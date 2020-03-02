#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
typedef struct
{
	int s;//�ߵ���ʼ����
	int e;//�ߵ���ʼ�յ�
	int w;//�ߵ�Ȩֵ
}Edge;

void  Bubblesort(Edge R[], int e)//ð��
{
	Edge temp;
	int i, j, swap;
	for (i = 0; i < e - 1; i++)
	{
		swap = 0;
		for (j = 0; j < e - i - 1; j++)
			if (R[j].w > R[j + 1].w)
			{
				temp = R[j]; R[j] = R[j + 1]; R[j + 1] = temp;
				swap = 1;
			}
		if (swap == 0) break;
	}
}

void Kruskal(int MGraph[999][999], int n)
{
	memset(MGraph, 0x3f3f3f3f, sizeof(int));
	MGraph[1][2] = MGraph[2][1] = 1;
	MGraph[2][3] = MGraph[3][2] = 5;
	MGraph[3][1] = MGraph[1][3] = 6;
	MGraph[1][4] = MGraph[4][1] = 5;
	MGraph[2][4] = MGraph[4][2] = 5;
	MGraph[2][5] = MGraph[5][2] = 6;
	MGraph[3][5] = MGraph[5][3] = 3;
	MGraph[4][6] = MGraph[6][4] = 2;
	MGraph[2][6] = MGraph[6][2] = 4;
	MGraph[5][6] = MGraph[6][5] = 6;
	int i, j, s1, e1, sn1, sn2, k;
	int vest[999];//����vest���ж�������֮���Ƿ���ͨ
	Edge E[999];
	k = 0;
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			if (i < j && MGraph[i][j] != 0x3f3f3f3f)
			{
				E[k].s = i;
				E[k].e = j;
				E[k].w = MGraph[i][j];
				k++;
			}
	Bubblesort(E, k);
	for (i = 1; i <= n; i++)
		vest[i] = i;
	k = 1;//k��ʾ��ǰ�����������ĵ�n���ߣ���ʼֵΪ1
	j = 0;//jΪ����E��Ԫ�ص��±꣬��ֵΪ0
	while (k < n)//������С��������n-1����
	{
		s1 = E[j].s; e1 = E[j].e;//ȡһ���ߵ�ͷβ����
		sn1 = vest[s1];
		sn2 = vest[e1];//�ֱ�õ����������������ļ��ϱ��
		if (sn1 != sn2)
		{
			k++;//���ɵı�����1
			for (i = 1; i <= n; i++)//��������ͳһ���
				if (vest[i] == sn2)//���ϱ��Ϊsn2�ĵ�i�ű���ߺŸ�Ϊsn1
					vest[i] = sn1;
		}
		j++;//ɨ����һ����
	}
}