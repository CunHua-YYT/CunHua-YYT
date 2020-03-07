#include<stdio.h>
#include<stdlib.h>
#define max 999999
int g[999][999];
int d[999];
int p[999];
int i, j, k;
int n, m;//µã¡¢±ß
int main()
{
	scanf("%d%d", &n, &m);
	int min, x, y, z;
	for (i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &x, &y, &z);
		g[x][y] = z;
	}
	for (i = 1; i <= n;i++)
	{
		d[i] = max;
		d[1] = 0;
	}
	for (i = 1; i <= n; i++)
	{
		min = max;
		for (j = 1; j <= n; j++)
		{
			if (!p[j] && d[j] < min)
			{
				min = d[i];
				k = j;
			}
			p[k] = 1;
			}
		for (j = 1; j <= n; j++)
		{
			if (g[k][j] != 0 && !p[j] && d[j] > d[k] + g[k][j])
				d[j] = d[k] + g[k][j];
		}
		for (i = 1; i < n; i++)
		{
			printf("%d", d[i]);
		}
	}
	return 0;
}