#include <stdio.h>
#include <string.h>

void strn_cpy(char *s, char *t, int n)
{
	while(*t && n-- > 0)
		*s++ = *t++;
	while(n-- > 0)
		*s++ = '\0';
}

void strn_cat(char *s, char *t, int n)
{
	void strn_cpy(char *s, char *t, int n);
	
	strn_cpy(s+strlen(s), t, n);
}

int strn_cmp(char *s, char *t, int n)
{
	for( ; *s == *t; s++, t++)
		if(*s == '\0' || --n <= 0)
			return 0;
	return *s - *t;
}

int main(void)
{
/*
	char s1[] = "abc";
	char s2[] = "def";
	char s3[] = "hijk";
	char s4[] = "lmnl";
	char s5[] = "opq";
	char s6[] = "rst";
*/
	char s1[4] = "abc";
	char s2[4] = "def";
	char s3[10] = "hijk";
	char s4[10] = "lmnl"; //要注意s3和s4的数组长度问题，上面的数组不够大，结果会出现输出乱码
	char s5[4] = "opq";
	char s6[4] = "rst";
	strn_cpy(s1,s2,2);
	printf("after strn_cpy(s1,s2,1) : s1 = %s,s2 = %s\n",s1,s2);
	strn_cat(s3,s4,2);
	printf("after strn_cat(s3,s4,2) : s3 = %s,s4 = %s\n",s3,s4);
	strn_cat(s5,s6,3);
	printf("after strn_cmp(s5,s6,3)  : s3 = %s,s4 = %s\n",s5,s6);
	return 0;
}

