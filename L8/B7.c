#include <stdio.h>
#include <stdlib.h>

int suma(long long int n)
{
	if (n < 10)
		return n;
	else
		return n %10 + suma(n /10);

}
  int radacinaDigitala( long int n)
{
	if (suma(n) < 10)
		return suma(n);
	else
		radacinaDigitala(suma(n));
}

int main()
{
	long  int n;
	int radacina_digitala;
	printf("Dati numarul : ");
	scanf("%ld", &n);
	radacina_digitala = radacinaDigitala(n);
	printf("Radacina digitala a lui %ld este %d \n",n, radacina_digitala);
	system("pause");
	return 0;
}