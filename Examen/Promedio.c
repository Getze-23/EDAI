#include <stdio.h>
#include <stdlib.h> //Es la libreria que utilizaremos para usar memoria dinamica (calloc,malloc,realloc,free)

int main(void)//INICIA EL PROGRAMA
{
	int n,bonus;//Declara dos variables enteras
	float *calificaciones; // Declara un puntero a float
    float suma=0.0; // Variable para acumular loa suma de todas las calificaciones

	printf("¿Cuantos estudiantes deseas registrar?\n");//Mensaje solicitando la cantidad de estudiantes
	scanf("%d",&n);//Lee el número de estudiantes ingresado
	 calificaciones=malloc(n* sizeof(float));//// Asigna memoria dinámica para n elementos de tipo float y apunta calificaciones
	 if (calificaciones == NULL)// Verifica si malloc falló (no se puede asignar memoria)
	 {
	 	printf("Error:No hay suficiente memoria.\n");// Muestra un mensaje de error si no se pudo asignar memoria
	 	return 1;// Termina el programa con código de error 1
	 }
	 for(int i=0;i<n;i++)//Bucle donde se recorre cada estudiante desde i = 0 hasta i = n-1
	 {
	 	printf("Calificacion del estudiante :%d\n",i+1);//Pide la calificación del estudiante
	 	scanf("%f",&calificaciones[i]);//Lee la calificación del estudiante y la guarda en el arreglo
	 	suma+=calificaciones[i];// Suma la calificación al acumulador suma
	 }
	 printf("El promedio de los alumnos ingresados es :%.2f\n\n",suma/n);//Calcula y muestra el promedio inicial con 2 decimales

      do {//Bucle para que la opción ingresada sea válida (1 o 0)
        printf("¿Deseas agregar más estudiantes? (1 = Sí, 0 = No): ");//Pregunta si desea agregar mas opciones
        scanf("%d", &bonus);//Lee la respuesta del usuario

        if (bonus != 1 && bonus != 0) {//// Si la opción no es 1 ni 0   
            printf("Opción no válida. Debes ingresar 1 o 0.\n\n");//Muestra un mensaje de error
        }

    } while (bonus != 1 && bonus != 0);// Repite mientras la opción ingresada no sea válida

    // Si el usuario elige 1, agregamos más estudiantes
    if (bonus == 1) {
        printf("¿Cuántos estudiantes adicionales deseas agregar? "); // Pide cuántos estudiantes más desea agregar
        scanf("%d", &bonus);// Lee la cantidad de estudiantes adicionales

        if (bonus > 0) {// Si la cantidad ingresada es válida (mayor que 0)
            int nuevo_tamano = n + bonus; // Calcula el nuevo tamaño del arreglo

            float *tmp = realloc(calificaciones, nuevo_tamano * sizeof(float));// Redimensiona la memoria dinámica para el nuevo tamaño
            if (tmp == NULL) { //Verifica si realloc falló     
                printf("Error al ampliar memoria.\n");// Muestra mensaje de error
                free(calificaciones);// Libera la memoria para evitar fugas
                return 1;// Termina el programa con error
            }

            calificaciones = tmp;  // Actualiza el puntero al nuevo bloque de memoria

            for (int i = n; i < nuevo_tamano; i++) {// Ciclo para ingresar las calificaciones de los estudiantes extra
                printf("Calificación del nuevo estudiante %d: ", i + 1); // Pide la calificación del nuevo estudiante
                scanf("%f", &calificaciones[i]);// Guarda la calificación en el arreglo
                suma += calificaciones[i];// Suma la calificación al acumulador para el promedio
            }

            n = nuevo_tamano; // Actualiza n con el nuevo número total de estudiantes

        } else {
            printf("Número inválido de estudiantes.\n");//Muestra un mensaje si se ingresó un número no válido
        }
    }
    printf("\n Calificaciones registradas \n\n"); 
    for (int i = 0; i < n; i++)
    {//Bucle que recorre todas las calificaciones
        printf("Estudiante %d: %.2f\n", i + 1, calificaciones[i]);//Muestra la calificacion de cada estudiante 
    }
    printf("\nPromedio general: %.2f\n", suma / n);//muestta el promedio total
    free(calificaciones);//Libera memoria
    return 0;//Termina el programa
}
