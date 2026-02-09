import numpy as np
import math

n = int(input("Enter order of matrix: "))

A = []
for i in range(n):
    A.append(list(map(float, input().split())))

A = np.array(A)

L = np.zeros((n,n))

for i in range(n):
    for j in range(i+1):
        s = 0
        for k in range(j):
            s += L[i][k] * L[j][k]

        if i == j:
            L[i][j] = math.sqrt(A[i][i] - s)
        else:
            L[i][j] = (A[i][j] - s) / L[j][j]

print("\nL =\n", L)