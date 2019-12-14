import numpy as np
import matplotlib.pyplot as plt


# Probabilidad de sigma dado x_value
def proba(x_value, sigma):
    if sigma >= 0:
        p = np.exp(-0.5*(x_value/sigma)**2) * (1/np.sqrt(2.0 * np.pi * sigma**2))
    else:
        p = 0.0
    return p

# likelihood usando bayes.
def likelihood(x_values, sigma):
    like = 1.0
    for x in x_values:
        like = like * proba(x, sigma)
    return like

# Metropolis Hastings para muestrear likelohood
def mcmc(x_values, n_points):
    sigma_values = np.ones(n_points)
    sigma_values[0] = np.random.random()*5
    for i in range(1,n_points):
        sigma_old = sigma_values[i-1]
        sigma_new = sigma_old + (np.random.random()-0.5)*0.5

        r = likelihood(x_values, sigma_new)/likelihood(x_values, sigma_old)
        r = min(1.0, r)
        alpha = np.random.random()
        if (alpha<r):
            sigma_values[i] = sigma_new
        else:
            sigma_values[i] = sigma_old
    return sigma_values



# carga los datos observacionales
x_data = np.loadtxt('valores.txt')

#primera grafica
n_points = 100
sigma_values = mcmc(x_data, 100000)
mean_sigma = np.mean(sigma_values)
std_sigma = np.std(sigma_values)
title = "Mean = {:.2f}, Std = {:.2f}".format(mean_sigma, std_sigma)
plt.figure()
plt.hist(sigma_values, density=True, bins=30)
plt.xlabel(r"$\sigma$")
plt.ylabel(r"$\rm{Likelihood}\ (\sigma|\rm{data})$")
plt.title(title)
plt.savefig("sigma.png")
