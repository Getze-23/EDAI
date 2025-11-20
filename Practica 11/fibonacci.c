#include <stdio.h>

int  long memoria[100];  
int long fibonacci(int n)
 {

    if (n == 1) return 0;   // f1 = 0
    if (n == 2) return 1;   // f2 = 1
    if (memoria[n] != -1) {
        return memoria[n];
    }

    memoria[n] = fibonacci(n - 1) + fibonacci(n - 2);

    return memoria[n];
}

int main() {

    for (int i = 0; i < 100; i++) {
        memoria[i] = -1;
    }

    int posiciones[] = {7, 21, 40, 71, 94};
    int total = 5;

    printf("Valores de la serie Fibonacci:\n\n");

    for (int i = 0; i < total; i++) {
        int pos = posiciones[i];
        printf("Fibonacci(%d) = %lld\n", pos, fibonacci(pos));
    }

    printf("\n");

    return 0;
}

