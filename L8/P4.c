#include <stdio.h>
#include <stdlib.h>
int sumaDoWhile(int n)
{
	int suma = 0;
	if(n>=1)
	do
	{
		suma = suma + n;
		n--;
	} while (n > 0);
	return suma;
}

int sumaWhile(int n)
{
	int suma = 0;
	while (n > 0)
	{
		suma = suma + n;
		n--;
	}
	return suma;
}

int sumaFor(int n)
{
	int i,suma=0;
	for (i = 1; i <= n; i++)
		suma = suma + i;
	return suma;

}

int sumaRecursiv(int n)
{
	if (n == 1)
		return 1;
	return n + sumaRecursiv(n - 1);
}
int main()
{
	int n;
	printf("Dati numarul : ");
	scanf("%d", &n);
	printf("\nSuma primelor %d numere utilizand : \n",n);
	printf("\t1)do while : %d \n", sumaDoWhile(n));
	printf("\t2)while : %d \n", sumaWhile(n));
	printf("\t2)for : %d \n", sumaFor(n));
	printf("\t4)recursiv  : %d \n", sumaRecursiv(n));
	system("pause");
	return 0;
}