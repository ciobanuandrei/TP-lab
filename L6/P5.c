#include <stdio.h>
#include <stdlib.h>

int w[20], v[20], s, n;
void sortare()
{
	int i, j,aux;

		for(i=0;i<n-1;i++)
			for(j=0;j<n-i-1;j++)
			if (w[j] > w[j+1])
			{
				aux = w[i];
				w[i] = w[i + 1];
				w[i + 1] = aux;
			
			}

}
void citire()
{
	int i;
	printf("n=");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		printf("w[%d]=", i);
		scanf("%d", &w[i]);
	}
	printf("dati suma cautata  : ");
	scanf("%d", &s);
}
void afisare(int k)
{
	int i;
	for (i = 0; i < k; i++)
		printf("%d ", v[i]);
	printf("\n");
}
int valid(int k,int i)
{
	int j;
	for (j = 0; j < k ; j++)
		if (v[j] <= w[i])
			return 0;
	return 1;
}

void bkt(int k)
{
	int sum=0,i,j,ok;
	
	for (j = 0; j < k; j++)
		sum = sum + v[j];
	if (sum == s)
		afisare(k);
	else
		for (i = 0; i < n; i++)
		{
			
			v[k] = w[i]; 
			if (sum < s && valid(k,i)==1)
				bkt(k + 1);
		}



}

int main()
{
	citire();
	sortare();
	bkt(0);
	system("pause");
	return 0;
}