#include<stdio.h>
#include<stdlib.h>
#include<iostream>

int INF = 999999;
void Prim(int n,int MGraph[999][999], int v0, float& sum)//n->顶点数 MGraph->带权图 v0->起始点
{
	MGraph[1][2] = MGraph[2][1]= 1;
	MGraph[2][3] = MGraph[3][2] = 2;
	MGraph[3][4] = MGraph[4][3] = 5;
	MGraph[1][3] = MGraph[3][1] = 3;
	MGraph[1][4] = MGraph[4][1] = 4;
	MGraph[1][5] = MGraph[5][1] = 6;
	MGraph[3][5] = MGraph[5][3] = 7;
	int lowCost[999], vSet[999];//lowCost[a]->当前生成树到顶点a最小权值 vSet[n]=0/1 点n是否已经加入树中
	int pre[999];//记录那个点到哪个点是最短的
	int v, k, min,m;
	for (int i = 0; i < n; i++)
	{
		lowCost[i] = MGraph[v0][i];
		vSet[i] = 0;
	}
	v = v0;
	vSet[v] = 1;
	sum = 0;
	for (int i = 0; i < n - 1; i++)
	{
		min = INF;
		for(int j=0;j<n;j++)
			if (vSet[j] == 0 && lowCost[j] < min)
			{
				min = lowCost[j];
				k = j;
			}
		vSet[k] = 1;
		v = k;
		sum += min;
		for (int j = 0; j < n; j++) {
			if (vSet[j] == 0 && MGraph[v][j] < lowCost[j])
				lowCost[j] = MGraph[v][j];
			pre[v] = j;
		}
		printf("%d%d%d", v, pre[v], min);
	}
}