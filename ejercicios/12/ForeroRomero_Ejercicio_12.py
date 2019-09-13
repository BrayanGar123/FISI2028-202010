import numpy as np
import matplotlib.pyplot as plt

#1.
def f(x):
    return np.cos(x) * np.exp(-x**2 -x)

def i(N=20):
    y, wprime = np.polynomial.legendre.leggauss(N)
    x = y/(1-y**2)
    w = wprime * (1+y**2)/(1-y**2)
    return np.sum(w * f(x))

print("Primera integral")
print(i())
print()
