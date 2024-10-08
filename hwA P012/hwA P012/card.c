#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
void realign(char a[][3]);
void swap(char*, char*);
int main(void)
{
	int count = 0;
	char card[5][3];
	for (int i = 0; i < 5; i++)
		card[i][2] = '\0';
	int flag = 0;
	while (scanf("%s", card[count]) == 1)
	{
		flag = 0;
		int a = 0;
		if ((card[count][0] == 'D' || card[count][0] == 'C' || card[count][0] == 'H' || card[count][0] == 'S') && ((isdigit(card[count][1]) && card[count][1] != '1'&& card[count][1] != '0') || card[count][1] == 'J' || card[count][1] == 'Q' || card[count][1] == 'K' || card[count][1] == 'A'|| card[count][1] == 'T')&&card[count][2]=='\0')
		{
			for (int i = 0; i < count; i++)
			{
				if (card[count][0] == card[i][0] && card[count][1] == card[i][1])
				{
					a = 1;
					break;
				}
			}
			if(a==0)
				count++;
		}
		if (count == 5)
		{
			count = 0;
			for (int i = 0; i < 5; i++)
			{
				if (card[i][1] == 'T')
					card[i][1] = ':';
				if (card[i][1] == 'J')
					card[i][1] = ';';
				if (card[i][1] == 'Q')
					card[i][1] = '<';
				if (card[i][1] == 'K')
					card[i][1] = '=';
				if (card[i][1] == 'A')
					card[i][1] = '>';
			}
			realign(card);
			if (card[0][0] == card[1][0] && card[1][0] == card[2][0] && card[2][0] == card[3][0] && card[3][0] == card[4][0])
			{
				flag = 4;
				if (card[4][1] == '>')
				{
					for (int i = 0; i < 4; i++)
					{
						if (card[i][1] == i + '2')
						{
							flag = 1;
							continue;
						}
						else
						{
							flag = 4;
							break;
						}
					}
					if (flag == 4)
					{
						for (int i = 0; i < 4; i++)
						{
							if (card[i][1] == i + ':')
							{
								flag = 1;
								continue;
							}
							else
							{
								flag = 4;
								break;
							}
						}
					}
				}
				else
				{
					for (int i = 0; i < 4; i++)
					{
						if (card[i + 1][1] - card[i][1] == 1)
						{
							flag = 1;
							continue;
						}
						else
						{
							flag = 4;
							break;
						}
					}
				}
			}
			else if (card[0][1] == card[3][1] || card[1][1] == card[4][1])
				flag = 2;
			else if ((card[0][1] == card[2][1] && card[3][1] == card[4][1]) || (card[0][1] == card[1][1] && card[2][1] == card[4][1]))
				flag = 3;
			else
			{
				if (card[4][1] == '>')
				{
					for (int i = 0; i < 4; i++)
					{
						if (card[i][1] == i + '2')
						{
							flag = 5;
							continue;
						}
						else
						{
							flag = 0;
							break;
						}
					}
					if (flag == 0)
					{
						for (int i = 0; i < 4; i++)
						{
							if (card[i][1] == i + ':')
							{
								flag = 5;
								continue;
							}
							else
							{
								flag = 0;
								break;
							}
						}
					}
				}
				else
				{
					for (int i = 0; i < 4; i++)
					{
						if (card[i + 1][1] - card[i][1] == 1)
						{
							flag = 5;
							continue;
						}
						else
						{
							flag = 0;
							break;
						}
					}
				}
				if (card[0][1] == card[2][1] || card[1][1] == card[3][1] || card[2][1] == card[4][1])
					flag = 6;
				else if ((card[0][1] == card[1][1] && card[2][1] == card[3][1]) || (card[0][1] == card[1][1] && card[3][1] == card[4][1]) || (card[1][1] == card[2][1] && card[3][1] == card[4][1]))
					flag = 7;
				else if (card[0][1] == card[1][1] || card[1][1] == card[2][1] || card[2][1] == card[3][1] || card[3][1] == card[4][1])
					flag = 8;
			}
			switch (flag)
			{
			case 0:
				puts("others");
				break;
			case 1:
				puts("straight flush");
				break;
			case 2:
				puts("four of a kind");
				break;
			case 3:
				puts("full house");
				break;
			case 4:
				puts("flush");
				break;
			case 5:
				puts("straight");
				break;
			case 6:
				puts("three of a kind");
				break;
			case 7:
				puts("two pairs");
				break;
			case 8:
				puts("pair");
				break;
			}
		}
		for (int i = 0; i < 5; i++)
			card[i][2] = '\0';
	}
	return 0;
}
void swap(char* p1, char* p2)
{
	char a = *p1;
	*p1 = *p2;
	*p2 = a;
}
void realign(char a[][3])
{
	for (int i = 4; i >= 0; i--)
	{
		for (int j = 0; j <= i; j++)
		{
			if (a[j][1] - a[i][1] > 0)
			{
				swap(&a[j][1],&a[i][1]);
			}
		}
	}
	return;
}