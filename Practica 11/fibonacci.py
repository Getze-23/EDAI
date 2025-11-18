
memoria = {1: 0, 2: 1}


def fibonacci(n):
    
    if n == 1:
        return 0
    if n == 2:
        return 1

    if n in memoria:
        return memoria[n]

    memoria[n] = fibonacci(n - 1) + fibonacci(n - 2)

    return memoria[n]


posiciones = [7, 21, 40, 71, 94]

print("Valores de la secuencia de Fibonacci:\n")

for p in posiciones:
    print(f"Fibonacci({p}) =", fibonacci(p))

