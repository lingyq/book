/*输入数据如下
6 7
1 4
1 3
4 2
3 2
2 5
2 6
5 6
*/

#include <stdio.h>
int n,m,e[9][9],root;
int num[9],low[9],flag[9],index;

int min(int a, int b)
{
	return a < b ? a : b;
}

void dfs(int cur, int father)
{
	int child=0,i;
	index++;
	num[cur]=index;
	low[cur]=index;
	for(i=1;i<=n;i++)
	{
		if(e[cur][i]==1)
		{
			if(num[i]==0)
			{
				child++;
				dfs(i,cur);
				low[cur]=min(low[cur],low[i]);
				if(cur!=root && low[i]>=num[cur])
					flag[cur]=1;
				if(cur==root && child==2)
					flag[cur]=1;
			}
			else if(1!=father)
			{
				low[cur]=min(low[cur],num[i]);
			}
		}
	}
	return;
}
int main()
{
	int i,j,x,y;
	scanf("%d %d",&n,&m);
	
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			e[i][j]=0;
	for(i=1;i<=m;i++)
	{
		scanf("%d %d",&x,&y);
		e[x][y]=1;
		e[y][x]=1;
	}
	root=1;
	dfs(1,root);
	for(i=1;i<=n;i++)
	{
		if(flag[i]==1)
			printf("%d",i);		
	}
	
	getchar();
	getchar();
	return 0;
}


