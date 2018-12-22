#include <stdio.h>

int main()
{
	int i;
	// printf("_3*6528=3_*8256\n");
	for(i=1;i<=9;i++)
		if((i*10+3)*6528 == (30+i)*8256){
			printf("%d\n",i);
			printf("%d3*6528=3%d*8256\n",i,i);
		}
	return 0;
}