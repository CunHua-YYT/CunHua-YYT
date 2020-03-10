#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
	int T[999];
	int j;
	int* p = T;
	memset(T, 0, sizeof(T));
	for (int i = 0; i < 999; i++)
	{
		scanf("%d", &T[i]);
		if (T[i] == -1)
			break;
	}
	for (int i = 999; i > 0; i--)
	{
		for (int j = 0; j < 999; j++)
		{
			int temp;
			if (T[j] > T[j + 1])
				temp = T[j];
			T[j] = T[j + 1];
			T[j + 1] = temp;
		}
	}
	scanf("%d", &j);
	for (int i = 0; i < 999; i++)
	{
		if (T[i] == j)
		{
			printf("%d", i);
			break;
		}
		else
		{
			if (i == 999 && T[i] != j)
				printf("s=0");
		}
	}
	system("pause");
	return 0;
}