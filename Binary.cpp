#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
	int T[999];
	int s;
	int* p = T;
	memset(T, 0, sizeof(T));
	for (int i = 0; i < 999; i++)
	{
		scanf("%d", &T[i]);
		if (T[i] == -1)
			break;
	}
	for (int i = 999; i >0; i--)
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
	scanf("%d", &s);
	int h=0, k=999, m=499;
	while (h < k)
	{
		if (T[m] == s)
		{
			printf("%d", m);
			break;
		}
		if (T[m] < s)
		{
			h = m + 1;
			m = (h + k) / 2;
		}
		if (T[m] > s)
		{
			k = m - 1;
			m = (h + k) / 2;
		}
		else
			printf("s=0");
	}
	system("pause");
	return 0;
}