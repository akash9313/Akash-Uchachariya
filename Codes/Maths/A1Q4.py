import numpy as np

A = np.array([[1,1,1,6],[2,3,1,11],[1,2,3,14]])
n = 3
for i in range(n):
    for j in range(i+1,n):
        factor = A[j][i]/A[i][i]
        A[j] = A[j] - A[i] * factor
        
print(A)

V = np.array([0]*n)

for i in range(n-1, -1,-1):
    sum = 0
    
    for j in range(n-1, i , -1):
        sum += V[j] * A[i][j]
    V[i] = (A[i][n] - sum)/A[i][i]
        
print(V)

