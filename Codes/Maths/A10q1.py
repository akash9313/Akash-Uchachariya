import numpy as np
import math
from scipy.integrate import quad

def trapezoidal_rule(f, a, b, n):
    h = (b - a) / n
    x = np.linspace(a, b, n + 1)
    y = f(x)
    return (h / 2) * (y[0] + 2 * np.sum(y[1:n]) + y[n])

def simpson_one_third(f, a, b, n):
    if n % 2 != 0:
        raise ValueError("Simpson's 1/3 rule requires n to be even.")
    h = (b - a) / n
    x = np.linspace(a, b, n + 1)
    y = f(x)
    return (h / 3) * (y[0] + y[n] + 4 * np.sum(y[1:n:2]) + 2 * np.sum(y[2:n-1:2]))

def simpson_three_eighth(f, a, b, n):
    if n % 3 != 0:
        raise ValueError("Simpson's 3/8 rule requires n to be a multiple of 3.")
    h = (b - a) / n
    x = np.linspace(a, b, n + 1)
    y = f(x)
    
    total = y[0] + y[n]
    for i in range(1, n):
        if i % 3 == 0:
            total += 2 * y[i]
        else:
            total += 3 * y[i]
    return (3 * h / 8) * total

def exact_q1a():
    x = 3
    return 0.5 * (x * math.sqrt(1 + x**2) + math.log(x + math.sqrt(1 + x**2)))

def exact_q1b():
    return math.log(7)

def print_results(title, exact, trap, simp13, simp38):
    print("\n" + "="*70)
    print(title)
    print("="*70)
    print(f"Exact Value         = {exact:.10f}")
    print(f"Trapezoidal Rule    = {trap:.10f}   Error = {abs(exact-trap):.10f}")
    print(f"Simpson's 1/3 Rule  = {simp13:.10f}   Error = {abs(exact-simp13):.10f}")
    print(f"Simpson's 3/8 Rule  = {simp38:.10f}   Error = {abs(exact-simp38):.10f}")

print("\nQ 1")

n = 6

f1a = lambda x: np.sqrt(1 + x**2)
a1, b1 = 0, 3

exact1a = exact_q1a()
trap1a = trapezoidal_rule(f1a, a1, b1, n)
simp13_1a = simpson_one_third(f1a, a1, b1, n)
simp38_1a = simpson_three_eighth(f1a, a1, b1, n)

print_results("Q1(a): Integral of sqrt(1+x^2) from 0 to 3", exact1a, trap1a, simp13_1a, simp38_1a)

f1b = lambda x: 1 / (1 + x)
a2, b2 = 0, 6

exact1b = exact_q1b()
trap1b = trapezoidal_rule(f1b, a2, b2, n)
simp13_1b = simpson_one_third(f1b, a2, b2, n)
simp38_1b = simpson_three_eighth(f1b, a2, b2, n)

print_results("Q1(b): Integral of 1/(1+x) from 0 to 6", exact1b, trap1b, simp13_1b, simp38_1b)

print("\n\nAccuracy test for Q1 by increasing n")
n_values = [6, 12, 18, 24]

for n_test in n_values:
    print(f"\nn = {n_test}")
    
    t = trapezoidal_rule(f1a, a1, b1, n_test)
    s13 = simpson_one_third(f1a, a1, b1, n_test)
    s38 = simpson_three_eighth(f1a, a1, b1, n_test)
    print(f"Q1(a) Errors -> Trap: {abs(exact1a-t):.10f}, Simpson 1/3: {abs(exact1a-s13):.10f}, Simpson 3/8: {abs(exact1a-s38):.10f}")
    
    t = trapezoidal_rule(f1b, a2, b2, n_test)
    s13 = simpson_one_third(f1b, a2, b2, n_test)
    s38 = simpson_three_eighth(f1b, a2, b2, n_test)
    print(f"Q1(b) Errors -> Trap: {abs(exact1b-t):.10f}, Simpson 1/3: {abs(exact1b-s13):.10f}, Simpson 3/8: {abs(exact1b-s38):.10f}")


print("\nQ 2")

f2a = lambda x: np.exp(-x**2) * np.cos(x)
a3, b3 = 0, 2
exact2a, _ = quad(lambda x: math.exp(-x**2) * math.cos(x), a3, b3)
n = 12

trap2a = trapezoidal_rule(f2a, a3, b3, n)
simp13_2a = simpson_one_third(f2a, a3, b3, n)
simp38_2a = simpson_three_eighth(f2a, a3, b3, n)

print_results("Q2(a): Integral of e^(-x^2) cos(x) from 0 to 2", exact2a, trap2a, simp13_2a, simp38_2a)

f2b = lambda x: np.log(x) / (1 + x**2)
a4, b4 = 1, 4

exact2b, _ = quad(lambda x: math.log(x) / (1 + x**2), a4, b4)

trap2b = trapezoidal_rule(f2b, a4, b4, n)
simp13_2b = simpson_one_third(f2b, a4, b4, n)
simp38_2b = simpson_three_eighth(f2b, a4, b4, n)

print_results("Q2(b): Integral of ln(x)/(1+x^2) from 1 to 4", exact2b, trap2b, simp13_2b, simp38_2b)

print("\n\nAccuracy test for Q2 by increasing n")
n_values = [6, 12, 18, 24, 30]

for n_test in n_values:
    print(f"\nn = {n_test}")
    
    # Q2(a)
    t = trapezoidal_rule(f2a, a3, b3, n_test)
    s13 = simpson_one_third(f2a, a3, b3, n_test)
    s38 = simpson_three_eighth(f2a, a3, b3, n_test)
    print(f"Q2(a) Errors -> Trap: {abs(exact2a-t):.10f}, Simpson 1/3: {abs(exact2a-s13):.10f}, Simpson 3/8: {abs(exact2a-s38):.10f}")
    
    # Q2(b)
    t = trapezoidal_rule(f2b, a4, b4, n_test)
    s13 = simpson_one_third(f2b, a4, b4, n_test)
    s38 = simpson_three_eighth(f2b, a4, b4, n_test)
    print(f"Q2(b) Errors -> Trap: {abs(exact2b-t):.10f}, Simpson 1/3: {abs(exact2b-s13):.10f}, Simpson 3/8: {abs(exact2b-s38):.10f}")