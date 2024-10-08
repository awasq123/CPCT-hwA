#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define length 2000
int main(void)
{
	int m = 0;
	int n = 0;
	int punct_count = 0;
	int word_count = 0;
	int word[length];
	char punct[length];
	char input[10087];
	char p[length][15];
	fgets(input,10087, stdin);
	for (int i = 0; i < strlen(input); i++)
	{
		if (input[i]==' '||input[i]=='\n')
		{
			p[m][n] = '\0';
			n = 0;
			m++;
			word_count++;
		}
		else if (input[i] == ',' || input[i] == '.' || input[i] == '?' || input[i] == '!')
		{
			punct[punct_count] = input[i];
			if (punct_count == 0)
				word[punct_count] = word_count + 1;
			else
				word[punct_count] = word_count;
			punct_count++;
			word_count = 0;
		}
		else
		{
			p[m][n] = input[i];
			n++;
		}
	}
	int a = 0;
	int b = punct_count;
	for (int i = m - 1; i >= 0; i--)
	{
		printf("%s", p[i]);
		a++;
		if (a == word[b - 1])
		{
			putchar(punct[punct_count - b]);
			b--;
			a = 0;
		}
		putchar(' ');
	}
	return 0;
}