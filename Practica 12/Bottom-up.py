def fibonacci_bottom_up(n):
    if n <= 1:
        print([0] if n == 0 else [0,1])
        return n

    tabla = [0, 1]

    for i in range(2, n + 1):
        tabla.append(tabla[i-1] + tabla[i-2])

    print("Tabla de serie fibonacci:\n", tabla)
    return tabla[n]

fibonacci_bottom_up(50)

