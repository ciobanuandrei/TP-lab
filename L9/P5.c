#include <stdio.h>
#include <stdlib.h>
int a[20][20] = { 0 }, n, dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 }, culoareNoua, culoareVeche, ok = 1;;
void citireMatrice()
{
	int i,j;
	FILE *f;
	f = fopen("in.txt", "rt");
	if (f == NULL)
	{
		printf("Eroare fisier");
		exit(0);
	}
	fscanf(f,"%d", &n);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			fscanf(f, "%d", &a[i][j]);


}
void afisareMatrice()
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
}
void FloodFill(int x, int y)
{
	int i;
	if (a[x][y] == culoareNoua)
		return;
	 if (x<0 || x>n || y<0 || y>n)
		return;
	 if (a[x][y] != culoareVeche)
		 return;
	 a[x][y] = culoareNoua;
	for (i = 0; i < 4; i++)
		FloodFill(x + dx[i], y + dy[i]);

}
int main()
{
	int i, j;
	citireMatrice();
	afisareMatrice();
	printf("1- Verde\n");
	printf("2-Rosu\n");
	printf("3-Albastru\n");
	printf("\nCoordonatele punctului de pornire\n");
	printf("i=");
	scanf("%d", &i);
	printf("j=");
	scanf("%d", &j);
	culoareVeche = a[i][j];
	printf("Alegeti noua culoare : ");
	scanf("%d", &culoareNoua);
	FloodFill(i, j);
	afisareMatrice();
	system("pause");
	return 0;
}