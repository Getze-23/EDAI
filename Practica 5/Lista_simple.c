#include <stdio.h>
#include <stdlib.h> // Para malloc, calloc, realloc y free

int main(void) {
    int n, m;             // Tamaños de los arreglos
    int *arr, *arr2;      // Apuntadores a enteros
    int i;

    // Reservar memoria con malloc 
    printf("¿Cuántos enteros deseas almacenar ? ");
    scanf("%d", &n);

    arr = (int *)malloc(n * sizeof(int)); // Reserva memoria para n enteros

    if (arr == NULL) { // Verifica si malloc falló
        printf("Error al reservar memoria .\n");
        return 1;
    }

    printf("\nValores iniciales (basura):\n");
    for (i = 0; i < n; i++) {
        printf("arr[%d] = %d\n", i, arr[i]); // Mostrará valores basura
    }

    //  Reservamos memoria con calloc 
    printf("\n¿Cuántos enteros deseas almacenar ? ");
    scanf("%d", &n);

    arr2 = (int *)calloc(n, sizeof(int)); // Reserva y llena con ceros

    if (arr2 == NULL) { // Verifica si calloc falló
        printf("Error al reservar memoria .\n");
        free(arr);
        return 1;
    }

    printf("\nValores iniciales (calloc - ceros):\n");
    for (i = 0; i < n; i++) {
        printf("arr2[%d] = %d\n", i, arr2[i]); // Mostrará ceros
    }

    //  Llenamoa el arreglo arr2 
    printf("\nIngresa %d valores para arr2:\n", n);
    for (i = 0; i < n; i++) {
        printf("arr2[%d] = ", i);
        scanf("%d", &arr2[i]);
    }

    //  Redimensionamos con realloc 
    printf("\nNuevo tamaño del arreglo: ");
    scanf("%d", &m);

    arr2 = (int *)realloc(arr2, m * sizeof(int)); 

    if (arr2 == NULL) {
        printf("Error al redimensionar memoria .\n");
        free(arr);
        return 1;
    }

    // Si el nuevo tamaño es mayor, pediremos  los valores faltantes
    if (m > n) {
        printf("\nIngresa los valores adicionales:\n");
        for (i = n; i < m; i++) {
            printf("arr2[%d] = ", i);
            scanf("%d", &arr2[i]);
        }
    }

    // Aqui se imprimen  todos los valores del nuevo arreglo
    printf("\nValores finales en arr2:\n");
    for (i = 0; i < m; i++) {
        printf("arr2[%d] = %d\n", i, arr2[i]);
    }

    //  Liberamos memoria 
    free(arr);
    free(arr2);
    printf("\nMemoria liberada correctamente.\n");

    return 0;
}
