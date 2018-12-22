/*输入数据如下
10 10 6 8
1 2 1 0 0 0 0 0 2 3
3 0 2 0 1 2 1 0 1 2
4 0 1 0 1 2 3 2 0 1
3 2 0 0 0 1 2 4 0 0
0 0 0 0 0 0 1 5 3 0
0 1 2 1 0 1 5 4 3 0
0 1 2 3 1 3 6 2 1 0
0 0 3 4 8 9 7 5 0 0
0 0 0 3 7 8 6 0 1 2
0 0 0 0 0 0 0 0 1 0
*/
//广搜  
#include <stdio.h>  
int a[51][51];
int book[51][51],n,m,sum;
void dfs(int x, int y, int color)
{
	int next[4][2]={
	{0,1},//向右走
	{1,0},//向下走
	{0,-1},//向左走
	{-1,0},//向上走 
    };
	
	int k,tx,ty;
	a[x][y]=color; //对a[x][y]这个格子进行染色
	for(k=0;k<=3;k++)
	{
		tx=x+next[k][0];  
		ty=y+next[k][1];  
		if(tx<1 || tx>n || ty<1 || ty>m)
			continue;
		// if(a[tx][ty]==0 && book[tx][ty]==0)
		if(a[tx][ty]>0 && book[tx][ty]==0)
		{
			sum++;
			book[tx][ty]=1;
			dfs(tx,ty,color);
		}
	}
	return;
}

int main()  
{  
	int i,j,num=0;
    scanf("%d %d",&n,&m);  
    for(i=1;i<=n;i++)   
      for(j=1;j<=m;j++)  
        scanf("%d",&a[i][j]);  
	
	//对每一个大于0的点尝试进行dfs染色
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(a[i][j]>0)
			{
				num--;
				book[i][j]=1;
				dfs(i,j,num);
			}
		}
	}
	
	//输出染色后的地图
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			printf("%3d",a[i][j]); //%3d中的3是C语言中的场宽
		}
		printf("\n");
	}
	
	printf("有%d个小岛\n",-num);  
	getchar();
	getchar();
    return 0;  
}