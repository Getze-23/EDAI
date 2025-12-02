import itertools
import string
import time

def fuerza_bruta():
    password = input("Ingresa la contraseña a buscar: ")
    longitud = len(password)

    caracteres = string.digits  

    print(f"\nBuscando  la contraseña con {longitud} dígitos...\n")

    inicio = time.time()

    for combinacion in itertools.product(caracteres, repeat=longitud):
        intento = "".join(combinacion)
        if intento == password:
            fin = time.time()
            print(f"Contraseña encontrada: {intento}")
            print(f"Tiempo transcurrido: {fin - inicio:.4f} segundos\n")
            return

    print("No se encontró la contraseña.\n")

fuerza_bruta()

