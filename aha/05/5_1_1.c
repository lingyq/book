/*输入数据如下
5 5
1 2
1 3
1 5
2 4
3 5
*/

#include <stdio.h>  
int book[101],sum,n,e[101][101];
void dfs(int cur)
{
	int i;
	printf("%d ",cur);
	sum++;
	if(sum==n)
		return;
	for(i=1;i<=n;i++)
	{
		if(e[cur][i]==1 && book[i]==0)
		{
			book[i]=1;
			dfs(i);
		}
	}
	return;
}

int main()  
{  
	int i,j,m,a,b=0;
    scanf("%d %d",&n,&m);
	//初始化二维矩阵
    for(i=1;i<=n;i++)   
      for(j=1;j<=n;j++)
		  if(i==j)
			  e[i][j]=0;
		  else
			  e[i][j]=99999999;
	
	//读入顶点之间的边
	for(i=1;i<=m;i++)
	{
		scanf("%d %d",&a,&b);
		e[a][b]=1;
		e[b][a]=1;//这是无向图，所以需要将e[b][a]也赋值为1
	}
	
	//从1号顶点出发
	book[1]=1;
	dfs(1);
	
	getchar();
	getchar();
    return 0;  
}