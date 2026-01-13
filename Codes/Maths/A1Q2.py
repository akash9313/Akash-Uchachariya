import numpy as np

A = np.array([[2,3+1j],[3-1j,4]])
B = np.array([[1,7,3],[7,4,-5],[3,-5,6]])

A_con = A.conj()
A_Trans_s = A.T
A_Trans = A_con.T

B_con = B.conj()
B_Trans_s = B.T
B_Trans = B_con.T

if np.array_equal(A_Trans_s,A):
    print("Matrix A is Symmetric")
else:
    print("Matrix A is not Symmetric")
    
if np.array_equal(A_Trans, A):
    print("Matrix A is Hermitian")
else:
    print("Matrix A is not Hermitian")
    
    
if np.array_equal(B_Trans_s,B):
    print("Matrix A is Symmetric")
else:
    print("Matrix A is not Symmetric")
    
if np.array_equal(B_Trans, B):
    print("Matrix A is Hermitian")
else:
    print("Matrix A is not Hermitian")
    


