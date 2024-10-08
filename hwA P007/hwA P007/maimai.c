#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void print(int a);
int main(void)
{
	int a, b, c, na, nb, nc, ma, mb, mc, E, ea, eb, ec;
	ea = 2147483647;
	eb = 2147483647;
	ec = 2147483647;
	scanf("%d %d %d %d %d %d %d %d %d %d", &a, &b, &c, &na, &nb, &nc, &ma, &mb, &mc, &E);
	for (int i = -ma; i <= na; i++)
	{
		for (int j = -mb; j <= nb; j++)
		{
			for (int k = -mc; k <= nc; k++)
			{
				if ((i * a + j * b + k * c) == E)
				{
					if (abs(i) + abs(j) + abs(k) < ea + eb + ec)
					{
						ea = i;
						eb = j;
						ec = k;
					}
				}
			}
		}
	}
	if (ea != 2147483647)
	{
		printf("%d\n", abs(ea) + abs(eb) + abs(ec));
		print(ea);
		print(eb);
		print(ec);
	}
	else
		printf("Wrong\n");
	return 0;
}
void print(int a)
{
	if (a == 0)
		printf("not used 0\n");
	else if (a > 0)
		printf("pay %d\n", a);
	else
		printf("get %d\n", -a);
	return;
}