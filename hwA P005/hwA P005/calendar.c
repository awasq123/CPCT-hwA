#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main(void)
{
	int year, month, day,days;
	int k = 1;
	int i = 0;
	int j;
	int month_day[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int month_day_special[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	scanf("%d %d", &year, &month);
	char calendar[11][28];
	memset(calendar, ' ', sizeof(calendar));
	for (int i = 0; i < 11; i++)
		calendar[i][27] = '\0';
	day = (year - 2000 + (year - 2000) / 4-(year-2000)/100+(year-2000)/400+6+7*100) % 7;
	if (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0))
	{
		if (year > 2000)
			day++;
		for (int i = 0; i < month-1; i++)
			day += month_day[i] % 7;
		days = month_day[month - 1];
	}
	else
	{
		for (int i = 0; i < month-1; i++)
			day += month_day_special[i] % 7;
		days = month_day_special[month - 1];
	}
	j = ((day) * 4 + 1) % 28;
	char number[50][4] ={"####","#  #","#  #","#  #","####","   #","   #","   #","   #","   #",
		"####","   #","####","#   ","####","####","   #","####","   #","####",
		"#  #","#  #","####","   #","   #","####","#   ","####","   #","####",
		"####","#   ","####","#  #","####","####","   #","   #","   #","   #",
	    "####","#  #","####","#  #","####","####","#  #","####","   #","####"};
	for (int i = 1; i <= 5; i++)
	{
		for (int j = 7; j <= 10; j++)
		{
			calendar[i][j] = number[(month / 10)*5+i-1][j - 7];
		}
		for (int j = 15; j <= 18; j++)
		{
			calendar[i][j] = number[(month % 10) * 5 + i - 1][j - 15];
		}
	}
	while (k <=days)
	{
		if(k<10)
		    calendar[i][j] = '0'+(k-0);
		else
		{
			calendar[i][j - 1] = '0'+k / 10-0;
			calendar[i][j] = '0'+k % 10-0;
		}
		j += 4;
		k++;
		if (j > 27)
		{
			j = 1;
			i+=2;
		}
	}
	printf("Sun Mon Tue Wed Thu Fri Sat\n");
	for (int i = 0; i < 11; i++)
	{
		puts(calendar[i]);
	}
}