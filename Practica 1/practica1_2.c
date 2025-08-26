#include<stdio.h>
int main()
{
	int n;
	int a[100];//Valor maximo de nuestro arreglo
	int suma=0;
	 float prom;
	int  min, max, ps_Min = 0, ps_Max = 0;

	do {
		printf("Ingresa una cantidad \n");
		scanf("%d",&n);
		if(n<0 || n>100)
		{
			printf("La cantidad debe estar entre 0 y 100 elementos \n");
		}
	}while (n<0 || n>100);
	printf("Ingrese %d numeros\n",n);
	for(int i=0;i<n;i++)
	{
		printf("Elemento %d:",i);
		scanf("%d",&a[i]);
	}
	printf("\n Los elementos del array son :\n");//Muestra los elementos del arreglo ingresado
	for(int i =0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	printf("\n");

	min = a[0];
	max = a[0];

	for(int i=0; i<n; i++){//Para las posiciones maximas y minimas
		suma += a[i];
		if(a[i] < min){
			min = a[i];
			ps_Min = i;
		}
		if(a[i] > max){
			max = a[i];
			ps_Max = i;
		}
	}

	prom = suma/ n;

	printf("\nSuma = %d\n", suma);
	printf("Promedio = %.2f\n", prom);
	printf("El minimo elemento = %d esta en la posicion %d\n", min, ps_Min);
	printf("El maximo elemento = %d esta en la posicion %d\n", max, ps_Max);

	return 0;
}