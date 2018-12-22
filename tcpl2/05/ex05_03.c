void my_strcat(char *s, char *t)
{
  while(*s)
	s++;
  while(*s++ = *t++)
	;
}

#include <stdio.h>

int main(void)
{
  char S1[8192] = "String One";
  char S2[8192] = "String Two";

  printf("String one is (%s)\n", S1);
  printf("String two is (%s)\n", S2);
 
  my_strcat(S1, S2);
  printf("The combined string is (%s)\n", S1);
  return 0;
}

