#include <stdio.h>
#include <string.h>

void expand(char s1[], char s2[]);

int main(void) 
{
    char *s[] = { "a-z-", "z-a-", "-1-6-",
                  "a-ee-a", "a-R-L", "1-9-1",
                  "5-5", NULL };
    char result[100];
    int i = 0;
    
    while ( s[i] ) 
	{
        expand(result, s[i]);
        printf("Unexpanded: %s\n", s[i]);
        printf("Expanded  : %s\n", result);
        ++i;
    }
    
    return 0;
}

void expand(char s1[], char s2[]) 
{
    char c;
    int i, j;

	i = j = 0;
    while ((c = s1[i++]) != '\0') 
	  if(s1[i] == '-' && s1[i+1] >= c)
	  {
		i++;
		while(c < s1[i])
		  s2[j++] = c++;
	  }
	  else
		s2[j++] = c;
	s2[j] = '\0';
}



