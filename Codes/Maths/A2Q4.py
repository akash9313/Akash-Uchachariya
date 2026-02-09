A = [
    [4, -3, 6],
    [8, -3, 10],
    [-4, 12, -10]
]

b = [
    [1, 0],
    [0, 1],
    [0, 0]
]

n = 3

L = [[0]*n for _ in range(n)]
U = [[0]*n for _ in range(n)]

for i in range(n):
    L[i][i] = 1

for j in range(n):
    for i in range(j+1):
        U[i][j] = A[i][j] - sum(L[i][k]*U[k][j] for k in range(i))
    for i in range(j, n):
        L[i][j] = (A[i][j] - sum(L[i][k]*U[k][j] for k in range(j))) / U[j][j]

print("\nL matrix:")
for row in L:
    print(row)

print("\nU matrix:")
for row in U:
    print(row)

Y = [[0]*2 for _ in range(n)]

for col in range(2):
    for i in range(n):
        Y[i][col] = b[i][col] - sum(L[i][j]*Y[j][col] for j in range(i))

print("\nY matrix:")
for row in Y:
    print(row)

X = [[0]*2 for _ in range(n)]

for col in range(2):
    for i in range(n-1, -1, -1):
        X[i][col] = (Y[i][col] - sum(U[i][j]*X[j][col] for j in range(i+1, n))) / U[i][i]

print("\nSolution X:")
for row in X:
    print(row)