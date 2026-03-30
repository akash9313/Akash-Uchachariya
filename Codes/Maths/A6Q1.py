import numpy as np
import matplotlib.pyplot as plt
from scipy.interpolate import CubicSpline

def f(x):
    return 1 / (1 + x**2)

N = 11
x_sample = np.linspace(-5, 5, N)
y_sample = f(x_sample)

x_test = np.linspace(-5, 5, 500)
y_true = f(x_test)

degrees = [2, 3, 5, 8, 10]

mse_results = {}

plt.figure(figsize=(14, 10))

for i, deg in enumerate(degrees, 1):

    coeffs = np.polyfit(x_sample, y_sample, deg)
    poly = np.poly1d(coeffs)

    y_pred = poly(x_test)

    mse = np.mean((y_true - y_pred) ** 2)
    mse_results[f"Poly Degree {deg}"] = mse

    plt.subplot(3, 2, i)
    plt.plot(x_test, y_true, label="True Function", linewidth=2)
    plt.plot(x_test, y_pred, '--', label=f"Degree {deg} Polynomial")
    plt.scatter(x_sample, y_sample, color='red', zorder=3)
    plt.title(f"Polynomial Degree {deg}\nMSE = {mse:.6f}")
    plt.legend()
    plt.grid(True)

plt.tight_layout()
plt.show()

spline = CubicSpline(x_sample, y_sample)

y_spline = spline(x_test)

mse_spline = np.mean((y_true - y_spline) ** 2)
mse_results["Cubic Spline"] = mse_spline

plt.figure(figsize=(8, 5))
plt.plot(x_test, y_true, label="True Function", linewidth=2)
plt.plot(x_test, y_spline, '--', label="Cubic Spline")
plt.scatter(x_sample, y_sample, color='red')
plt.title(f"Cubic Spline Approximation\nMSE = {mse_spline:.6f}")
plt.legend()
plt.grid(True)
plt.show()

print("\nMean Squared Error Comparison:\n")
for method, mse in mse_results.items():
    print(f"{method}: {mse:.8f}")