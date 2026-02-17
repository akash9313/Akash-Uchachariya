import numpy as np
import matplotlib.pyplot as plt
from scipy.interpolate import CubicSpline
from sklearn.metrics import mean_squared_error

def f(x):
    return 1 / (1 + x**2)

N = 11
x_sample = np.linspace(-5, 5, N)
y_sample = f(x_sample)

x_dense = np.linspace(-5, 5, 500)
y_true = f(x_dense)

degrees = [2, 3, 5, 8, 10]

print("Polynomial Approximation Errors (MSE):")
plt.figure(figsize=(10, 6))
plt.plot(x_dense, y_true, linewidth=2, label="True Function")

for d in degrees:
    coeffs = np.polyfit(x_sample, y_sample, d)
    poly = np.poly1d(coeffs)
    y_poly = poly(x_dense)
    mse = mean_squared_error(y_true, y_poly)
    print(f"Degree {d}: MSE = {mse:.6f}")
    plt.plot(x_dense, y_poly, label=f"Degree {d}")

spline = CubicSpline(x_sample, y_sample)
y_spline = spline(x_dense)

mse_spline = mean_squared_error(y_true, y_spline)
print(f"\nCubic Spline MSE: {mse_spline:.6f}")

plt.plot(x_dense, y_spline, '--', label="Cubic Spline")
plt.scatter(x_sample, y_sample, color='black', zorder=5, label="Sample Points")

plt.legend()
plt.title("Polynomial vs Cubic Spline Approximation")
plt.xlabel("x")
plt.ylabel("f(x)")
plt.grid()
plt.show()