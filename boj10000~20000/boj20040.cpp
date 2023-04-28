#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <math.h>
#include <cstdlib>
#include <utility>
#include <map>
#include <cstdio>
#include <string>
using namespace std;

int par[500001];

int find(int a)
{
	if (par[a] == a)
		return a;
	return par[a] = find(par[a]);
}

void merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a != b)
	{
		par[a] = b;
	}
}

int main()
{
	int n, m;
	int ans = -1;
	bool sel = false;

	cin >> n >> m;

	for (int i = 1; i <= 500000; i++)
	{
		par[i] = i;
	}

	for (int i = 0; i < m; i++)
	{
		int p, q;
		cin >> p >> q;

		int tp = find(p);
		int tq = find(q);
		if (tp == tq && !sel)
		{
			ans = i + 1;
			sel = true;
			break;
		}
		merge(p, q);
	}

	if (ans == -1)
		ans = 0;
	cout << ans;

	return 0;
}