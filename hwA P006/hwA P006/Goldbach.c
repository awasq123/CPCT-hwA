#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main(void)
{
	unsigned int a;
	scanf("%u", &a);
	for (int i = 3; i <= a / 2; i+=2)
	{
		int m;
		int b = 0;
		int c = 0;
		for (int j = 2; j <= (int)sqrt(i); j++)
		{
			if (i % j == 0)
				b = 1;
			else
				continue;
		}
		if (b == 0)
		{
			m = a - i;
			for (int j = 2; j <= (int)sqrt(m); j++)
			{
				if (m % j == 0)
					c = 1;
				else
					continue;
			}
			if (c == 0)
				printf("%u = %d + %d\n", a, i, m);
			else
				continue;
		}
		else
			continue;
	}
	return 0;
}