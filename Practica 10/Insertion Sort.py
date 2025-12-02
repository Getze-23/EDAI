def insertion_sort():
    lista = list(map(int, input("Ingresa  los números separados por  un espacio: ").split()))

    for i in range(1, len(lista)):
        clave = lista[i]
        j = i - 1

        while j >= 0 and clave < lista[j]:
            lista[j + 1] = lista[j]
            j -= 1

        lista[j + 1] = clave

    print("Tu lista ordenada es :", lista)

insertion_sort()
