import numpy as np

# Example matrix
A = np.array([[39.583,60.417,41.25],[60.417,122.917,82.083],[41.25,82.083,54.917]])
              

# Calculate eigenvalues and eigenvectors
eigenvalues, eigenvectors = np.linalg.eig(A)

print("Matrix A:")
print(A)

print("\nEigenvalues:")
print(eigenvalues)

print("\nEigenvectors (each column corresponds to an eigenvalue):")
print(eigenvectors)