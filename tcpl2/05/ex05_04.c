// int strlen(char *s) /* added by RJH; source: K&R p99 */
// {
  // int n;

  // for(n = 0; *s != '\0'; s++)
  // {
    // n++;
  // }
  // return n;
// }

int strcmp(char *s, char *t) /* added by RJH; source: K&R p106 */
{
  for(;*s == *t; s++, t++)
    if(*s == '\0')
      return 0;
  return *s - *t;
}

int strend(char *s, char *t)
{
	char *bs = s;
	char *bt = t;
	
	for( ; *s; s++)
		;
	for( ; *t; t++)
		;
	for( ; *s == *t; s--,t--)
		if(t == bt || s == bs)
			break;
	if(*s == *t && t == bt && *s != '\0')
		return 1;
	else
		return 0;
}

#include <stdio.h>

int main(void)
{
  char *s1 = "some really long string.";
  char *s2 = "ng.";
  char *s3 = "ng";

  if(strend(s1, s2))
  {
	printf("The string (%s) has (%s) at the end.\n", s1, s2);
  }
  else
  {
	printf("The string (%s) doesn't have (%s) at the end.\n", s1, s2);
  }
  if(strend(s1, s3))
  {
    printf("The string (%s) has (%s) at the end.\n", s1, s3);
  }
  else
  {
    printf("The string (%s) doesn't have (%s) at the end.\n", s1, s3);
  }

  return 0;
}


