import numpy as np

n = int(input("Enter order of square matrix (n): "))

matrix = []
for i in range(n):
    row = list(map(float, input().split()))
    matrix.append(row)

A = np.array(matrix)
L = np.zeros((n,n), dtype = float)
U = np.zeros((n,n), dtype = float)

for i in range(n):
    for j in range(i, n):
        sum = 0
        for k in range(0, i):
            sum += L[i][k] * U[k][j]
        U[i][j] = A[i][j] - sum
    
    for j in range(i, n):
        if i == j:
            L[i][i] = 1  
        else:
            sum = 0
            for k in range(0, i):
                sum += L[j][k] * U[k][i]
            L[j][i] = (A[j][i] - sum) / U[i][i]
            
print("Upper triangular matrix : \n",U)
print("Lower triangular matrix: \n", L)