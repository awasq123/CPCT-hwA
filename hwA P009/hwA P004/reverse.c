#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int my_strcmp(char* p1, char* p2);
int main(void)
{
	char c[10087];
	char d[10087];
	int length;
	scanf("%s", c);
	length = strlen(c);
	for (int i = 0; i < length ; i++)
	{
		*(d+length - i - 1) = *(c+i);
	}
	d[length] = '\0';
	if (my_strcmp(c, d) == 0)
		printf("yes");
	else
		printf("no");
	getchar();
	getchar();
	return 0;
}
int my_strcmp(char* p1, char* p2)
{
	int ret_val;
	while (*p1 != '\0' && *p2 != '\0')
	{
		if (*p1 == *p2)
		{
			p1++;
			p2++;
			continue;
		}
		else
		{
			return *p1 - *p2;
		}
	}
	return 0;
}