#include <ctype.h>
#include <stdio.h>

int getch(void);
void ungetch(int);

int getint(int *pn)
{
	int c, d, sign;

	while (isspace(c = getch()))   
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') 
	{
		ungetch(c);  
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
	{
		d = c;
		if(!isdigit(c = getch()))
		{
			if(c != EOF)
				ungetch(c);
			ungetch(d);
			return d;
		}
	}
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if (c != EOF)
		ungetch(c);
	return c;
}

#include <stdio.h> //重复包含头文件没问题，但是递归包含会报错

#define BUFSIZE 100

char buf[BUFSIZE];      
int bufp = 0;          

int getch(void)        
{
        return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)     
{
        if (bufp >= BUFSIZE)
                printf("ungetch: too many characters\n");
        else
                buf[bufp++] = c;
}


int main(void)
{
        int ret;

        do {
                int i;

                fputs("Enter a int number: ", stdout);
                fflush(stdout);
                ret = getint(&i);
                if (ret > 0) {
                        printf("You entered: %d\n", i);
                }
        } while (ret > 0);

        if (ret == EOF) {
                puts("Stopped by EOF.");
        } else {
                puts("Stopped by bad input.");
        }
        
        return 0;
}
