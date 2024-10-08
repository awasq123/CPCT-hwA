#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int a;
	scanf("%d", &a);
	for (int i = 1; i <= a; i++)
	{
		for (int j = a; j > i; j--)
			putchar(' ');
		for (int j = 1; j < i; j++)
		{
			printf("%d ", i);
		}
		printf("%d", i);
		putchar('\n');
	}
	for (int i = a - 1; i > 0; i--)
	{
		for (int j = a; j > i; j--)
			putchar(' ');
		for (int j = 1; j < i; j++)
		{
			printf("%d ", i);
		}
		printf("%d", i);
		putchar('\n');
	}
	return 0;
}