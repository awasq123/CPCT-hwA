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
	char p[length][15];
	int i = 0;
	while (scanf("%s", p[i]) == 1) 
	{
		word_count++;
		if (p[i][strlen(p[i])-1] == ',' || p[i][strlen(p[i])-1] == '.' || p[i][strlen(p[i])-1] == '?' || p[i][strlen(p[i])-1] == '!')
		{
			punct[punct_count] = p[i][strlen(p[i])-1];
			p[i][strlen(p[i])-1] = '\0';
			word[punct_count] = word_count;
			punct_count++;
			word_count = 0;
		}
		i++;
		if (getchar() == '\n')
			break;
	}
	int a = 0;
	int b = punct_count;
	for (int z = i - 1; z >= 0; z--)
	{
		printf("%s", p[z]);
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