import cv2
import numpy as np
from mcap.reader import make_reader
from mcap_ros2.decoder import DecoderFactory


class CameraCalibrator:
    def __init__(self, input_file, topic_name, K_matrix, D_coeffs, alpha=0.2):
        self.input_file = input_file
        self.topic_name = topic_name
        self.K_original = np.array(K_matrix)
        self.D = np.array(D_coeffs)
        self.alpha = alpha

        # Estado interno da calibração
        self.mapx = None
        self.mapy = None
        self.f_final = None

        # Estado do leitor de ficheiros
        self._file_handle = None
        self._reader_iterator = None

    def _initialize_calibration(self, h, w):
        """Calcula os mapas de retificação na primeira vez que recebe uma imagem."""
        f_mean = (self.K_original[0, 0] + self.K_original[1, 1]) / 2

        K_square = self.K_original.copy()
        K_square[0, 0] = K_square[1, 1] = f_mean

        new_K, roi = cv2.getOptimalNewCameraMatrix(K_square, self.D, (w, h), self.alpha, (w, h))

        self.f_final = (new_K[0, 0] + new_K[1, 1]) / 2
        new_K[0, 0] = new_K[1, 1] = self.f_final

        self.mapx, self.mapy = cv2.initUndistortRectifyMap(
            K_square, self.D, None, new_K, (w, h), cv2.CV_32FC1
        )
        print(f"[Calibrator] Inicializado. Resolução: {w}x{h} | Focal Final: {self.f_final:.2f} px")

    def open(self):
        """Abre o ficheiro MCAP e prepara o iterador de mensagens."""
        self._file_handle = open(self.input_file, "rb")
        reader = make_reader(self._file_handle, decoder_factories=[DecoderFactory()])
        # Cria um iterador que vai "cuspir" uma mensagem de cada vez
        self._reader_iterator = reader.iter_decoded_messages(topics=[self.topic_name])

    def close(self):
        """Fecha o ficheiro MCAP de forma segura."""
        if self._file_handle and not self._file_handle.closed:
            self._file_handle.close()
            self._reader_iterator = None
            print("[Calibrator] Ficheiro MCAP fechado.")

    def get_next_frame(self):
        """
        Lê a próxima mensagem do bag, descodifica, calibra e devolve.
        Retorna: (timestamp_ns, imagem_raw, imagem_calibrada) ou (None, None, None) se chegar ao fim.
        """
        if self._reader_iterator is None:
            print("Erro: Precisas de chamar open() antes de get_next_frame().")
            return None, None, None

        while True:
            try:
                # Pede a próxima mensagem ao iterador
                schema, channel, message, ros_msg = next(self._reader_iterator)

                # Descodificar imagem
                np_arr = np.frombuffer(ros_msg.data, np.uint8)
                raw_img = cv2.imdecode(np_arr, cv2.IMREAD_COLOR)

                if raw_img is None:
                    continue  # Tenta a próxima mensagem se esta falhar

                # Inicializar matrizes de calibração no primeiro frame válido
                if self.mapx is None:
                    h, w = raw_img.shape[:2]
                    self._initialize_calibration(h, w)

                # Aplicar a retificação
                calibrated_img = cv2.remap(raw_img, self.mapx, self.mapy, cv2.INTER_CUBIC)

                # Devolve o tempo da mensagem, a imagem RAW, e a calibrada
                return message.log_time, raw_img, calibrated_img

            except StopIteration:
                # Chegámos ao fim do ficheiro
                return None, None, None
