#include <stdio.h>
#define MAXLINE  1000
#define LONGLINE 10 //取值小一点，更容易观察
int Getline(char line[], int maxline);

int main(void) 
{
    int len;
    char line[MAXLINE];

    while ( (len = Getline(line, MAXLINE)) > 0 )
    {
        if (len > LONGLINE)
        {
            printf("%s",line);
        }
    }

    return 0;
} 

int Getline(char s[], int lim)
{
    int c, i, j;

    j = 0;
    for(i = 0; (c = getchar())!=EOF && c != '\n'; ++i)
    {
        if(i < lim - 2)
        {
            s[j] = c;
            ++j;
        }
    }
    if(c == '\n')
    {
        s[j] = c;
        ++j;
        ++i;
    }
    s[j] = '\0';

    return i;
}

