#include <stdio.h>
#define NUM 10

int a[NUM], book[NUM], n;

void dfs(int step) 
{
	int i;

	if (step == n + 1) 
	{
		for (i = 1; i <= n; i++) 
			printf("%d", a[i]);

		printf("\n");
		return;
	}

	for (i = 1; i <= n; i++) 
	{
		if (book[i] == 0) 
		{
			a[step] = i;
			book[i] = 1;
			dfs(step + 1);
			book[i] = 0;
		}
	}
}

int main(void) {
	scanf("%d", &n);//输入的时候注意n为1~9之间的整数

	dfs(1);//首先站在1号小盒子前面
	getchar();
	getchar();
	return 0;
}