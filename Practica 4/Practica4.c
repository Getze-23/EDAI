#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m, i;
    int *array, *array2;

    // Para  malloc
    printf("¿Cuántos enteros deseas almacenar? ");
    scanf("%d", &n);

    array = (int *)malloc(n * sizeof(int));
    if (array == NULL) {
        printf("Error al reservar memoria\n");
        return 1;
    }

    printf("\nValores iniciales:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);  // basura
    }
    printf("\n");

    // Para calloc
    array2 = (int *)calloc(n, sizeof(int));
    if (array2 == NULL) {
        printf("Error al reservar memoria con calloc.\n");
        free(array);
        return 1;
    }

    printf("\nValores iniciales con calloc:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", array2[i]);  // inicializados en 0
    }
    printf("\n");

    // Paso 3: Llenar arreglo con valores
    printf("\nA continuacion introduce %d valores:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &array2[i]);
    }

    // Paso 4: Redimensionar con realloc
    printf("\nNuevo tamaño del arreglo: ");
    scanf("%d", &m);

    array2 = (int *)realloc(array2, m * sizeof(int));
    if (array2 == NULL) {
        printf("Error al redimensionar la  memoria.\n");
        free(array);
        return 1;
    }

    if (m > n) {
        printf("\nIntroduce los %d valores adicionales:\n", m - n);
        for (i = n; i < m; i++) {
            scanf("%d", &array2[i]);
        }
    }

    printf("\nValores actuales del arreglo:\n");
    for (i = 0; i < m; i++) {
        printf("%d ", array2[i]);
    }
    printf("\n");

    // Paso 5: Liberar memoria
    free(array);
    free(array2);
    printf("\nMemoria liberada correctamente.\n");

    return 0;
}
