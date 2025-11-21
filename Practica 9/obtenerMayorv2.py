def obtenerMayorv2(param1, param2):
    if param1 < param2:
        return param2
    else:
        return param1

print("El mayor es {}".format(obtenerMayorv2(4, 20)))
print("El mayor es {}".format(obtenerMayorv2(11, 6)))
