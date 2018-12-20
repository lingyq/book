#include <stdio.h>  

int main(void)
{
	printf("\033[43;35;5mabc\033[0m\n");
	printf("\33[43m\33[35m\33[5mabc\33[0m\n");
	printf("\033[1m\33[7mabc\033[0m\n");
	return 0;
}