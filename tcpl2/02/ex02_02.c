#include <stdio.h>

#define MAX_STRING_LENGTH 100

int main(void)
{
	int i ,
	lim = MAX_STRING_LENGTH,
	c;
	char s[MAX_STRING_LENGTH];
	/*
	for (i = 0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
	s[i] = c;
	*/
	enum loop { NO, YES };
	enum loop okloop = YES;

	i = 0;
	while(okloop == YES)
	{
		if(i > lim-1)
		{
			okloop = NO;
		}
		else if((c = getchar()) == '\n')
		{
			okloop = NO;
		}
		else if(c == EOF)
		{
			okloop = NO;
		}
		else
		{
			s[i] = c;
			++i;
		}
	}
	s[i] = '\0';   /* terminate the string */
	for(i = 0; s[i] != '\0'; i++)
	{
		putchar(s[i]) ;
	}
	putchar('\n') ;

	return 0;
}

