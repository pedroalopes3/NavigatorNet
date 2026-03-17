1. Geometric Context

The parameters provided correspond to a Rational Polynomial Model (8-coefficient), typically used for high-distortion wide-angle or fisheye lenses.
Orientation (Extrinsics)

The camera is mounted with the following physical offsets relative to the vehicle/platform horizon:

    Pitch: 27.0∘ (Downward tilt toward the ground)

    Roll: −4.0∘ (Slight counter-clockwise rotation)

2. Intrinsic Parameters

The intrinsic matrix K represents the optical center and focal length in pixels.
Parameter	Symbol	Value
Focal Length X	fx​	896.602173
Focal Length Y	fy​	881.922974
Principal Point X	cx​	1003.954285
Principal Point Y	cy​	451.323334

Camera Matrix (K):
K=​896.60217300​0881.9229740​1003.954285451.3233341​​
3. Distortion Coefficients

The lens distortion is modeled using 6 radial coefficients (k) and 2 tangential coefficients (p).

Vector Format: [k1​,k2​,p1​,p2​,k3​,k4​,k5​,k6​]
Coefficient	Value	Type
k1​	1.771178e+00	Radial (Numerator)
k2​	3.254712e+00	Radial (Numerator)
p1​	4.790912e-03	Tangential
p2​	-3.419381e-03	Tangential
k3​	2.092365e-01	Radial (Numerator)
k4​	2.054499e+00	Radial (Denominator)
k5​	` 3.929369e+00$	Radial (Denominator)
4. Usage in OpenCV (Python)

To undistort a frame using these parameters, use the following implementation:
Python

import numpy as np
import cv2

# Define Matrix
K = np.array([
    [896.602173, 0, 1003.954285],
    [0, 881.922974, 451.323334],
    [0, 0, 1]
])

# Define Distortion Coefficients
# Order: k1, k2, p1, p2, k3, k4, k5, k6
D = np.array([
    1.771178, 3.254712, 0.004791, -0.003419, 
    0.209236, 2.054499, 3.929369, 1.042681
])

def process_image(img):
    h, w = img.shape[:2]
    # Calculate optimal matrix to minimize black borders
    new_K, roi = cv2.getOptimalNewCameraMatrix(K, D, (w, h), 1, (w, h))
    # Apply undistortion
    dst = cv2.undistort(img, K, D, None, new_K)
    return dst
