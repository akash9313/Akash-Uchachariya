import numpy as np
import math

def forward_diff_table(y):
    n = len(y)
    table = np.zeros((n, n))
    table[:, 0] = y

    for j in range(1, n):
        for i in range(n - j):
            table[i, j] = table[i+1, j-1] - table[i, j-1]

    return table


def newton_forward(x, y, value):
    n = len(x)
    table = forward_diff_table(y)

    h = x[1] - x[0]
    u = (value - x[0]) / h

    result = table[0, 0]
    u_term = 1

    for i in range(1, n):
        u_term *= (u - (i - 1))
        result += (u_term * table[0, i]) / math.factorial(i)

    return result



def newton_backward(x, y, value):
    n = len(x)
    table = forward_diff_table(y)

    h = x[1] - x[0]
    u = (value - x[-1]) / h

    result = table[n-1, 0]
    u_term = 1

    for i in range(1, n):
        u_term *= (u + (i - 1))
        result += (u_term * table[n-i-1, i]) / math.factorial(i)

    return result


x = np.array([0, 1, 2, 3], dtype=float)
y = np.array([1, 3, 7, 13], dtype=float)
print("y(2.5) =", np.round(newton_backward(x, y, 2.5), 3))

print("y(0.5) =", np.round(newton_forward(x, y, 0.5), 3))