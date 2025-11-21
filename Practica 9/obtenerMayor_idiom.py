def obtenerMayor_idiom(param1, param2):
    valor = param2 if (param1 < param2) else param1
    return valor

print("El mayor es {}".format(obtenerMayor_idiom(11, 6)))
