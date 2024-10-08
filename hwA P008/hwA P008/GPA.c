#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
double to_gpa(int a);
int to_grade(double a);
int main(void)
{
	int count = 0;
	double gpa, a;
	int a1, a2, a3, a4, a5;
	double grade[10] = { 0,1,1.5,2,2.5,3,3.5,4,4.5,5 };
	double aaa[300];
	for (int i = 0; i < 299; i++)
		aaa[i] = 0.1;
	while (scanf("%lf", &gpa))
	{
		count = 0;
		for (int i = 0; i < 299; i++)
			aaa[i] = 0.1;
		for (a1 = 0; a1 <= 100; a1++)
		{
			for (a2 = a1; a2 <= 100; a2++)
			{
				for (a3 = a2; a3 <= 100; a3++)
				{
					for (a4 = a3; a4 <= 100; a4++)
					{
						for (a5 = a4; a5 <= 100; a5++)
						{
							if (to_gpa(a1) + to_gpa(a2) + to_gpa(a3) + to_gpa(a4) + to_gpa(a5) == gpa * 5)
							{
								a = (double)(a1 + a2 + a3 + a4 + a5) / 5;
								for (int i = 0; i < 500; i++)
								{
									if (aaa[i] == a)
										break;
									else if (aaa[i] == 0.1)
									{
										aaa[i] = a;
										count++;
										break;
									}
								}
							}
						}
					}
				}
			}
		}
		for (int i = 0; i < count; i++)
			printf("%.1f ", aaa[i]);
		putchar('\n');
	}
	return 0;
}
double to_gpa(int a)
{
	double grade[10] = { 0,1,1.5,2,2.5,3,3.5,4,4.5,5 };
	if (a < 60)
		return grade[0];
	else
		return grade[1 + (a - 60) / 5];
}
int to_grade(double a)
{
	if (a == 0)
		return 60;
	else
	{
		return (60 + ceil(2 * a - 2) * 5);
	}
}