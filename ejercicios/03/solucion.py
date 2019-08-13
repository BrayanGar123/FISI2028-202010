# Ejercicio 03 - Segunda parte.

# Funciones
def cuenta_palabra(archivo, n_letras=4):
    """
    Encuentra la palabra que mas se repite en 'archivo'
    que tiene al menos 'n_letras'.
    """

    filein = open(archivo, "r")
    texto = filein.readlines()
    filein.close()

    cuenta = {}
    for linea_completa in texto:
        linea = linea_completa.split()
        for palabra in linea:
            if(len(palabra)>=n_letras):
                if palabra in cuenta.keys():
                    cuenta[palabra] += 1
                else:
                    cuenta[palabra] = 1
    conteo = 0
    palabra_mas_repetida = ''
    for palabra in cuenta.keys():
        if cuenta[palabra] > conteo:
            palabra_mas_repetida = palabra
            conteo = cuenta[palabra]

    return  palabra, conteo

n_letras = 4
p, cuenta = cuenta_palabra("hamlet.txt", n_letras=n_letras)
print("La palabra mas repetida con al menos {} letras es: {} que se encuentra {} veces\n".format(n_letras, p, cuenta))


n_letras = 8
p, cuenta = cuenta_palabra("hamlet.txt", n_letras=n_letras)
print("La palabra mas repetida con al menos {} letras es: {} que se encuentra {} veces\n".format(n_letras, p, cuenta))

# p, cuenta = cuenta_palabra("hamlet.txt", n_letras=7)
# print "La palabra mas repetida es: {} que se encuentra {} veces\n".format(p, cuenta[p])

# Clases
# v = Vector3D(2, 0, 1)
# w = Vector3D(1, -1, 3)
# v.cross(w)
