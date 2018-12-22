#include <stdio.h>

int main()
{
	int a,b,c,d;
	for(a=1;a<=4;a++)
	for(b=1;b<=4;b++)
	for(c=1;c<=4;c++)
	for(d=1;d<=4;d++)
		if(a!=b && a!=c && a!=d && b!=c && b!=d && c!=d)
			printf("%d%d%d%d\n",a,b,c,d);
	return 0;
}