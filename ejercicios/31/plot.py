import numpy as np
import matplotlib.pyplot as plt


data = np.loadtxt("datos.dat")
    
plt.figure(figsize=(17,4))
    
plt.subplot(1,3,1)
plt.plot(data[:,0], data[:,1])
plt.scatter(data[:,0], data[:,1])
plt.xlabel("N_x")
plt.ylabel("N iteraciones")

plt.subplot(1,3,2)
plt.plot(data[:,0], data[:,2]*1E2)
plt.scatter(data[:,0], data[:,2]*1E2)
plt.xlabel("N_x")
plt.ylabel(r"Error Centro $\times 10^2$")

plt.subplot(1,3,3)
plt.plot(data[:,0], data[:,3]*1E6)
plt.scatter(data[:,0], data[:,3]*1E6)
plt.xlabel("N_x")
plt.ylabel(r"Error Convergencia $\times 10^6$")

plt.savefig("resultado.png", bbox_inches='tight')
