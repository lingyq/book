#include <stdio.h>
#include <stdlib.h>
#define swap(t, x, y) { t _z;\
						_z = y;\
						y = x;\
						x = _z;}

int main(void)
{
	char  a1 = 7,b1 = 8;
	int   a2 = 3,b2 = 4;
	float a3 = 5,b3 = 6;
	printf("before call swap(t,a,b) : a1 = %c,b1 = %c,a2 = %d,b2 = %d,a3 = %g,b3 = %g\n",a1,b1,a2,b2,a3,b3);
	swap(char,a1,b1);
	swap(int,a2,b2);
	swap(float,a3,b3);
	printf(" after call swap(t,a,b) : a1 = %c,b1 = %c,a2 = %d,b2 = %d,a3 = %g,b3 = %g\n",a1,b1,a2,b2,a3,b3);
	return 0;
}
//为什么 char 类型的打印值为ASIIC码？ ASIIC中7为一声短鸣，8为不可打印字符