#include <stdio.h>
#include <stdlib.h>

#define YES 1
#define NO  0

int htoi(char s[])
{
	int hexdigit, i, inhex, n;

	i = 0;
	if(s[i] == '0')
	{
		++i;
		if(s[i] == 'x' || s[i] == 'x')
			++i;
	}
	n = 0;
	inhex = YES;
	for( ; inhex == YES; ++i)
	{
		if(s[i] >= '0' && s[i] <= '9')
			hexdigit = s[i] - '0';
		else if(s[i] >= 'a' && s[i] <= 'f')
			hexdigit = s[i] - 'a' + 10;
		else if(s[i] >= 'A' && s[i] <= 'F')
			hexdigit = s[i] - 'A' + 10;
		else 
			inhex = NO;
		if(inhex == YES)
			n = 16 * n + hexdigit;
	}
		return n;
}

int main(void)
{
  char *endp = NULL;
  char *test[] =
  {
    "F00",
    "bar",
    "0100",
    "0x1",
    "0XA",
    "0X0C0BE",
    "abcdef",
    "123456",
    "0x123456",
    "deadbeef",
    "zog_c"
  };

  unsigned int result;
  unsigned int check;

  size_t numtests = sizeof test / sizeof test[0];

  size_t thistest;

  for(thistest = 0; thistest < numtests; thistest++)
  {
    result = htoi(test[thistest]);
/*******************************************************/
//函数定义：unsigned long int strtoul(const char *nptr,char **endptr,int base);
//函数说明：strtoul()会将参数nptr字符串根据参数base来转换成无符号的长整型数。
//参数base范围从2至36，或0。参数base代表采用的进制方式，如base值为10则采用10进制，若base值为16则采用16进制数等。
//当base值为0时则是采用10进制做转换，但遇到如'0x'前置字符则会使用16进制做转换。
//一开始strtoul()会扫描参数nptr字符串，跳过前面的空格字符串，直到遇上数字或正负符号才开始做转换，
//再遇到非数字或字符串结束时('')结束转换，并将结果返回。
//若参数endptr不为NULL，则会将遇到不合条件而终止的nptr中的字符指针由endptr返回。
/*******************************************************/
    check = (unsigned int)strtoul(test[thistest], &endp, 16);//strtoul函数可以参考教材230页的函数说明

    if((*endp != '\0' && result == 0) || result == check)
    {
      printf("Testing %s. Correct. %u\n", test[thistest], result);
    }
    else
    {
      printf("Testing %s. Incorrect. %u\n", test[thistest], result);
    }
  }

  return 0;
}

