import numpy as np
import matplotlib.pyplot as plt
from scipy.interpolate import CubicSpline

x = np.array([0, 1, 2])
y = np.array([1, 3, 2])

spline = CubicSpline(x, y, bc_type='natural')

x_dense = np.linspace(0, 2, 400)
y_dense = spline(x_dense)

plt.figure(figsize=(8, 5))

plt.plot(x_dense, y_dense, label="Natural Cubic Spline", linewidth=2)
plt.scatter(x, y, color='red', zorder=3, label="Data Points")

for xi, yi in zip(x, y):
    plt.text(xi, yi + 0.1, f"({xi}, {yi})", ha='center')

plt.title("Natural Cubic Spline Interpolation")
plt.xlabel("x")
plt.ylabel("y")
plt.legend()
plt.grid(True)
plt.show()

x_val = 1.5
y_val = spline(x_val)

print(f"Interpolated value at x = {x_val} is {y_val:.6f}")