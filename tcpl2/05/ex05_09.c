#include <stdio.h>

static char daytab[2][13] =  {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

int day_of_year(int year, int month, int day)
{
	int leap;
	char *p;
	
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	p = daytab[leap];
	while(--month)
		day += *++p;
	return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int leap;
	char *p;
	
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	p = daytab[leap];
	while(yearday > *++p)
		yearday -= *p;
	*pmonth = p - *(daytab + leap);
	*pday = yearday;
}


int main(void)
{
	int month,day;
	printf("day_of_year(2013,1,1) is %d\n",day_of_year(2013,1,1));
	printf("day_of_year(2013,3,1) is %d\n",day_of_year(2013,3,1));
	month_day(1988,60,&month,&day);
	printf("60 is %d month %d day of 1988\n",month,day);
	return 0;
}
