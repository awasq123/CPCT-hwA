#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
struct number {
	int num;
	struct number* next;
};
int main(void)
{
	int n,a,b;
	scanf("%d", &n);
	struct number* head,* current,* pre,*p;
	head=(struct number*)malloc(sizeof(struct number));
	for (int i = 0; i < n; i++)
	{
		b = 0;
		current=head;
		pre = head;
		scanf("%d", &a);
		if (i == 0 && head)
		{
			head->num = a;
			head->next = NULL;
		}
		else
		{
			if (head->num >= a && head)
			{
				head= (struct number*)malloc(sizeof(struct number));
				head->num = a;
				head->next = current;
			}
			else
			{
				while (current->num <= a && current)
				{
					if (current->next == NULL)
					{
						b = 1;
						break;
					}
					current = current->next;
				}
				if (b == 0)
				{
					while (pre->next != current && pre)
					{
						pre = pre->next;
					}
					p = (struct number*)malloc(sizeof(struct number));
					if (p)
					{
						p->num = a;
						pre->next = p;
						p->next = current;
					}
				}
				else if (b == 1)
				{
					p = (struct number*)malloc(sizeof(struct number));
					p->num = a;
					current->next = p;
					p->next = NULL;
				}
			}
		}
		current = head;
		while (current != NULL)
		{
			printf("%d ", current->num);
			current = current->next;
		}
		putchar('\n');
	}
	current = head;
	pre = head;
	while (current != NULL)
	{
		current = current->next;
		free(pre);
		pre = current;
	}
	return 0;
}
