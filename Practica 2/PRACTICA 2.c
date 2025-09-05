#include<stdio.h>
int main (void)
{
	 int a[5]={2,4,6,8,10};
	 int *p=a;

	 printf("1)a[1]=%d\n",a[1]);
	 printf("2)*(a+3)=%d\n",*(a+3));
	 printf("3)*p++=%d\n",*p++);
	 printf("4)*++p=%d\n",*p++);
	 printf("5)p[1]=%d\n",p[1]);
	 printf("6)*(p+=2)=%d\n",*(p+=2));
	 printf("7)p-a=%ld\n",p-a);
	 return 0;
}