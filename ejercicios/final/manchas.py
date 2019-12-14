import numpy as np
import matplotlib.pyplot as plt
import scipy.fftpack

# Leo y recorto los datos
data = np.loadtxt("monthrg.dat")
fecha = data[:,0] + data[:,1]/12.0
manchas = data[:,3]
ii = fecha>1900

# Resto la media para que no domine la frecuencia 0 en la transformada de fourier.
mean_manchas = np.mean(manchas[ii])
manchas = manchas[ii] - mean_manchas
fecha = fecha[ii]
n_points = len(manchas)

# Calculo la transformada de Fourier
fft_manchas = np.fft.fft(manchas)
frecuencias = np.fft.fftfreq(n_points, 1)
fft_norm = np.abs(fft_manchas)

# encuentra la frecuencia dominante
ii = np.argmax(fft_norm)
periodo_year = (1/frecuencias[ii])/12.0

# Frecuecias mayor a la dominante
ii_altas = np.abs(frecuencias) > (frecuencias[ii])
# Frecuecias menores a la dominante
ii_bajas = np.abs(frecuencias) < (frecuencias[ii])

# Hago cero todos los modos menos los de la frecuencia dominante
fft_manchas[ii_altas | ii_bajas] = 0.0

# Calculo la transformada inversa
manchas_dominante = np.fft.ifft(fft_manchas)

plt.title(r"El per\'iodo es de {:.2f} a\~nos".format(periodo_year))
plt.plot(fecha, manchas+ mean_manchas, label='datos')
plt.plot(fecha, np.real(manchas_dominante) + mean_manchas, label='frecuencia dominante')
plt.xlabel('Frecuencia (1/mes)')
plt.ylabel('Norma FFT')
plt.legend()
plt.savefig('manchas.png')
