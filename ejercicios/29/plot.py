import numpy as np
import matplotlib.pyplot as plt



def grafica(datafile, plotfile, plotlabel):
    data = np.loadtxt(datafile)
    
    
    plt.figure(figsize=(14,4))
    
    plt.subplot(1,3,1)
    s = np.shape(data)
    print(s)
    n_x = s[1]
    n_t = s[0]
    plt.imshow(data, extent=[-1,1,1,0], aspect=2.0)
    plt.colorbar(label="$\psi$")
    plt.xlabel("Posicion")
    plt.ylabel("Tiempo")
    plt.title(plotlabel)


    plt.subplot(1,3,2)
    x = np.linspace(-1,1,n_x)
    delta_t = 1.0/n_t
    for i in range(n_t):
        if i%(n_t//9) == 0:
            plt.plot(x, data[i,:], alpha=(i+1)/n_t, color='black', label="t={:.02f}".format(i*delta_t))
    plt.legend(loc=1)
    plt.xlabel("Posicion")
    plt.ylabel("$\psi$")
            
    plt.subplot(1,3,3)
    t = np.linspace(0,1,n_t)
    plt.plot(t, data[:,n_x//2], alpha=i/n_t, color='black')
    plt.xlabel("Tiempo")
    plt.ylabel("$\psi$(x=0)")


    plt.savefig(plotfile, bbox_inches='tight')

grafica("evolve_30_450.dat", "evolve_A.png", "$N_x=30$ ,  $N_{tc}$")

grafica("evolve_31_450.dat", "evolve_B.png", "$N_x=31$ ,  $N_{tc}$")

grafica("evolve_29_450.dat", "evolve_C.png", "$N_x=29$ ,  $N_{tc}$")

grafica("evolve_30_440.dat", "evolve_D.png", "$N_x=30$ ,  $N_{tc}-10$")
