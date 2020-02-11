# funciones

def suma (a, b):
    return a+b 



# Para ejecutarme:
# python3 meh.py

# Esto es un comentario

"""
Esto es un comentario
en muchas
lineas
"""

# Mostrar por pantalla
print('hola mundo')

# variables

#char
a = "f"
print (a)

# string
a = "ewtrwe"
print (a)

# integer
a = 3
print (a)

# float
a = 3.3 
print (a)

# Booleano
a = False
print(a)

a = True
print(a)

# + cosis del print
a = 53
print("la variable %s a es: %s " % (a, a))
# if
edad = 15
if edad > 18:
    print("es mayor de edad")
else:
    print("es menor de edad")


# pedir la edad
# int() float() bool() str() int() 

edad = int(input("Introduce tu edad: "))

if edad > 18:
    print("es mayor de edad")
else:
    print("es menor de edad")

# vectors

llista_numeros = [1, 2, 3 ,4]
llista_numeros.append(5)
print("la lista tiene %s posiciones" % len(llista_numeros))
print(llista_numeros)


for num in llista_numeros:
    print(num)
    

print(range(0, len(llista_numeros)))

for i in range(0, len(llista_numeros)):
    print(llista_numeros[i])


#while (True):
#    print ("holap")

print()
print (suma(3,4))
