import numpy as np
import matplotlib.pyplot as plt

# 1. (10 puntos) Reproducir la Figura 2.1 del capítulo 2 del libro de Sivia, 
# pero usando los siguientes cuatro casos 
# {N_cara=1, N_sello=0},{ N_cara=4, N_sello=6}, 
# {N_cara=35, N_sello=65}, {N_cara=320, N_sello=680}.

def proba_h(h, cara, n_points=100):
    if cara==0:
        return h
    if cara==1:
        return 1-h
def likelihood(n_cara, n_sello, n_points=100):
    h = np.linspace(0,1,n_points)
    l = np.ones(n_points)
    for i in range(n_cara):
        l = l * proba_h(h, 0, n_points=n_points)
    for i in range(n_sello):
        l = l * proba_h(h, 1, n_points=n_points)
    return h, l

def plot_likelihood(n_cara, n_sello):
    h, l = likelihood(n_cara, n_sello)
    plt.plot(h, l/l.max())
    plt.xlabel("H")
    plt.ylabel("P(H|datos)")
    label = "$N_c = {}, N_s = {}$".format(n_cara, n_sello)
    plt.title(label)
    

plt.figure(figsize=(5,5))
plt.subplots_adjust(hspace=0.4)
plt.subplots_adjust(wspace=0.4)

datos = [[1, 0], [4, 6], [35, 65], [320, 680]]
for i in range(len(datos)):
    plt.subplot(2,2,i+1)
    print(datos[i][0], datos[i][1])
    plot_likelihood(datos[i][0], datos[i][1])

plt.savefig("monedas.png", bbox_inches="tight")

    

#2. (20 puntos) Implementar el código necesario para reproducir la Figura 2.9 (P(alpha|[x_i], beta)) del mismo libro, pero asumiendo solamente cuatro mediciones, x = [-5.2, -3.1, -2.8, -3.5] y ademas que beta=3.0.

def proba_alpha(alpha, x, beta=3.0, n_points=100):
    p = beta/np.pi
    p = p / (beta**2 + (x-alpha)**2)
    return p

def likelihood(x_data, n_points=100):
    alpha = np.linspace(-10,10,n_points)
    l = np.ones(n_points)
    for x in x_data:
        l = l * proba_alpha(alpha, x, n_points=n_points)
    return alpha, l

def plot_likelihood(x_data):
    alpha,l = likelihood(x_data)
    plt.plot(alpha, l/l.max())
    plt.xlabel(r'$\alpha$')
    plt.ylabel(r'P($\alpha$|x)')
    label = 'x = {}'.format(x_data)
    plt.title(label)


plt.figure(figsize=(5,5))
plt.subplots_adjust(hspace=0.4)
plt.subplots_adjust(wspace=0.4)

datos = np.array([-5.2, -3.1, -2.8, -3.5])
for i in range(len(datos)):
    plt.subplot(2,2,i+1)
    print(datos[:i+1])
    plot_likelihood(datos[:i+1])

plt.savefig("faro.png", bbox_inches="tight")
