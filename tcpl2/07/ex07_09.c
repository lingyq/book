#include <stdio.h>
int is_upper(char c)
{
    if(c >= 'A' && c <= 'Z')
		return 1;
	else
		return 0;
}
int main(void)
{
	char a;
	scanf("%c",&a);
	if(is_upper(a)) 
		//printf("the input is %c,in A to Z\n",&a);//分析这种情况的输出结果 
        printf("the input is %c,in A to Z\n",a);
	else  
		printf("the input is %c,not in A to Z\n",a);
	return 0;
}


