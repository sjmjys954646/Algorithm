#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>
#define X first
#define Y second
using namespace std;

const int INF = 987654321;

long long cache[101];

long long padoban(int i)
{
	long long& ret = cache[i];

	if (ret != -1) return ret;

	return ret = (padoban(i - 2) + padoban(i - 3));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	memset(cache, -1, sizeof(cache));

	cache[0] = 1;
	cache[1] = 1;
	cache[2] = 1;
	
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int t;
		cin >> t;
		cout << padoban(t-1) << "\n";
	}

	return 0;
}