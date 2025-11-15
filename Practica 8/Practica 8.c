#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *anterior;
    struct Nodo *siguiente;
};

void insertarInicio(struct Nodo **inicio, int valor) {
    struct Nodo *new = (struct Nodo*)malloc(sizeof(struct Nodo));
    new->dato = valor;
    new->anterior = NULL;
    new->siguiente = *inicio;

    if (*inicio != NULL)
        (*inicio)->anterior = new;

    *inicio = new;
}

void insertarFinal(struct Nodo **inicio, int valor) {
    struct Nodo *new = (struct Nodo*)malloc(sizeof(struct Nodo));
    new->dato = valor;
    new->siguiente = NULL;

    if (*inicio == NULL) {
        new->anterior = NULL;
        *inicio = new;
        return;
    }

    struct Nodo *temp = *inicio;
    while (temp->siguiente != NULL)
        temp = temp->siguiente;

    temp->siguiente = new;
    new->anterior = temp;
}

void recorrerAdelante(struct Nodo *inicio) {
    struct Nodo *temp = inicio;
    printf("Lista adelante: ");
    while (temp != NULL) {
        printf("%d ", temp->dato);
        temp = temp->siguiente;
    }
    printf("\n");
}

void recorrerAtras(struct Nodo *inicio) {
    if (inicio == NULL) return;

    struct Nodo *temp = inicio;
    while (temp->siguiente != NULL)
        temp = temp->siguiente;

    printf("Lista atrás: ");
    while (temp != NULL) {
        printf("%d ", temp->dato);
        temp = temp->anterior;
    }
    printf("\n");
}

void eliminar(struct Nodo **inicio, int valor) {
    struct Nodo *temp = *inicio;

    while (temp != NULL && temp->dato != valor)
        temp = temp->siguiente;

    if (temp == NULL) return;

    if (temp->anterior != NULL)
        temp->anterior->siguiente = temp->siguiente;
    else  
        *inicio = temp->siguiente;

    if (temp->siguiente != NULL)
        temp->siguiente->anterior = temp->anterior;

    free(temp);
}

void liberar(struct Nodo *inicio) {
    struct Nodo *temp;
    while (inicio != NULL) {
        temp = inicio;
        inicio = inicio->siguiente;
        free(temp);
    }
    printf("Memoria liberada \n");
}

int main() {
    struct Nodo *inicio = NULL;
    int n, valor;

    printf("¿Cuántos valores desea insertar al inicio?: ");
    scanf("%d", &n);

    int arregloInicio[n];  

    printf("Ingrese los valores:\n");
    for (int i = 0; i < n; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%d", &arregloInicio[i]);
    }

    // Insertar desde el arreglo
    for (int i = 0; i < n; i++) {
        insertarInicio(&inicio, arregloInicio[i]);
    }

    recorrerAdelante(inicio);

    printf("\n¿Cuántos valores desea insertar al final?: ");
    scanf("%d", &n);

    int arregloFin[n];  // 

    printf("Ingrese los valores:\n");
    for (int i = 0; i < n; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%d", &arregloFin[i]);
    }

    // Insertar desde el arreglo
    for (int i = 0; i < n; i++) {
        insertarFinal(&inicio, arregloFin[i]);
    }

    recorrerAdelante(inicio);
    recorrerAtras(inicio);

   //Para poder eliminar
    printf("\nValor a eliminar: ");
    scanf("%d", &valor);
    eliminar(&inicio, valor);

    recorrerAdelante(inicio);

    //Aqui liberamos memoria
    liberar(inicio);
    return 0;
}

