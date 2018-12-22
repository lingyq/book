#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void itoa(int n, char s[])
{
	static int i;
	
	if( n / 10 )
		itoa( n / 10, s);
	else
	{
		i = 0;
		if( n < 0 )
			s[i++] = '-';
	}
	s[i++] = abs(n) % 10 + '0';
	s[i] = '\0';
}

int main(void)
{
	//char s[] = "123542678";
	char s[50];
	itoa(123443,s);
	printf("%s\n",s);
	return 0;
}