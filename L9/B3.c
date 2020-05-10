#include <stdio.h>
#include <stdlib.h>
void f(int k)
{
	if (k == 1)
		return;
	else if ((k & 1) == 0)
	{
		printf("%d->", k / 2);
		f(k / 2);
	}
	else
	{
		printf("%d->", 3 * k + 1);
		f(3 * k + 1);
	}
}
int main()
{
	int n;
	printf("n=");
	scanf("%d", &n);
	f(n);
	system("pause");
	return 0;
}