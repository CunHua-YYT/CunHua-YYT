#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#define MAX 100

int a[MAX], b[MAX];
void merge(int low, int mid, int high)
{
	int i = low, j = mid + 1, k = low;
	while (i <= mid && j <= high)
		if (a[i] < a[j])
			b[k++] = a[i++];
		else
			b[k++] = a[j++];
	while (i <= mid)
		b[k++] = a[i++];
	while (j <= high)
		b[k++] = a[j++];
	for (i = low; i <= high; i++) {
		a[i] = b[i];
		printf("%d",a[i]);
	}
	printf("/n");
}

void mergeSort(int a, int b) {
	if (a < b) {
		int mid = (a + b) / 2;
		mergeSort(a, mid);
		mergeSort(mid + 1, b);
		merge(a, mid, b);
	}
}