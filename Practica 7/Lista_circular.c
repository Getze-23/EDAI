#include <stdio.h>
#include <stdlib.h>

struct Nodo {
    int dato;
    struct Nodo *next;
};

// ===== Inserta un nodo al inicio en una lista circular =====
void insertarInicioCircular(struct Nodo **cabeza, struct Nodo **ultimo, int valor) {
    struct Nodo *nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
    if (nuevo == NULL) {
        printf("Error al asignar memoria\n");
        return;
    }

    nuevo->dato = valor;

    
    if (*cabeza == NULL) {
        *cabeza = nuevo;
        *ultimo = nuevo;
        nuevo->next = *cabeza; // apunta a sí mismo
    } 
    else {
        nuevo->next = *cabeza;
        (*ultimo)->next = nuevo;
        *cabeza = nuevo;
    }
}


void recorrerCircular(struct Nodo *cabeza) {
    if (cabeza == NULL) {
        printf("Lista vacía.\n");
        return;
    }

    struct Nodo *actual = cabeza;
    do {
        printf("%d -> ", actual->dato);
        actual = actual->next;
    } while (actual != cabeza);

    printf("%d\n", cabeza->dato); // muestra el valor de la cabeza 
}


void eliminarCircular(struct Nodo **cabeza, struct Nodo **ultimo, int valor) {
    if (*cabeza == NULL) {
        printf("La lista está vacía.\n");
        return;
    }

    struct Nodo *actual = *cabeza;
    struct Nodo *anterior = *ultimo;
    int encontrado = 0;

    
    do {
        if (actual->dato == valor) {
            encontrado = 1;
            break;
        }
        anterior = actual;
        actual = actual->next;
    } while (actual != *cabeza);

    if (!encontrado) {
        printf("Valor no encontrado.\n");
        return;
    }

    
    if (actual == *cabeza && actual == *ultimo) {
        *cabeza = NULL;
        *ultimo = NULL;
    }
    
    else if (actual == *cabeza) {
        *cabeza = (*cabeza)->next;
        (*ultimo)->next = *cabeza;
    }
    
    else if (actual == *ultimo) {
        anterior->next = *cabeza;
        *ultimo = anterior;
    }
    
    else {
        anterior->next = actual->next;
    }

    free(actual);
    printf("Nodo con valor %d eliminado.\n", valor);
}


void liberarCircular(struct Nodo **cabeza, struct Nodo **ultimo) {
    if (*cabeza == NULL) return;

    struct Nodo *actual = *cabeza;
    struct Nodo *siguiente;

    do {
        siguiente = actual->next;
        free(actual);
        actual = siguiente;
    } while (actual != *cabeza);

    *cabeza = NULL;
    *ultimo = NULL;
    printf("Memoria liberada correctamente.\n");
}

int main(void) {
    struct Nodo *cabeza = NULL, *ultimo = NULL;
    int n, valor, eliminarValor;

    printf("¿Cuántos valores deseas insertar? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Inserta el valor %d: ", i + 1);
        scanf("%d", &valor);
        insertarInicioCircular(&cabeza, &ultimo, valor);
        printf("Lista actual: ");
        recorrerCircular(cabeza);
    }

    printf("\nIngresa el valor que deseas eliminar: ");
    scanf("%d", &eliminarValor);
    eliminarCircular(&cabeza, &ultimo, eliminarValor);

    printf("Lista después de eliminar:\n");
    recorrerCircular(cabeza);

    liberarCircular(&cabeza, &ultimo);
    return 0;
}
