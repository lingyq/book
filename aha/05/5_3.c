/*输入数据如下
5 7 1 5
1 2
1 3
2 3
2 4
3 4
3 5
4 5
*/

#include <stdio.h>  
struct note
{
	int x;
	int s;
};

int main()  
{  
	struct note que[2501];
	int e[51][51]={0},book[51]={0};
	int head,tail;
	int i,j,n,m,a,b,cur,start,end,flag=0;
    scanf("%d %d %d %d",&n,&m,&start,&end);
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
	
	//队列初始化
	head=1;
	tail=1;
	
	//从1号顶点出发，将1号顶点加入队列
	que[tail].x=start;
	que[tail].s=0;
	tail++;
	book[start]=1;
	
	//当队列不为空的时候循环
	while(head<tail && tail<=n)
	{
		cur=que[head].x;
		for(j=1;j<=n;j++)
		{
			if(e[cur][j]==1 && book[j]==0)
			{
				que[tail].x=j;
				que[tail].s=que[head].s+1;
				tail++;
				book[j]=1;
			}
			if(que[tail-1].x==end)
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
			break;
		head++;
	}
	
	printf("%d",que[tail-1].s);
	getchar();
	getchar();
    return 0;  
}