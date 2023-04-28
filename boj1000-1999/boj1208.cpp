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
using namespace std;

int N, S, half, sum;
int arr[41];
long long ans = 0;
map<int, int> m;

void dfs(int idx)
{
	if (idx == half)
	{
		auto it = m.find(sum);
		if (it != m.end())
			it->second++;
		else
			m[sum] = 1;
		return;
	}
	dfs(idx + 1);
	sum += arr[idx];
	dfs(idx + 1);
	sum -= arr[idx];
}

void dfs2(int idx)
{
	if (idx == N)
	{
		auto it = m.find(S - sum);
		if (it != m.end())
			ans += it->second;
		
		return;
	}
	dfs2(idx + 1);
	sum += arr[idx];
	dfs2(idx + 1);
	sum -= arr[idx];
}

int main()
{
	scanf("%d %d", &N, &S);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}

	half = N / 2;

	dfs(0);
	dfs2(half);

	if (S == 0)
		ans--;

	printf("%lld", ans);

	return 0;
}