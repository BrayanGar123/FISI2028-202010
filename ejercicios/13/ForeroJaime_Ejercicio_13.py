import numpy as np
import matplotlib.pyplot as plt

def maxwellian(x, sigma):
    return (x**2) * np.exp(-0.5*(x/sigma)**2)

def integrate_maxwellian(sigma, N=20):
    y, wprime = np.polynomial.legendre.leggauss(N)
    a = 1.0 * sigma
    x = a * (1+y)/(1-y)
    w = wprime * 2.0 * a / (1-y**2)
    f = maxwellian(x, sigma)
    I = np.sum(w * f)
    return I

def derivative_maxwellian_integral(sigma, delta_sigma=0.1):
    b = integrate_maxwellian(sigma + delta_sigma)
    a = integrate_maxwellian(sigma - delta_sigma)
    print(a, b, (b-a)/(2.0*delta_sigma))
    return (b-a)/(2.0*delta_sigma)


# Primer punto. Grafica de la funcion
plt.figure(figsize=(12,4))

sigma = [1,2,10]
for i,s in enumerate(sigma):
    x = np.linspace(0,5*s, 200)
    plt.subplot(1,3,i+1)
    plt.plot(x, maxwellian(x,s), label="$\sigma={:d}$".format(s))
    plt.xlabel("x")
    plt.ylabel("f(x)")
    plt.legend()

plt.savefig("mb.png")


# calcula la integral y la derivada de la integral
n_points = 100
sigma_range = np.linspace(1,20, n_points)
integral = np.zeros(n_points)
derivative = np.zeros(n_points)
for i in range(n_points):
    integral[i] = integrate_maxwellian(sigma_range[i])
    derivative[i] = derivative_maxwellian_integral(sigma_range[i])

# Segundo punto
plt.figure()
plt.plot(np.log10(sigma_range), np.log10(integral))
plt.xlabel("$\sigma$")
plt.ylabel("$I(\sigma)$")
plt.savefig("mb_int.png")

# Tercer punto
plt.figure()
plt.plot(np.log10(sigma_range), np.log10(derivative))
plt.xlabel("$\sigma$")
plt.ylabel("$dI(\sigma)/d\sigma$")
plt.savefig("mb_int_prime.png")

