#include <stdio.h>   

int main(void)
{
    
    int a[5] = {2, 4, 6, 8, 10};// Primero declaramos un arreglo de 5 elementos

    int *p = a;    // Declaramos un puntero y lo inicializamos con la dirección del arreglo  que apuntara a ->(a[0])
    printf("1)a[1]=%d\n", a[1]); //Accede al índice 1 del arreglo -> a[1] = 4
    printf("2)*(a+3)=%d\n", *(a+3)); //*(a+3) equivale a (a[3] -> 8)
    printf("3)*p++=%d\n", *p++);// *p++ devuelve el valor actual de *p (a[0] = 2) y luego incrementa el puntero para que apunte a (a[1])
    printf("4)*++p=%d\n", *++p);// *++p incrementa el puntero (p pasa de a[1] -> a[2]) y devuelve el valor en esa posición -> a[2] = 6    
    printf("5)p[1]=%d\n", p[1]); // p[1] es equivalente a *(p+1) y como p está en a[2], p+1 apunta a a[3] -> 8
    printf("6)*(p+=2)=%d\n", *(p+=2));//(p+=2) mueve el puntero 2 posiciones hacia adelante p estaba en a[2] ahora queda en a[4] por lo cual ->*(p) = a[4] = 10  
    printf("7)p-a=%ld\n", p - a);// p - a calcula la distancia (en elementos) entre p y a.
    //p apunta a a[4], a apunta a a[0]. como diferencia son 4 posiciones
    
    return 0; // Fin del programa
}
