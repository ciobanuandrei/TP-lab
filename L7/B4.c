#include <stdio.h> 
#include <stdlib.h>
 
int N, maze[20][20],sol[20][2],count;
void printSolution(int count)
{
	int i;
	printf("The solution of the maze : \n");
	for (i = 0; i < count; i++)
		printf("%d%d-", sol[i][0], sol[i][1]);
	printf("\n");
}

int isSafe(int maze[20][20], int x, int y)
{
	if (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1)
		return 1;

	return 0;
}
int solveMaze(int maze[20][20])
{

	if (solveMazeUtil(maze, 0, 0,0) == 0) {
		printf("Solution doesn't exist");
		return 0;
	}

	printSolution(count);
	return 1;
}


int solveMazeUtil(int maze[20][20], int x, int y,int k)
{
	if (x == N - 1 && y == N - 1 && maze[x][y] == 1) {
		sol[k][0] = x;
		sol[k][1] = y;
		count = k + 1;
		return 1;
	}
	if (isSafe(maze, x, y) == 1) { 
		sol[k][0] = x;
		sol[k][1] = y;

		if (solveMazeUtil(maze, x + 1, y, k+1) == 1)
			return 1;

		if (solveMazeUtil(maze, x, y + 1,k+1) == 1)
			return 1;
		if (solveMazeUtil(maze, x - 1, y,k+1) == 1)
			return 1;
		if (solveMazeUtil(maze, x, y - 1, k+1) == 1)
			return 1;
		
return 0;
	}
	return 0;
}
int main()
{
	int maze[20][20],i,j;
	printf("N=");
	scanf("%d", &N);
	for(i=0;i<N;i++)
		for (j = 0; j < N; j++)
		{
			printf("maze[%d][%d]=", i, j);
			scanf("%d", &maze[i][j]);
		}

	solveMaze(maze);
	system("pause");
	return 0;
}