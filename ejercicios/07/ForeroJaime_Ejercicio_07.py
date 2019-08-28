import numpy as np
import random

# Ejercicio 1
print("Ejercicio 1")
def saca_media(cajon):
    n_medias = len(cajon)
    i = int(n_medias * np.random.random())
    media = cajon[i]
    return media, np.delete(cajon, i)

def saca_media_hasta_completar_par(n_colores=10):
    cajon = np.concatenate([np.arange(n_colores),np.arange(n_colores)])
    cuenta = np.zeros(n_colores, dtype=int)
    while 2 not in cuenta:
        media, cajon = saca_media(cajon)
        cuenta[media] += 1
    return np.sum(cuenta)

def experimento_medias(n_intentos=10000, n_colores=10):
    medias = np.zeros(n_intentos)
    for i in range(n_intentos):
        medias[i] = saca_media_hasta_completar_par(n_colores=n_colores)        
    return medias.mean()

print('El numero medio de medias para sacar del cajon: {}'.format(experimento_medias()))
print('')

# Ejercicio 2
print("Ejercicio 2")
def genera_secuencia(n_lanzamientos=100):
    s = np.random.random(n_lanzamientos)
    return np.round_(s)

def experimento_monedas(n_intentos=10000, n_lanzamientos=100, n_caras=50):
    conteo = np.zeros(n_intentos)
    for i in range(n_intentos):
        conteo[i] = np.sum(genera_secuencia(n_lanzamientos=n_lanzamientos))
    return np.count_nonzero(conteo==n_caras)/len(conteo)

print("La probabilidad de tener 50 caras:", experimento_monedas())
print("")

# Ejercicio 3
print("Ejercicio 3")
def genera_fechas(n_personas=20):
    fechas = np.int_(365 * np.random.random(n_personas))
    return fechas

def hay_fechas_repetidas(fechas):
    n_fechas = len(fechas)
    n_fechas_unicas = len(set(fechas))
    if n_fechas_unicas == n_fechas:
        return False
    else:
        return True

def probabilidad_fechas_repetidas(n_intentos=10000, n_personas=20):
    conteo = 0
    for i in range(n_intentos):
        fechas = genera_fechas(n_personas=n_personas)
        if hay_fechas_repetidas(fechas):
            conteo += 1
    return 1.0*conteo/n_intentos

def barrido_probabilidades(n_personas_max=50):
    probabilidades = np.zeros(n_personas_max)
    n_personas = np.zeros(n_personas_max)
    for n in range(2,n_personas_max):
        probabilidades[n] = probabilidad_fechas_repetidas(n_personas=n)
        n_personas[n] = n
        print('n_personas: {}. Proba cumples iguales {}'.format(n, probabilidades[n]))
    return probabilidades, n_personas

    
probas, personas = barrido_probabilidades()
i_50 = np.argmin(np.abs(probas-0.5))
print("n_personas para probabilidad de 0.5 :{}".format(personas[i_50]))
i_90 = np.argmin(np.abs(probas-0.9))
print("n_personas para probabilidad de 0.9 :{}".format(personas[i_90]))


