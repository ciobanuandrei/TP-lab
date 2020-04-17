#include <stdio.h>
#include <stdlib.h>

void afiseaza(int *a, int k)
{
	int i;
	for (i = 0; i < k; i++)
		printf("%d ", *(a+i));
	printf("\n");
}

int ok(int *a, int k,int nr)
{
	int i, p = 1,ok=1;
	for (i = 0; i < k; i++)
		p = p * (*(a+i));
	if (p < nr)
		return 1;
	return 0;
}

int solutie(int *a, int k, int nr)
{
	int i, p = 1,ok=1;
	for (i = 0; i < k; i++)
		p = p * (*(a + i));
	for (i = 1; i < k; i++)
		if (*(a + i - 1) > *(a + i))
		{
			ok = 0;
			break;
		}
	if (p == nr && ok==1)
		return 1;
	return 0;
}

void backtracking(int *a, int k, int nr)
{
	int i;
	if (solutie(a, k, nr) == 1)
		afiseaza(a, k);
	else
	for (i = 2; i <= nr/2; i++)
	{
		*(a + k) = i;
		if (ok(a, k, nr) == 1)
			backtracking(a,k + 1,nr);
	}
}

int main()
{
	int *a, nr;
	printf("Numarul de descompus : ");
	scanf("%d", &nr);
	a = (int*)malloc(sizeof(int) * 20);
	backtracking(a,0,nr);
	system("pause");
	return 0;
}