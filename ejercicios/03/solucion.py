import random
import math
# Solucion primera parte


# [1] (10 puntos) Compute how many times, on average, do you have to throw a die (with only six faces) in order to reach reach a minimum of 100 points. In this game you start with 0 points, you throw the die and add the number you get to the total account. Use the results of random.random() to implement the die throw.

n_games = 10000
n_try = []
for i in range(n_games):
    n = 0
    points = 0
    while(points < 100):
        i = (random.random()*6)//1 + 1
        points += i
        n += 1
    n_try.append(n)
    

suma = 0
for i in range(n_games):
    suma += n_try[i]

promedio = suma/len(n_try)
print(promedio)


# [2] (10 puntos) Define a function distance that takes as arguments two lists a,b and computes the Euclidean distance between the two:

def distance(a,b):
    n = len(a)
    d = 0.0
    for i in range(n):
        d += (a[i] -b[i])**2
    d = math.sqrt(d)
    return d

print(distance([0,0], [1,1]))
print(distance([1,5], [2,2]))
print(distance([0,1,2], [2,3,4]))

# [3] (10 puntos) Redefine the class Circle to include a new method called perimeter that returns the value of the circle's perimeter.

class Circle:
    def __init__(self, radius):
        self.radius = radius #all attributes must be preceded by "self."
    def area(self):
        import math
        return math.pi * self.radius * self.radius
    def perimeter(self):
        import math
        return 2.0  * math.pi * self.radius


# [4] (10 puntos) Define the class Vector3D to represent vectors in 3D. The class must have
#Three attributes: x, y, and z, to store the coordinates.
#A method called dot that computes the dot product

class Vector3D:
    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z
    def dot(self, v):
        return self.x  * v.x + self.y * v.y + self.z * v.z

v = Vector3D(2, 0, 1)
w = Vector3D(1, -1, 3)
print(v.dot(w))

# [5] (10 puntos) Import the module random and use the function shuffle to shuffle the contents of a list that has the integers from 0 to 9. Print the list before and after shuffling. Use random.shuffle? to read the documentation string for that function. 

import random

a = list(range(10))
print(a)
random.shuffle(a)
print(a)

# Ejercicio 03 - Segunda parte.

# [6] (30 puntos)
# Funciones
#    Encuentra la palabra que mas se repite en 'archivo'
#    que tiene al menos 'n_letras'.

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
        for palabra in linea_completa.split():
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

# Clases
# [7] (20 puntos) Extienda la clase Vector3D para calcular el producto cruz entre vectores.
class Vector3D:
    def __init__(self, x, y, z):
        self.x = x
        self.y = y
        self.z = z
    def dot(self, v):
        return self.x  * v.x + self.y * v.y + self.z * v.z
    def cross(self, v):
        i = self.y * v.z - self.z * v.y
        j = self.z * v.x - self.x * v.z
        k = self.x * v.y - self.y * v.x
        self.x = i
        self.y = j
        self.z = k

v = Vector3D(2, 0, 1)
w = Vector3D(1, -1, 3)
v.cross(w)
print(v.x, v.y, v.z)

