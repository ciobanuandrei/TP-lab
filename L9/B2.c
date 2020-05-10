// putin extra sa nu iasa din intamplare plagiat cu cineva random :))  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char arr[20];

int factorial(int n)
{
	if (n == 0 || n == 1)
		return 1;
	return n * factorial(n - 1);
}
void swap(char *a, char* b)
{
	char temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void permutation(int start, int end)
{
	if (start == end)
	{
		printf("%s\n", arr);
		return;
	}
	int i;
	for (i = start; i <= end; i++)
	{
		swap(&arr[i], &arr[start]);
		permutation(start + 1, end);
		swap(&arr[i], &arr[start]);
	}
}

int main()
{
	int nrPermutari,n;
	printf("Dati sirul : ");
	scanf("%s", arr);
	n = strlen(arr);
	nrPermutari = factorial(n);
	printf("Cele %d permutari lexicografice :\n",nrPermutari);
	permutation(0, n- 1);
	system("pause");
	return 0;
}