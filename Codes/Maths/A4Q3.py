import numpy as np
import math

n = int(input("Enter no. of rows: "))
m = int(input("Enter no. of columns: "))

A = np.array([list(map(float, input().split())) for _ in range(n)])

print(np.linalg.svd(A))
