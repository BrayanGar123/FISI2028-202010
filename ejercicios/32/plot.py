import numpy as np
import matplotlib.pyplot as plt



def grafica(datafile, plotfile, plotlabel):
    data = np.loadtxt(datafile)
    
    
    plt.figure(figsize=(19,4))
    
    plt.subplot(1,3,1)
    s = np.shape(data)
    print(s)
    n_x = s[1]
    n_t = s[0]
    plt.imshow(data*1E4, extent=[0,1,0.1,0], aspect=10.0)
    plt.colorbar(label=r"$\psi\times 10^5$")
    plt.xlabel("Posicion")
    plt.ylabel("Tiempo")
    plt.title(plotlabel)


    plt.subplot(1,3,2)
    x = np.linspace(0,1,n_x)
    delta_t = 0.1/n_t
    for i in range(n_t):
        if i%(n_t//9) == 0:
            plt.plot(x, data[i,:]*1E4, alpha=(i+1)/n_t, color='black', label="t={:.02f}".format(i*delta_t))
    plt.legend(loc=1)
    plt.xlabel("Posicion")
    plt.ylabel(r"$\psi\times 10^5$")
            
    plt.subplot(1,3,3)
    t = np.linspace(0,0.1,n_t)
    plt.plot(t, data[:,n_x//4]*1E4, color='black')
    plt.xlabel("Tiempo")
    plt.ylabel(r"$\psi(L/4)\times 10^5$")


    plt.savefig(plotfile, bbox_inches='tight')
#    plt.savefig(plotfile)

grafica("datos.dat", "resultado.png", "$N_x=100$ ,  $N_{t}=1000$")
