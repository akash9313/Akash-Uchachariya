import numpy as np

A = np.array([[2,1],[4,5]])

eig_val = np.linalg.eig(A)
print(eig_val)

B = np.array([[2,1,0],[1,2,1],[0,1,2]])

eig_val2 = np.linalg.eig(B)
print(eig_val2)
