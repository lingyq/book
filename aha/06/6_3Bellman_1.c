/*输入数据如下
5 5
2 3 2
1 2 -3
1 5 5
4 5 2
3 4 3
*/
#include <stdio.h>

int main()
{
	int dis[10],i,k,n,m,u[10],v[10],w[10];
	int inf=99999999;
	scanf("%d %d",&n,&m);
	
	for(i=1;i<=m;i++)
		scanf("%d %d %d",&u[i],&v[i],&w[i]);
	
	for(i=1;i<=n;i++)
		dis[i]=inf;
	dis[1]=0;
	
	//Bellman-Ford核心算法语句
	for(k=1;k<=n-1;k++)
		for(i=1;i<=m;i++)
			if(dis[v[i]] > dis[u[i]] + w[i])
			   dis[v[i]] = dis[u[i]] + w[i];
	for(i=1;i<=n;i++)
		printf("%d ",dis[i]);
	
    getchar();  
    getchar();  
    return 0;  
}
