import numpy as np

n = int(input("Enter order of square matrix (n): "))

matrix = []
for i in range(n):
    row = list(map(float, input().split()))
    matrix.append(row)

A = np.array(matrix)

detA = np.linalg.det(A)
print("\nDeterminant of matrix:", detA)

if detA != 0:
    invA = np.linalg.inv(A)
    print("\nInverse of matrix:")
    print(invA)
else:
    print("\nInverse does not exist")
