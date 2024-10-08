#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void montecarlo(int n);
int main(void)
{
	int s,count;
	count = 0;
	scanf("%d", &s);
	srand(s);
	montecarlo(10000);
	montecarlo(100000);
	montecarlo(1000000);
	return 0;
}
void montecarlo(int n)
{
	int count=0;
	for (int i = 0; i < n; i++)
	{
		double x, y;
		x = (rand() - 16383.0) / 16383.0;
		y = (rand() - 16383.0) / 16383.0;
		if (x * x + y * y <= 1)
			count++;
	}
	printf("n=%d pi = %f\n", n, (double)count / n * 4.0);
}