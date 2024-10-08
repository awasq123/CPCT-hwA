#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void)
{
	int n;
	unsigned long long s = 1;
	unsigned long long a = 0;
	unsigned long long max;
	scanf("%d", &n);
	scanf("%llu", &max);
	for (int i = 1; i <= n; i++)
	{
		s = s * i;
		a = a + s;
	}
	if ( a > max || n >= 22)
		printf("overflow");
	else
		printf("%llu", a);
}