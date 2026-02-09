# Jacobi method
import numpy as np

n = int(input("Enter no. of rows: "))
m = int(input("Enter no. of colms: "))

A = [list(map(float, input().split())) for _ in range(n)]
A = np.array(A)

print("\nYour input matrix: ")
print(A)

X = np.array([0.0]*(m-1))

for it in range(1000000):
    for i in range(n):
        sum_ax = 0.0
        for j in range(m-1):
            if j != i:
                sum_ax += A[i][j] * X[j]
        X[i] = (A[i][m-1] - sum_ax) / A[i][i]
    print(f"\nIteration {it+1}:")
print(X)
    
    





