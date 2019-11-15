import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt("sin_friccion.dat")
plt.plot(data[:,0], data[:,1], label='sin friccion')

data = np.loadtxt("con_friccion.dat")
plt.plot(data[:,0], data[:,1], label='con friccion')

plt.xlabel("x")
plt.ylabel("y")
plt.legend()
plt.savefig("friccion.png")
