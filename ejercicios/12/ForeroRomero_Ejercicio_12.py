import numpy as np
import matplotlib.pyplot as plt

#1.
def f1(x):
    return np.cos(x) * np.exp(-x**2-x)

def gauss_quad(f, N=20):
    y, wprime = np.polynomial.legendre.leggauss(N)
    x = y/(1-y**2)
    w = wprime * (1+y**2)/(1-y**2)
    return np.sum(w * f(x))

print("Primera integral")
print(gauss_quad(f1))
print()

#2.
def f(x):
    return np.cos(x)

def f2(x):
    return np.exp(-x**2 -x)    

def metropolis_hastings_1D(f, N=100000, delta=1.0):
    x = np.zeros(N)
    for i in range(1,N):
        x[i] = x[i-1] + (np.random.random()-0.5)*delta

        future = f(x[i])
        present = f(x[i-1])

        r = np.minimum(1.0, future/present)
        g = np.random.random()

        if g < r:
            x[i] = x[i]
        else:
            x[i] = x[i-1]
    return x

def mc_integral(f, g):
    x = metropolis_hastings_1D(g)
    average = np.average(f(x))
    norm = gauss_quad(g, N=100)
    return average * norm

print("Segunda Integral")
print(mc_integral(f, f2))
