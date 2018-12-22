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
//�������壺unsigned long int strtoul(const char *nptr,char **endptr,int base);
//����˵����strtoul()�Ὣ����nptr�ַ������ݲ���base��ת�����޷��ŵĳ���������
//����base��Χ��2��36����0������base������õĽ��Ʒ�ʽ����baseֵΪ10�����10���ƣ���baseֵΪ16�����16�������ȡ�
//��baseֵΪ0ʱ���ǲ���10������ת������������'0x'ǰ���ַ����ʹ��16������ת����
//һ��ʼstrtoul()��ɨ�����nptr�ַ���������ǰ��Ŀո��ַ�����ֱ���������ֻ��������Ųſ�ʼ��ת����
//�����������ֻ��ַ�������ʱ('')����ת��������������ء�
//������endptr��ΪNULL����Ὣ����������������ֹ��nptr�е��ַ�ָ����endptr���ء�
/*******************************************************/
    check = (unsigned int)strtoul(test[thistest], &endp, 16);//strtoul�������Բο��̲�230ҳ�ĺ���˵��

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

