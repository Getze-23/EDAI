def quicksort_practica(lista, nivel=0):
    sangria = "   " * nivel   
    print(f"{sangria}Lista recibida: {lista}")

    
    if len(lista) <= 1:
        print(f"{sangria}  Lista de tamaño 1 o vacía, se regresa igual\n")
        return lista

    pivote = lista[len(lista) // 2]
    print(f"{sangria}Pivote elegido: {pivote}")

    menores = [x for x in lista if x < pivote]
    iguales = [x for x in lista if x == pivote]
    mayores = [x for x in lista if x > pivote]

    print(f"{sangria}Menores: {menores}")
    print(f"{sangria}Iguales: {iguales}")
    print(f"{sangria}Mayores: {mayores}\n")

    print(f"{sangria} → Ordenando menores")
    menores_ordenados = quicksort_practica(menores, nivel + 1)

    print(f"{sangria} → Ordenando mayores")
    mayores_ordenados = quicksort_practica(mayores, nivel + 1)

    # Combinación igual que “divide y vencerás”
    resultado = menores_ordenados + iguales + mayores_ordenados
    print(f"{sangria}Resultado combinado: {resultado}\n")

    return resultado

quicksort_practica([8, 3, 9, 1, 4, 7, 6])

