#include <stdlib.h>
#include <stdio.h>
    
void itob(int n, char s[], int b);
void reverse(char s[]);

int main(void) {
    char buffer[10];
    int i;
    
    for ( i = 2; i <= 20; ++i ) {
        itob(255, buffer, i);
        printf("Decimal 255 in base %-2d : %s\n", i, buffer);
    }
    return 0;
}

void itob(int n, char s[], int b) 
{
    int i, j, sign;
    void reverse(char s[]);

    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do {
       j = n % b; 
	   s[i++] = (j <=9) ? j+'0' : j+'a'-10;
    } while ((n /= b) > 0);
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
