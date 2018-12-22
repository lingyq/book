/* 
炸弹人：计算出哪个位置的炸弹能炸到最多的人(本题有例外情况，需要优化)  
*/  

/*输入的团如下，可直接复制粘贴

13 13
#############
#GG.GGG#GGG.#
###.#G#G#G#G#
#.......#..G#
#G#.###.#G#G#
#GG.GGG.#.GG#
#G#.#G#.#.###
##G...G.....#
#G#.#G###.#G#
#...G#GGG.GG#
#G#.#G#G#.#G#
#GG.GGG#G.GG#
#############

*/
#include<stdio.h>  
int main()  
{  
	char a[20][21];  
	int i,j,sum,map=0,p,q,x,y,n,m;  

	scanf("%d %d",&n,&m);//n表示行字符数  
	for(i=0;i<=n-1;i++)  
		scanf("%s",a[i]); //读入n行字符   

	for(i=0;i<=n-1;i++)  
	{  
		for(j=0;j<=m-1;j++)  
		{  
			if(a[i][j]=='.') //判断可放置炸弹的位置  
			{  
				sum=0;  
				x=i;y=j;  
				while(a[x][y]!='#') //不是墙  
				{  
					if(a[x][y]=='G') //是敌人  
						sum++;  
					x--; //向上移一位  
				}  

				x=i;y=j;  
				while(a[x][y]!='#')  
				{  
					if(a[x][y]=='G')  
						sum++;  
					x++; //下移  
				}  

				x=i;y=j;  
				while(a[x][y]!='#')  
				{  
					if(a[x][y]=='G')  
						sum++;  
					y--; //左移  
				}  

				x=i;y=j;  
				while(a[x][y]!='#')  
				{  
					if(a[x][y]=='G')  
						sum++;  
					y++; //右移  
				}  

				if(sum>map) //更新map的值   
				{  
					map=sum;  
					//p、q标记当前点坐标   
					p=i;  
					q=j;  
				}  
			}  
		}  
	}  
	printf("放置的位置[%d,%d],消灭的敌人数量%d",p,q,map);  
	getchar();getchar();  
	return 0;  
}  