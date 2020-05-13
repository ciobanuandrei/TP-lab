 
#include <stdio.h>
#include <stdlib.h>
int search(int mat[20][20], int fromRow, int toRow,
	int fromCol, int toCol, int key)
{ 
	int i = fromRow + (toRow - fromRow) / 2;
	int j = fromCol + (toCol - fromCol) / 2;
	if (mat[i][j] == key)
		printf("True");
	else
	{
		if (i != toRow || j != fromCol)
			 search(mat, fromRow, i, j, toCol, key);

		
		if (fromRow == toRow && fromCol + 1 == toCol)
			if (mat[fromRow][toCol] == key)
				printf("True");
		if (mat[i][j] < key)
		{
			if (i + 1 <= toRow)
				 search(mat, i + 1, toRow, fromCol, toCol, key);
		}

		 
		else
		{
			if (j - 1 >= fromCol)
				 search(mat, fromRow, toRow, fromCol, j - 1, key);
		}
	}
}

int main()
{
	
	int n, mat[20][20],i,j,key;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			printf("mat[%d][%d]=", i, j);
			scanf("%d", &mat[i][j]);
		}
	printf("Give the wanted element : ");
	scanf("%d", &key);
	search(mat, 0, n-1, 0, n-1, key);
	system("pause");
	return 0;
}