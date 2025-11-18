#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int x;
    struct Nodo *anterior;
    struct Nodo *siguiente;
};

void insertarFinalCircular(struct Nodo **inicio, int valor) {
    struct Nodo *new = (struct Nodo*)malloc(sizeof(struct Nodo));
    new->x = valor;

    if (*inicio == NULL) {
        new->siguiente = new;
        new->anterior = new;
        *inicio = new;
        return;
    }

    struct Nodo *ultimo = (*inicio)->anterior;

    new->siguiente = *inicio;
    new->anterior = ultimo;

    ultimo->siguiente = new;
    (*inicio)->anterior = new;
}

void recorrerCircular(struct Nodo *inicio) {
    if (inicio == NULL) return;

    struct Nodo *temp = inicio;
    printf("Lista circular por delante: ");

    do {
        printf("%d ", temp->x);
        temp = temp->siguiente;
    } while (temp != inicio);

    printf("\n");
}

void recorrerCircularAtras(struct Nodo *inicio) {
    if (inicio == NULL) return;

    struct Nodo *temp = inicio->anterior;
    printf("Lista circular por atrás: ");

    do {
        printf("%d ", temp->x);
        temp = temp->anterior;
    } while (temp != inicio->anterior);

    printf("\n");
}

void eliminarCircular(struct Nodo **inicio, int valor) {
    if (*inicio == NULL) return;

    struct Nodo *temp = *inicio;

    do {
        if (temp->x == valor)
            break;
        temp = temp->siguiente;
    } while (temp != *inicio);

    if (temp->x != valor)
        return;

    if (temp->siguiente == temp) {
        free(temp);
        *inicio = NULL;
        return;
    }

    temp->anterior->siguiente = temp->siguiente;
    temp->siguiente->anterior = temp->anterior;

    if (*inicio == temp)
        *inicio = temp->siguiente;

    free(temp);
}

int main() {
    struct Nodo *inicio = NULL;
    int n, valor;

    printf("¿Cuántos valores desea insertar ?: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Valor: ");
        scanf("%d", &valor);
        insertarFinalCircular(&inicio, valor);
    }

    printf("\nDespués de las inserciones:\n");
    recorrerCircular(inicio);
    recorrerCircularAtras(inicio);

    printf("\nValor a eliminar: ");
    scanf("%d", &valor);

    eliminarCircular(&inicio, valor);

    printf("\nDespués de  la eliminacion:\n");
    recorrerCircular(inicio);
    recorrerCircularAtras(inicio);

    return 0;
}

