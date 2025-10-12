#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int valor;
    struct Nodo *next;
} Nodo;

Nodo* crearNodo(int valor) {
    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo));
    if (nuevo == NULL) {
        printf("Error al reservar memoria.\n");
        exit(1);
    }
    nuevo->valor = valor;
    nuevo->next = NULL;
    return nuevo;
}

// Función para liberar toda la lista circular
void liberarLista(Nodo *inicio) {
    if (inicio == NULL) return;

    Nodo *actual = inicio->next;
    while (actual != inicio) {
        Nodo *temp = actual;
        actual = actual->next;
        free(temp);
    }
    free(inicio);
}

int main(void) {
    int n, m, i, valor;
    Nodo *inicio = NULL, *ultimo = NULL, *nuevo, *actual;

    
    printf("¿Cuántos enteros deseas almacenar? ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Ingresa valor %d: ", i + 1);
        scanf("%d", &valor);

        nuevo = crearNodo(valor);

        if (inicio == NULL) {
            inicio = nuevo;
            ultimo = nuevo;
            nuevo->next = inicio; 
        } else {
            ultimo->next = nuevo;
            ultimo = nuevo;
            ultimo->next = inicio; 
        }
    }

 
    printf("\nValores actuales en la lista circular:\n");
    if (inicio != NULL) {
        actual = inicio;
        do {
            printf("%d ", actual->valor);
            actual = actual->next;
        } while (actual != inicio);
    }
    printf("\n");

    
    printf("\nNuevo tamaño de la lista: ");
    scanf("%d", &m);

    if (m > n) {
        printf("\nIngresa los valores adicionales:\n");
        for (i = n; i < m; i++) {
            printf("Nuevo valor %d: ", i + 1);
            scanf("%d", &valor);

            nuevo = crearNodo(valor);
            if (inicio == NULL) {
                inicio = nuevo;
                ultimo = nuevo;
                nuevo->next = inicio;
            } else {
                ultimo->next = nuevo;
                ultimo = nuevo;
                ultimo->next = inicio;
            }
        }
    } else if (m < n) {
       
        printf("\nReduciendo lista a %d elementos...\n", m);
        actual = inicio;
        for (i = 1; i < m; i++) {
            actual = actual->next;
        }
        
        Nodo *aBorrar = actual->next;
        actual->next = inicio; 
        ultimo = actual;

        
        while (aBorrar != inicio) {
            Nodo *temp = aBorrar;
            aBorrar = aBorrar->next;
            free(temp);
        }
    }

    
    printf("\nValores finales en la lista circular:\n");
    if (inicio != NULL) {
        actual = inicio;
        do {
            printf("%d ", actual->valor);
            actual = actual->next;
        } while (actual != inicio);
    }
    printf("\n");


    liberarLista(inicio);
    printf("\nMemoria liberada correctamente.\n");

    return 0;
}
