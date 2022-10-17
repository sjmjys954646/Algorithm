#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <stdio.h>
#include <string>
#include<string.h>
#include <math.h>
#include <map>
#include <queue>
#define Max(a,b) a < b ? b : a;
#define Min(a,b) a < b ? a : b;

using namespace std;

int heapsize = 0;
int h[100001];

void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void push(int data)
{
	h[++heapsize] = data;

	int child = heapsize;
	int parent = heapsize / 2;
	while (child > 1 && h[parent] > h[child])
	{
		swap(&h[child], &h[parent]);
		child = parent;
		parent = child / 2;
	}
}

int del()
{
	int ret = h[1];

	swap(&h[1], &h[heapsize]);
	heapsize--;

	int parent = 1;
	int child = parent * 2;

	if (child + 1 <= heapsize)
	{
		child = h[child] < h[child + 1] ? child : child + 1;
	}

	while (child <= heapsize && h[parent] > h[child])
	{
		swap(&h[child], &h[parent]);

		parent = child;
		child = child * 2;
		

		if (child + 1 <= heapsize)
		{
			child = h[child] < h[child + 1] ? child : child + 1;
		}
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;

	cin >> N;


	for (int i = 0; i < N; i++)
	{
		int o;
		cin >> o;
		
		if (o == 0)
		{
			if (heapsize == 0)
			{
				cout << "0\n";
			}
			else
			{
				cout << del() << "\n";
			}
		}
		else
		{
			push(o);
		}
	}
	
	return 0;
}
