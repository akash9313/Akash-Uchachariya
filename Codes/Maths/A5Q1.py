def divided_diff(x, y):
    n = len(x)
    coef = y.copy()

    for i in range(1, n):
        for j in range(n-1, i-1, -1):
            coef[j] = (coef[j] - coef[j-1]) / (x[j] - x[j-i])
          
    return coef


def newtons_interpolation(x, coef, value):
    n = len(coef)
    result = coef[n-1]

    for i in range(n-2, -1, -1):
        result = result * (value - x[i]) + coef[i]

    return result


x = [1, 2, 3]
y = [2, 3, 5]
value = 1.5

coef = divided_diff(x, y)
result = newtons_interpolation(x, coef, value)

print("x =", value, "result:", result)
