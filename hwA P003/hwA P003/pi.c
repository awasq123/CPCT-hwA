#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main(void)
{
	int n;
	scanf("%d", &n);
	double pi,pi1;
	pi = 0;
	pi1 = 10;
	int k = 0;
	do
	{
		pi1 = pi;
		pi += pow(16, -k) * ((double)4 / (8*k + 1)-(double)2/(8*k+4)-(double)1/(8*k+5)-(double)1 / (8 * k + 6));
		k++;
	} while ((pi / (pi1 + 0.00000000000000001) - 1) > (double)pow(10, -n));
	pi = floor(pi1 * pow(10, n - 1));
	pi1 = (double)pi * pow(10, 1 - n);
	printf("%.*lf", n-1,pi1);
}