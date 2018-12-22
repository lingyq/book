/*输入数据如下
13 13 3 3
#############
#GG.GGG#GGG.#
###.#G#G#G#G#
#.......#..G#
#G#.###.#G#G#
#GG.GGG.#.GG#
#G#.#G#.#.#.#
##G...G.....#
#G#.#G###.#G#
#...G#GGG.GG#
#G#.#G#G#.#G#
#GG.GGG#G.GG#
#############
*/

//深搜  
#include <stdio.h>
char a[20][21];
int book[20][20],max,mx,my,n,m;

int getnum(int i,int j)//得到此点放炸弹消灭的敌人数  
{  
    int sum,x,y;  
    sum=0;
	
    //向上统计  
    x=i; y=j;  
    while(a[x][y]!='#'){  
        if(a[x][y]=='G')  
            sum++;  
        x--;  
    }
	
    //向下统计  
    x=i; y=j;  
    while(a[x][y]!='#'){  
        if(a[x][y]=='G')  
            sum++;  
        x++;  
    }
	
    //向左统计  
    x=i; y=j;  
    while(a[x][y]!='#'){  
        if(a[x][y]=='G')  
            sum++;  
        y--;  
    }  
    //向右统计  
    x=i; y=j;  
    while(a[x][y]!='#'){  
        if(a[x][y]=='G')  
            sum++;  
        y++;  
    }  
    return sum;  
}  

void dfs(int x, int y)
{
	int next[4][2]={
	{0,1},//向右走
	{1,0},//向下走
	{0,-1},//向左走
	{-1,0},//向上走 
    };
	
	int k,sum,tx,ty;
	sum=getnum(x,y);
	if(sum>max)
	{
		max=sum;
		mx=x;
		my=y;
	}
	
	for(k=0;k<=3;k++)
	{
		tx=x+next[k][0];  
		ty=y+next[k][1];  
		if(tx<1 || tx>n-1 || ty<0 || ty>m-1)
			continue;
		// if(a[tx][ty]==0 && book[tx][ty]==0)
		if(a[tx][ty]=='.' && book[tx][ty]==0)
		{
			book[tx][ty]=1;
			dfs(tx,ty);
		}
	}
	return;
}

int main()  
{  
	int i,startx,starty;
	
    scanf("%d %d %d %d",&n,&m,&startx,&starty);  

    for(i=0;i<=n-1;i++)  
       scanf("%s",a[i]);  

	book[startx][starty]=1;
	max=getnum(startx,starty);
	mx=startx;  
	my=starty;  
	dfs(startx,starty);

	printf("将炸弹放置在(%d,%d)处，可以消灭%d个敌人\n",mx,my,max);
    getchar();
    getchar();
	return 0;
}  
