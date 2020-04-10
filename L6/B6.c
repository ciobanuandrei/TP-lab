#include <stdio.h>
#include <stdlib.h>
int v[20],a[20], n;
void sortare()
{
	int i, j, aux;

	for (i = 0; i < n - 1; i++)
		for (j = i+1; j < n ; j++)
			if (v[i] > v[j ])
			{
				aux = v[i];
				v[i] = v[j];
				v[j] = aux;

			}

}
void citire()
{
	int i;
	printf("n=");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		printf("v[%d]=", i);
		scanf("%d", &v[i]);
	}
}
void afisare(int k)
{
	int i;
	for (i = 0; i < k; i++)
		printf("%d ", a[i]);
	printf("\n");
}
int valid(int k,int i)
{
	int j;
	for (j = 0; j < k; j++)
		if (a[j] == v[i])
			return 0;
	return 1;
}
void back(int k)
{
	int i;
	if (k == 4)
		afisare(k);
	else
		for (i = 0; i < n; i++)
		{
			a[k] = v[i];
			if (valid(k,i) == 1)
				back(k + 1);
		}
}
int main()
{
	citire();
	sortare();
	back(0);
	system("pause");
	return 0;
}