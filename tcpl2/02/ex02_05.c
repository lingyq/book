/*
在stdio.h中默认定义了size_t,位于69-72行:
#ifndef _SIZE_T_DEFINED
typedef unsigned int size_t;
#define _SIZE_T_DEFINED
#endif
*/
int any(char s1[], char s2[])
{
  int i, j;

  for(i = 0; s1[i] != '\0'; i++)
  {
    for(j = 0; s2[j] != '\0'; j++)
    {
      if(s1[i] == s2[j])
      {
       return i;
      }
    } 
  }
  return -1;
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
	"456"
  };
  char *rightstr[] =
  {
	"123_go",
    "windows",
    "and",
    "linux"
  };

  size_t numlefts = sizeof leftstr / sizeof leftstr[0];
  size_t numrights = sizeof rightstr / sizeof rightstr[0];
  size_t left = 0;
  size_t right = 0;

  int passed = 0;
  int failed = 0;

  int pos = -1;
  char *ptr = NULL;

  for(left = 0; left < numlefts; left++)
  {
    for(right = 0; right < numrights; right++)
    {
      pos = any(leftstr[left], rightstr[right]);
      ptr = strpbrk(leftstr[left], rightstr[right]);

      if(-1 == pos)
      {
        if(ptr != NULL)
        {
          printf("Test %ld/%ld failed.\n", left, right);
          ++failed;
        }
        else
        {
          printf("Test %ld/%ld passed.\n", left, right);
          ++passed;
        }
      }
      else
      {
        if(ptr == NULL)
        {
          printf("Test %ld/%ld failed.\n", left, right);
          ++failed;
        }
        else
        {
          if(ptr - leftstr[left] == pos)
          {
            printf("Test %ld/%ld passed.\n", left, right);
            ++passed;
          }
          else
          {
            printf("Test %ld/%ld failed.\n", left, right);
            ++failed;
          }
        }
      }
    }
  }
  printf("\n\nTotal passes %d, fails %d, total tests %d\n",
         passed,
         failed,
         passed + failed);
  return 0;
}
//32位平台size_t是unsigned long，64位平台size_t是unsigned long long，其数值范围都超过int，不会损失精度，故不会警告。反之则会。
//这里的%ld改为%ld可避免警告


