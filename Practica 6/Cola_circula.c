#include <stdio.h>
#define MAX 8

typedef struct {
    int datos[MAX];
    int frente;
    int final;
    int size; // Tamaño actual
} ColaCircular;

void inicializar(ColaCircular *cola) {
    cola->frente = 0;
    cola->final = 0;
    cola->size = 0;
    printf("\nCola circular inicializada.\n");
}

int isEmpty(ColaCircular *cola) {
    return cola->size == 0;
}

int isFull(ColaCircular *cola) {
    return cola->size == MAX;
}

void enqueue(ColaCircular *cola, int valor) {
    if (isFull(cola)) {
        printf("Error: Cola llena. No se puede encolar ", valor);
        return;
    }
    cola->datos[cola->final] = valor;
    cola->final = (cola->final + 1) % MAX;
    cola->size++;
}

int dequeue(ColaCircular *cola) {
    if (isEmpty(cola)) {
        printf("Error: Cola vacía.\n");
        return -1;
    }
    int valor = cola->datos[cola->frente];
    cola->frente = (cola->frente + 1) % MAX;
    cola->size--;
    return valor;
}

void printQueue(ColaCircular *cola) {
    printf("\n Estado actual de la cola:\nCola: ");
    if (isEmpty(cola)) {
        printf("(vacía)");
    } else {
        for (int i = 0; i < cola->size; i++) {
            int idx = (cola->frente + i) % MAX;
            printf("%d ", cola->datos[idx]);
        }
    }
    printf("\nFrente: %d  Final: %d  Tamaño: %d\n", cola->frente, cola->final, cola->size);
}

int main() {
    ColaCircular cola;
    inicializar(&cola);

    int n, valor, d;

    // Encolar valores
    printf("\n¿Cuántos valores deseas encolar? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Ingresa el valor [%d]: ", i + 1);
        scanf("%d", &valor);
        enqueue(&cola, valor);
    }

    printQueue(&cola);

    // Desencolar valores
    printf("\n¿Cuántos valores deseas desencolar? ");
    scanf("%d", &d);

    for (int i = 0; i < d; i++) {
        int eliminado = dequeue(&cola);
        if (eliminado != -1)
            printf("Se desencoló: %d\n", eliminado);
    }

    printQueue(&cola);

    int e;
    printf("\n¿Cuántos valores nuevos deseas encolar ahora? ");
    scanf("%d", &e);

    for (int i = 0; i < e; i++) {
        printf("Ingresa el valor nuevo [%d]: ", i + 1);
        scanf("%d", &valor);
        enqueue(&cola, valor);
    }

    printQueue(&cola);

    return 0;
}
