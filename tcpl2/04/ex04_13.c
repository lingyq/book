//¿É²Î¿¼Á·Ï°1-19
#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 1000

int Getline(char line[], int maxline);
void reverse(char s[]);

int main(void)
{
  char line[MAXLINE];

  while ( Getline(line, MAXLINE) > 0 ) 
  {
	reverse(line);
	printf("%s",line);
  }
  return 0;
}

/*
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
*/
#include <string.h>
void reverse(char s[])
{
	void reverser(char s[], int i, int len);
	
	reverser(s, 0, strlen(s));
}

void reverser(char s[], int i, int len)
{
  int c, j;

  j = len - (i + 1);
  if(i < j)
  {
	c = s[i];
	s[i] = s[j];
	s[j] = c;
	reverser(s, ++i, len);
  }
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




