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

int N, C, ans, arr[33];
vector<int> v1, v2;

void dfs(int start, int end, int sum, vector<int>& v)
{
	if (sum > C)
		return;
	if (start > end)
		return v.push_back(sum);
	dfs(start + 1, end, sum, v);
	dfs(start + 1, end, sum + arr[start], v);
}

int main()
{
	scanf("%d %d", &N, &C);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}

	dfs(0, N / 2 - 1, 0, v1);
	dfs(N / 2 ,N-1, 0, v2);
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	int tmp = v2.size() - 1;

	for (int i = 0; i < v1.size(); i++)
	{
		while (tmp >= 0 && v1[i] + v2[tmp] > C)
			tmp--;
		ans += tmp + 1;
	}


	printf("%d", ans);

	return 0;
}