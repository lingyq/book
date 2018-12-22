#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#define abs(x) ((x) <0 ? -(x) : (x))
//itoa在stdio里已经有实现了，所以这里改用itoaa，
//否则编译会出现警告：warning C4030: first formal parameter list longer than the second list
void itoaa(int n, char s[]);
void reverse(char s[]);

int main(void) {
    char buffer[20];
    
    printf("INT_MIN: %d\n", INT_MIN);
    itoaa(INT_MIN, buffer);
    printf("Buffer : %s\n", buffer);
    
    return 0;
}

void itoaa(int n, char s[]) 
{
    int i, sign;
	void reverse(char s[]);

    sign = n;
    i = 0;
    do 
	{
        s[i++] = abs(n % 10) + '0';
    } while ( (n /= 10) != 0 );
    if (sign < 0)
        s[i++] = '-';
    
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[])
{
  int i, j;
  char temp;

  i = 0;
  while( s[i] != '\0')
	++i;
  --i;
  if(s[i] == '\n')
	--i;
  j = 0;
  while( j < i )
  {
	temp = s[j];
	s[j] = s[i];
	s[i] = temp;
	--i;
	++j;
  }
}

