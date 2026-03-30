import numpy as np

def polynomial_fit(x, y, degree):
    coeffs = np.polyfit(x, y, degree)
    poly = np.poly1d(coeffs)
    y_pred = poly(x)
    return y_pred, coeffs

def exponential_fit(x, y):
    logy = np.log(y)
    b, loga = np.polyfit(x, logy, 1)
    a = np.exp(loga)
    y_pred = a * np.exp(b * x)
    return y_pred, a, b

def compute_errors(y, y_pred):
    sse = np.sum((y - y_pred)**2)
    rmse = np.sqrt(sse / len(y))
    return sse, rmse

def solve_question(x, y, title):
    print("\n", "="*50)
    print(title)
    print("="*50)

    best_rmse = float('inf')
    best_model = ""

    for d in range(1,5):
        y_pred, coeffs = polynomial_fit(x, y, d)
        sse, rmse = compute_errors(y, y_pred)

        print(f"\nPolynomial Degree {d}")
        print("Coefficients:", coeffs)
        print("SSE:", sse)
        print("RMSE:", rmse)

        if rmse < best_rmse:
            best_rmse = rmse
            best_model = f"Polynomial Degree {d}"

    y_pred, a, b = exponential_fit(x, y)
    sse, rmse = compute_errors(y, y_pred)

    print("\nExponential Model y = a*e^(bx)")
    print("a =", a)
    print("b =", b)
    print("SSE:", sse)
    print("RMSE:", rmse)

    if rmse < best_rmse:
        best_model = "Exponential Model"

    print("\nBest Model:", best_model)


x1 = np.array([0,1,2,3,4,5])
y1 = np.array([5,8,13,21,34,55])

solve_question(x1, y1, "q1")

x2 = np.array([0,1,2,3,4,5])
y2 = np.array([2,5,10,17,26,37])

solve_question(x2, y2, "q2")

x3 = np.array([0,1,2,3,4,5])
y3 = np.array([2,3.3,5.4,8.9,14.8,24.4])

solve_question(x3, y3, "q3")