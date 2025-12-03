def fibonacci_top_down(n, memo=None, nivel=0):
    if memo is None:
        memo = {}

    sangria = "   " * nivel

    if n in memo:
        print(f"{sangria}f({n}) ya está en  la memoria → {memo[n]}")
        return memo[n]

    if n <= 1:
        memo[n] = n
        print(f"{sangria}Guardando: f({n}) = {n}")
        return n

    print(f"{sangria}Calculando f({n}) → f({n-1}) + f({n-2})")
    memo[n] = fibonacci_top_down(n-1, memo, nivel+1) + fibonacci_top_down(n-2, memo, nivel+1)

    print(f"{sangria}Guardando: f({n}) = {memo[n]}")
    return memo[n]

fibonacci_top_down(10)

