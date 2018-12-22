#include <ctype.h>
#include <stdio.h>


double atof(char s[])
{
    double val, power;
    int exp, i, sign;
	
	for(i = 0; isspace(s[i]); i++)
		;
	sign = (s[i] == '-') ? -1 : 1;
	if(s[i] == '+' || s[i] == '-')
		i++;
	for(val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if(s[i] = '.')
		i++;
	for(power = 1.0; isdigit(s[i]); i++)
	{
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}
	val = sign * val / power;
	
	if(s[i] == 'e' || s[i] == 'E')
	{
		sign = (s[++i] == '-') ? -1 : 1;
		if(s[i] == '+' || s[i] == '-')
			i++;
		for(exp = 0; isdigit(s[i]); i++)
			exp = 10 * exp + (s[i] - '0');
		if(sign == 1)
			while(exp-- > 0)
				val *= 10;
		else
			while(exp-- > 0)
				val /= 10;
	}
    return val;
}


char  *strings[] = {
    "1.0e43",
    "999.999",
    "123.456e-9",
    "-1.2e-3",
    "1.2e-3",
    "-1.2E3",
    "-1.2e03",
    "cat",
    "",
    0
};

char  string[] = "123.456e-9";

int main(void)
{
 // int i;  
 // for (i = 0; *strings[i]; i++)
 //     printf("atof(%s) = %g\n", strings[i], atof(strings[i]));//为什么二维数组不行？
        printf("atof(%s) = %g\n", string, atof(string));//一维数组没问题
	return 0;
}
