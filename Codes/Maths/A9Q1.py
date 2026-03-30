def f(x):
    return x**3- x - 2

def Regula_falsi(a,b,f):
    return (a*f(b) - b*f(a))/(f(b) - f(a))

a = 1.0
b = 2.0
x = 1.0

while abs(f(x)) > 1e-6:
    x = Regula_falsi(a,b,f)
    if f(x)*f(b) < 0:
        a = x
    else:
        b = x
        
print(x)   