import numpy  as np
import matplotlib.pyplot as plt

def parabola(v_0x, v_0y, n_points=100):
    a = -10.0
    t_max = np.abs(2.0*v_0y/a)
    t = np.linspace(0,t_max, n_points)
    x = v_0x * t
    y = v_0y * t  + (0.5 * a * t **2)
    return x, y


plt.figure()
n_init = 20
v_norm = 20.0
v_x_values = np.linspace(-19,19,n_init)
for i in range(n_init):
    v_y = np.sqrt(v_norm**2 - v_x_values[i]**2)
    x, y = parabola(v_x_values[i], v_y)

    plt.plot(x,y, color='black')
    ii = np.argmax(y)
    plt.scatter(x[ii], y[ii], color='red', s=200)

plt.title("$N=20,\ -19\leq v_{0x}\leq 19,\ |v|=20,\ a=-10$")
plt.xlim([-40,40])
plt.ylim([0,21])
plt.xlabel('x')
plt.ylabel('y')
plt.savefig("parabola.png")
