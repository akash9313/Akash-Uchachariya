import numpy as np

def incremental_search(f, a, b, step=0.01):
    x = a
    while x <= b:
        if f(x) == 0:
            return x
        if f(x) * f(x + step) < 0:
            return (x + x + step) / 2
        x = x + step
    return None

def bisection_method(f, a, b, tol=1e-6):

    if f(a) * f(b) >= 0:
        print("Bisection method cannot be applied.")
        return None

    while (b - a) >= tol:

        c = (a + b) / 2
        if f(c) == 0:
            return c

        if f(a) * f(c) < 0:
            b = c
        else:
            a = c

    return (a + b) / 2

def newton_raphson(f, df, x0, tol=1e-6, max_iter=100):

    x = x0

    for i in range(max_iter):

        if df(x) == 0:
            print("Derivative is zero.")
            return None

        x_new = x - f(x) / df(x)

        if abs(x_new - x) < tol:
            return x_new

        x = x_new

    return x

print("\nQ1:")


def f1(x):
    return x**2 - 5*x + 6

def df1(x):
    return 2*x - 5

print("\nEquation: x^2 -5x +6")

root1_inc = incremental_search(f1, 1.5, 2.5)
root2_inc = incremental_search(f1, 2.5, 3.5)

root1_bis = bisection_method(f1, 1.5, 2.5)
root2_bis = bisection_method(f1, 2.5, 3.5)

root1_new = newton_raphson(f1, df1, 1.8)
root2_new = newton_raphson(f1, df1, 3.2)

print("Incremental Search Roots:", root1_inc, root2_inc)
print("Bisection Roots:", root1_bis, root2_bis)
print("Newton Raphson Roots:", root1_new, root2_new)

def f2(x):
    return x**2 - 5

def df2(x):
    return 2*x

print("\nEquation: x^2 -5")

root_inc = incremental_search(f2, 2, 3)
root_bis = bisection_method(f2, 2, 3)
root_new = newton_raphson(f2, df2, 2)

print("Incremental Search Root:", root_inc)
print("Bisection Root:", root_bis)
print("Newton Raphson Root:", root_new)

print("\nQ2:")
def f3(x):
    return np.exp(-x) - x**2 + 0.2

def df3(x):
    return -np.exp(-x) - 2*x

print("\nEquation: e^-x - x^2 + 0.2")

root_inc = incremental_search(f3, 0, 1)
root_bis = bisection_method(f3, 0, 1)
root_new = newton_raphson(f3, df3, 0.5)

print("Incremental Search Root:", root_inc)
print("Bisection Root:", root_bis)
print("Newton Raphson Root:", root_new)

def f4(x):
    return np.sin(x) - x/2

def df4(x):
    return np.cos(x) - 0.5

print("\nEquation: sin(x) - x/2")

root_inc = incremental_search(f4, 1.5, 2.5)
root_bis = bisection_method(f4, 1.5, 2.5)
root_new = newton_raphson(f4, df4, 2)

print("Incremental Search Root:", root_inc)
print("Bisection Root:", root_bis)
print("Newton Raphson Root:", root_new)

def f5(x):
    return x**5 - x - 1

def df5(x):
    return 5*x**4 - 1

print("\nEquation: x^5 - x - 1")

root_inc = incremental_search(f5, 1, 2)
root_bis = bisection_method(f5, 1, 2)
root_new = newton_raphson(f5, df5, 1.5)

print("Incremental Search Root:", root_inc)
print("Bisection Root:", root_bis)
print("Newton Raphson Root:", root_new)