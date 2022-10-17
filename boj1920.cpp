

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
#include <stack>
#define Max(a,b) a < b ? b : a;
#define Min(a,b) a < b ? a : b;

using namespace std;

int a[100008];
int c[100008];

int find(int index,int lo, int hi)
{
	if (lo > hi)
		return 0;

	int mid = (lo + hi) / 2;

	if (c[index] == a[mid])
		return 1;

	if (c[index] < a[mid])
	{
		return find(index, lo, mid-1);
	}
	else
	{
		return find(index, mid + 1, hi);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
	}

	sort(a, a+N);

	cin >> M;
	
	for (int i = 0; i < M; i++)
	{
		cin >> c[i];
	}

	for (int i = 0; i < M; i++)
	{
		cout << find(i, 0, N - 1) << "\n";
	}

	return 0;
}

