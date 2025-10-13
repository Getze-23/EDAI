#include <stdio.h>
#include <stdlib.h>


struct Nodo {
    int dato;
    struct Nodo *next;
};


void insertarInicio(struct Nodo **cabeza, int valor) {
    struct Nodo *nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
    if (nuevo == NULL) {
        printf("Error al asignar memoria\n");
        return;
    }
    nuevo->dato = valor;
    nuevo->next = *cabeza; 
    *cabeza = nuevo; 
}

// ====== Recorre e imprime la lista ======
void recorrer(struct Nodo *cabeza) {
    struct Nodo *actual = cabeza;
    while (actual != NULL) {
        printf("%d -> ", actual->dato);
        actual = actual->next;
    }
    printf("NULL\n");
}

// ====== Elimina un nodo con cierto valor ======
void eliminar(struct Nodo **cabeza, int valor) {
    struct Nodo *actual = *cabeza, *anterior = NULL;

    while (actual != NULL && actual->dato != valor) {
        anterior = actual;
        actual = actual->next;
    }

    if (actual == NULL) {
        printf("Valor no encontrado.\n");
        return;
    }

    if (anterior == NULL) {
        *cabeza = actual->next; // era la cabeza
    } else {
        anterior->next = actual->next; // salta el nodo eliminado
    }

    free(actual);
    printf("Nodo con valor %d eliminado.\n", valor);
}


void liberar(struct Nodo *cabeza) {
    struct Nodo *temp;
    while (cabeza != NULL) {
        temp = cabeza;
        cabeza = cabeza->next;
        free(temp);
    }
    printf("Memoria liberada correctamente.\n");
}


int main(void) {
    struct Nodo *cabeza = NULL;
    int n, valor, eliminarValor;

    printf("¿Cuántos valores deseas insertar? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Inserta el valor %d: ", i + 1);
        scanf("%d", &valor);
        insertarInicio(&cabeza, valor);
        printf("Lista actual: ");
        recorrer(cabeza);
    }

    printf("\nIngresa el valor que deseas eliminar: ");
    scanf("%d", &eliminarValor);
    eliminar(&cabeza, eliminarValor);

    printf("Lista después de eliminar:\n");
    recorrer(cabeza);

    liberar(cabeza);
    return 0;
}

