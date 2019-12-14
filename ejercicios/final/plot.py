import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt('datos.txt')

min_t = data[:,0].min()
max_t = data[:,0].max()

inicial_x = data[data[:,0]==min_t, 1]
inicial_u = data[data[:,0]==min_t, 2]

final_x = data[data[:,0]==max_t, 1]
final_u = data[data[:,0]==max_t, 2]


plt.plot(inicial_x, inicial_u, label='inicial')
plt.plot(final_x, final_u, '--', label='final')
plt.legend()
plt.xlabel("x")
plt.ylabel("u")
plt.savefig('resultado.png')
