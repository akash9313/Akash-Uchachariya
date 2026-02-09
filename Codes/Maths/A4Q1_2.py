# SVD Method
import numpy as np 
import math

n = int(input("Enter no. of rows: "))
m = int(input("Enter no. of colms: "))

A = [list(map(float, input().split())) for _ in range(n)]
A = np.array(A)
 
A_Trans = A.T 
B = A_Trans @ A

[eig_val, eig_vec] = np.linalg.eig(B)
V = eig_vec

sigma = np.zeros((n,m),dtype = float)
for i in range(n):
    sigma[i][i] = math.sqrt(eig_val)
    
[eig_val1, eig_vec2] = np.linalg.eig(sigma)
V2 = eig_vec2

detsigma = np.linalg.det(sigma)
if detsigma != 0:
    invsigma = np.linalg.inv(sigma)
    
U1 = A @ V2
U = U1 @ invsigma

print(U)
    
 