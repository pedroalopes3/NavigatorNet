import torch
import torch.nn as nn
import torch.nn.functional as F
import torchvision.models as models


class NetVLADLayer(nn.Module):
    """Standard NetVLAD layer implementation for spatial pooling."""

    def __init__(self, num_clusters=64, dim=512, normalize_input=True):
        super(NetVLADLayer, self).__init__()
        self.num_clusters = num_clusters
        self.dim = dim
        self.normalize_input = normalize_input

        # Linear projection and cluster centers
        self.conv = nn.Conv2d(dim, num_clusters, kernel_size=(1, 1), bias=True)
        self.centroids = nn.Parameter(torch.rand(num_clusters, dim))

    def forward(self, x):
        N, C = x.shape[:2]

        if self.normalize_input:
            x = F.normalize(x, p=2, dim=1)  # L2 normalize across channels

        # Soft-assignment of features to clusters
        soft_assign = self.conv(x).view(N, self.num_clusters, -1)
        soft_assign = F.softmax(soft_assign, dim=1)

        x_flatten = x.view(N, C, -1)

        # Initialize output VLAD tensor
        vlad = torch.zeros(
            [N, self.num_clusters, C], dtype=x.dtype, layout=x.layout, device=x.device
        )

        # Calculate residuals for each cluster
        for C_idx in range(self.num_clusters):
            residual = x_flatten.unsqueeze(0).permute(1, 0, 2, 3) - self.centroids[
                C_idx : C_idx + 1, :
            ].view(1, 1, -1, 1)
            residual *= soft_assign[:, C_idx : C_idx + 1, :].unsqueeze(2)
            vlad[:, C_idx : C_idx + 1, :] = residual.sum(dim=-1)

        # Intra-normalization
        vlad = F.normalize(vlad, p=2, dim=2)
        # Flatten
        vlad = vlad.view(x.size(0), -1)
        # L2 Normalization
        vlad = F.normalize(vlad, p=2, dim=1)

        return vlad


class VGG16NetVLAD(nn.Module):
    """Combines a VGG-16 feature extractor with the NetVLAD pooling layer."""

    def __init__(self):
        super(VGG16NetVLAD, self).__init__()
        # Use VGG16 up to the last conv layer (conv5_3) before max pooling
        vgg = models.vgg16(weights=None)
        layers = list(vgg.features.children())[:-2]
        self.encoder = nn.Sequential(*layers)

        # Initialize NetVLAD layer (VGG16 outputs 512 dimensions)
        self.pool = NetVLADLayer(num_clusters=64, dim=512)

    def forward(self, x):
        image_encoding = self.encoder(x)
        vlad_encoding = self.pool(image_encoding)
        return vlad_encoding


def get_netvlad_model():
    """Entry point used by netvlad_extractor.py to instantiate the model."""
    return VGG16NetVLAD()
