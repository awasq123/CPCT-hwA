#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
void merge(int* p1, int* p2, int start, int mid, int end);
void mergesort(int* p1, int* p2, int start, int end);
int main(void)
{
	int n, opt;
	scanf("%d %d", &n, &opt);
	int* p1 = (int*)malloc(n * sizeof(int));
	int* p2 = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		scanf("%d", p1 + i);
	}
	mergesort(p1, p2, 0, n - 1);
	if (opt == 0)
	{
		for (int i = 0; i < n; i++)
			printf("%d ", *(p1 + i));
	}
	else if (opt == 1)
	{
		for (int i = n - 1; i >= 0; i--)
			printf("%d ", *(p1 + i));
	}
	free(p1);
	free(p2);
	return 0;
}
void merge(int* p1, int* p2, int start, int mid, int end)
{
	int i = start;
	int j = mid + 1;
	int k = start;
	while (i < mid+1 && j < end+1)
	{
		if (*(p1 + i) <= *(p1 + j))
		{
			*(p2 + k) = *(p1 + i);
			i++;
		}
		else
		{
			*(p2 + k) = *(p1 + j);
			j++;
		}
		k++;
	}
	if (i == mid+1)
	{
		while (k <= end)
		{
			*(p2 + k) = *(p1 + j);
			k++; 
			j++;
		}
	}
	else if (j == end+1)
	{
		while (k <= end)
		{
			*(p2 + k) = *(p1 + i);
			k++;
			i++;
		}
	}
	for (int i = start; i <= end; i++)
		*(p1 + i) = *(p2 + i);
	return;
}
void mergesort(int* p1, int* p2, int start,int end)
{
	if (start < end)
	{
		mergesort(p1, p2, start, start+(end-start) / 2);
		mergesort(p1, p2, start + (end - start) / 2+1, end);
		merge(p1, p2, start, (start + end) / 2, end);
	}
	return;
}