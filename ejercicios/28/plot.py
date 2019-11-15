import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt("solve.dat")

plt.plot(data[:,0], data[:,1])

plt.savefig("solve.png")
