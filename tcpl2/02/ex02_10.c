#include <stdio.h>
#include <string.h>

int lower(int c)
{
  return c >= 'A' && c <= 'Z' ? c + 'a' - 'A' : c;
}

int main(void)
{
  char *Tests = "AaBbcCD3EdFGHgIJKLhM2NOjPQRkSTlUVWfXYf0Z1";
  char *p = Tests;
  int Result = 0;  

  while('\0' != *p)
  {
    Result = lower(*p);
    printf("[%c] gives [%c]\n", *p, Result);
    ++p;
  }

  Result = lower(0);
  printf("'\\0' gives %d\n", Result); 

  return 0;
}



