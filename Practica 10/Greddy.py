def greedy_cambio():
    monto = int(input("Monto a devolver: "))
    monedas = [10, 5, 2, 1]   #las mondeas q actualmente existen

    resultado = {}
    restante = monto

    for moneda in monedas:
        if restante >= moneda:
            cantidad = restante // moneda
            restante -= cantidad * moneda
            resultado[moneda] = cantidad

    print("\nCambio que debes regresar (Greedy):")
    for m, c in resultado.items():
        print(f"Moneda con valor de: {m}: {c}")

greedy_cambio()
