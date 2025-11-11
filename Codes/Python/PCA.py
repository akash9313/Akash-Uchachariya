import numpy as np
import matplotlib.pyplot as plt
from PIL import Image
import os

# -------------------- 1. Load Dataset --------------------
def load_images_from_folder(folder, size=(100, 100)):
    images = []
    for filename in os.listdir(folder):
        img = Image.open(os.path.join(folder, filename)).convert('L')  # grayscale
        img = img.resize(size)
        img_array = np.asarray(img, dtype=np.float64).flatten()
        images.append(img_array)
    return np.array(images).T  # shape = (pixels, n_images)

X = load_images_from_folder("faces/")   # (pixels, n_images)
m, n = X.shape
print("Data matrix shape:", X.shape)

# -------------------- 2. Compute Mean Manually --------------------
mean_face = np.zeros((m,1))
for i in range(n):
    mean_face += X[:,i].reshape(-1,1)
mean_face /= n

# Mean center
X_centered = X - mean_face

# -------------------- 3. Covariance Matrix (manual) --------------------
# C_x = (1/(n-1)) * (X_centered.T @ X_centered)
C_x = (X_centered.T @ X_centered) / (n-1)

# -------------------- 4. Eigen Decomposition --------------------
eigenvalues, eigenvectors = np.linalg.eigh(C_x)

# Map eigenvectors to original space
eigenfaces = X_centered @ eigenvectors

# Normalize eigenfaces
for i in range(eigenfaces.shape[1]):
    eigenfaces[:,i] /= np.linalg.norm(eigenfaces[:,i])

# -------------------- 5. Sort Eigenfaces --------------------
idx = np.argsort(eigenvalues)[::-1]
eigenvalues = eigenvalues[idx]
eigenfaces = eigenfaces[:, idx]

# -------------------- 6. Reconstruction --------------------
def reconstruct(X_centered, mean_face, eigenfaces, k):
    W = eigenfaces[:, :k]                  # top k eigenfaces
    X_projected = W.T @ X_centered          # projection
    X_reconstructed = (W @ X_projected) + mean_face
    return X_reconstructed

# -------------------- 7. Show Original vs Reconstructed --------------------
def show_comparison(X, X_reconstructed, h=100, w=100, idx=0, k=10):
    plt.figure(figsize=(6,3))
    plt.subplot(1,2,1)
    plt.imshow(X[:,idx].reshape(h,w), cmap='gray')
    plt.title("Original")
    plt.axis("off")

    plt.subplot(1,2,2)
    plt.imshow(X_reconstructed[:,idx].reshape(h,w), cmap='gray')
    plt.title(f"Reconstructed (k={k})")
    plt.axis("off")
    plt.show()

# Try different k
k_values = [10, 20, 50]
errors = []
for k in k_values:
    X_reconstructed = reconstruct(X_centered, mean_face, eigenfaces, k)
    error = np.linalg.norm(X - X_reconstructed, 'fro')
    errors.append(error)
    show_comparison(X, X_reconstructed, idx=0, k=k)

# -------------------- 8. Plot Reconstruction Error --------------------
plt.plot(k_values, errors, marker='o')
plt.xlabel("Number of Components (k)")
plt.ylabel("Reconstruction Error")
plt.title("Error vs Components")
plt.show()

# -------------------- 9. Final Comments --------------------
"""
Eigenfaces successfully capture the main facial variations.
With small k, reconstruction loses detail but identity is preserved.
As k increases, error decreases and images get clearer.
PCA compresses data while retaining essential information.
"""