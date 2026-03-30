import numpy as np

def increametal_search(f, a,b,step=0.01):
    x=a
    while x<=b:
        if f(x) == 0:
            return x
        if f(x)*f(x+step)<0:
            return (x+x+step)/2
        x =x + step
    return None

def Bisection_method(f,a,b, tol = 1e-6)
        