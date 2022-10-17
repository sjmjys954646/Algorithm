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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int num;

	cin >> num;

	vector<int> vec;
	stack<pair<int, int> > s;

	for (int i = 0; i < num; i++)
	{
		int tmp;
		cin >> tmp;
		vec.push_back(tmp);
	}
	long long ans = 0;

	for (int i = 0; i < num; i++)
	{
		int idx = i;
		while (!s.empty() && s.top().first >= vec[i])
		{
			ans = Max(ans, 1LL * (i - s.top().second) * s.top().first);
			idx = s.top().second;
			s.pop();
		}
		s.push({ vec[i],idx });
	}
	while (!s.empty())
	{
		ans = Max(ans, 1LL * (num - s.top().second) * s.top().first);
		s.pop();
	}
	cout << ans << "\n";

	return 0;
}