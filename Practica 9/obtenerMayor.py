def obtenerMayor(param1, param2):
    if param1 < param2:
        print('{} es mayor que {}'.format(param2, param1))
    else:
        print('{} es mayor que {}'.format(param1, param2))


# Llamadas a la función (deben ir fuera)
obtenerMayor(5, 7)
obtenerMayor(7, 5)

# Código independiente
x = y = z = 3
if x == y == z:
    print(True)
