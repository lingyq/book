void squeeze(char s1[], char s2[])
{
  int i, j, k;

  for(i = k = 0; s1[i] != '\0'; i++)
  {
    for(j = 0; s2[j] != '\0' && s2[j] != s1[i]; j++)
	  ;
	if(s2[j] == '\0')
        s1[k++] = s1[i];
  }
  s1[k] = '\0';
}


/* test driver */

#include <stdio.h>
#include <string.h>

int main(void)
{
  char *leftstr[] =
  {
	"http://nic.dgut.edu.cn/",
	"my name is ling yu quan",
	"tel:15816829247",
	"qq:1349589296",
  };
  char *rightstr[] =
  {
	"123_go",
    "windows",
    "and",
    "linux"
  };

  char buffer[32];
  size_t numlefts = sizeof leftstr / sizeof leftstr[0];
  size_t numrights = sizeof rightstr / sizeof rightstr[0];
  size_t left = 0;
  size_t right = 0;

  for(left = 0; left < numlefts; left++)
  {
    for(right = 0; right < numrights; right++)
    {
      strcpy(buffer, leftstr[left]);

      squeeze(buffer, rightstr[right]);

      printf("[%s] - [%s] = [%s]\n", leftstr[left], rightstr[right], buffer);
    }
  }
  return 0;
}

