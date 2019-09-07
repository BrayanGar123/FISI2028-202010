import numpy as np
import matplotlib.pyplot as plt

#1. (50 puntos) Reproducir la Figura 3.3 del libro de Sivia para el
#caso donde las medidas son N=[60, 70, 70, 80, 90, 110, 90, 80, 60,
#55, 60]  para x=[-5,-4,-3,-2,-1,0,1,2,3,4,5] y x_0=0, FWHM=5.0 

def logproba_A_B(A, B, x, N):
    w = 5.0/2.355 # FWHM = 5.0
    D = (A * np.exp(-0.5*(x/w)**2) ) + B
    p = N * np.log(D) - D
    return p

def loglikelihood(x_data, N_data, n_points=1000):
    a = np.linspace(20, 60, n_points)
    b = np.linspace(50, 80, n_points)
    A, B = np.meshgrid(a, b)

    l = np.zeros ((n_points, n_points))
    for x, N in zip(x_data, N_data):
        l = l + logproba_A_B(A, B, x, N)
    return A, B, l

def plot_loglikelihood(x_data, N_data):
    A, B, L = loglikelihood(x_data, N_data)
    plt.contour(A, B, np.exp(L-L.max()))
    plt.xlabel("A")
    plt.ylabel("B")


plt.figure(figsize=(5,5))

x_data = np.array([-5.0, -4.0, -3.0, -2.0, -1.0, 0.0, 1.0, 2.0, 3.0, 4.0, 5.0])
N_data = np.array([60, 70, 70, 80, 90, 110, 90, 110, 90, 80, 60, 55, 60])

plot_loglikelihood(x_data, N_data)
plt.savefig("counts.png", bbox_inches="tight")

#2. (50 puntos) Implementar Metrópolis-Hastings para generar una lista
#con 10000 valores de alpha que al hacer el histograma de estos
#valores reproduzcan la Figura 2.9 (P(alpha|[x_i], beta)) del libro de
#Sivia. Asumiendo cuatro mediciones, x = [-5.2, -3.1, -2.8, -3.5] y
#beta=3.0. 


def proba_alpha(alpha, x, beta=3.0):
    p = beta/np.pi
    p = p / (beta**2 + (x-alpha)**2)
    return p

def likelihood(alpha, x_data):
    l = 1.0
    for x in x_data:
        l = l * proba_alpha(alpha, x)
    return l

def alpha_metropolis(x_data, N=100000, delta=1.0):
    lista = [np.random.random()]

    for i in range(1,N):
        propuesta  = lista[i-1] + (np.random.random()-0.5)*delta
        r = min(1, likelihood(propuesta, x_data)/likelihood(lista[i-1], x_data))
        gamma = np.random.random()
        if(gamma < r):
            lista.append(propuesta)
        else:
            lista.append(lista[i-1])
    return np.array(lista)


plt.figure()
plt.subplots_adjust(hspace=0.4)
plt.subplots_adjust(wspace=0.4)

datos = np.array([-5.2, -3.1, -2.8, -3.5])
alpha = alpha_metropolis(datos, N=10000, delta=2.0)

_ = plt.hist(alpha, bins=40, density=True)

plt.xlabel(r'$\alpha$')
plt.ylabel(r'P($\alpha$|x)')
label = 'x = {}'.format(datos)
plt.title(label)
plt.savefig("faro_metropolis.png", bbox_inches="tight")


