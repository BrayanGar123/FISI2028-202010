import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

def plot_vectors(data, row_names, col_names, figname=None):
    # renormaliza los datos
    for i in range(len(col_names)):
        data[i,:] = (data[i,:] - np.mean(data[i,:]))/np.std(data[i,:])
        
    # calcula vectores propios
    cov = np.cov(data)
    valores, vectores = np.linalg.eig(cov)
    orden_valores = np.argsort(valores)[::-1] # indices de los autovalores de menor a mayor
    
    new_data = data.T @ vectores # esto hace el cambio de base al nuevo sistema de los autovectores
        
    plt.figure(figsize=(9,9))
    # Grafica los nombres
    for i, name in enumerate(row_names):
        plt.text(new_data[i,orden_valores[0]], new_data[i,orden_valores[1]], name, alpha=0.5, fontsize=12, color='Blue')
    
    # Grafica los loading vectors
    for i, name in enumerate(col_names):
        plt.arrow(0, 0, 3*vectores[i,orden_valores[0]], 3*vectores[i, orden_valores[1]], head_width=0.1)
        plt.text(3*vectores[i,orden_valores[0]], 3*vectores[i, orden_valores[1]], name, fontsize=14, color='Red')
    
    plt.xlabel('Primera Componente Principal')
    plt.ylabel('Segunda Componente Principal')
    plt.xlim(-3.5,3.5)
    plt.ylim(-3.5,3.5)
    plt.savefig(figname)

# primera grafica
indata = pd.read_csv('USArrests.csv')
data = np.array([indata['Murder'], indata['Assault'], indata['UrbanPop'], indata['Rape']])
names = np.array(indata['Unnamed: 0'])
col_names = ['Murder', 'Assault', 'UrbanPop', 'Rape']
plot_vectors(data, names, col_names, figname='arrestos.png')

#segunda grafica
indata = pd.read_csv('Cars93.csv')
data = np.array([indata['Horsepower'], indata['Length'], indata['Width'], indata['Fuel.tank.capacity']])
names = np.array(indata['Model'])
col_names = ['Horsepower', 'Length', 'Width', 'Fuel.tank.capacity']
plot_vectors(data, names, col_names, figname='cars.png')

