#include <stdio.h>
int main()
{
	int n;
	int a[100];//numero maximo del arreglo
	do {
		printf("Ingresa una cantidad \n");
		scanf("%d",&n);

		if(n < 0 || n > 100){
			printf("La cantidad debe estar entre 0 y 100 elementos\n");//Validacion para no agregar numeros negativos ni mayores a 100
		}
	} while(n < 0 || n > 100);
	printf("Ingrese %d numeros :\n",n);
	for(int i=0; i<n;i++)
	{
	printf("Elemento %d :",i);
	scanf("%d",&a[i]);
	}
	printf("\n Los elementos del array son :\n");
	for(int i =0;i<n;i++)
	{
	printf("%d ",a[i]);
	}
	printf("\n");
	return 0;
}