#include<stdlib.h>
#include<stdio.h>
#define max 999999999

int d[999][999], path[999][999];
int main()
{
	int i, j, k, m, n;
	int x, y, z;
	scanf("% d % d", &n, &m);
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			d[i][j] = max;
			path[i][j] = j;
		}
	}
	while (scanf("%d%d%d", &x, &y, &z) != EOF) {
		d[x][y] = z;
		if (x == 0 && y == 0)
			break;
	}
	for (k = 1; k <= n; k++)
	{
		for (i = 1; i <= n;i++)
		{
			for (j = 1; j <=n ; j++)
			{
				if (d[i][k] + d[k][j] < d[i][j])
				{
					d[i][j] = d[i][k] + d[k][j];
					path[i][j] = path[i][k];
				}
			}
		}
	}
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (i != j) printf("%d%d%d", i, j, d[i][j]);
		}
	}
	return 0;
}