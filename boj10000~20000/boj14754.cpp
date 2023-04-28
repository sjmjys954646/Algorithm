// freopen("input.txt", "r", stdin);
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <cstring>
#include <list>
#include <set>
#include <string.h>
#include <map>
#include <limits.h>
#include <stdlib.h>
#include <typeinfo>
#include <bitset>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define range(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int INF = 987654321;

long long n, m;
long long arr[1002][1002];
set<long long> s;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long tot = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			tot += arr[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		long long maxi = -1;
		for (int j = 0; j < m; j++)
		{
			maxi = max(maxi, arr[i][j]);
		}
		s.insert(maxi);
	}

	for (int i = 0; i < m; i++)
	{
		long long maxi = -1;
		for (int j = 0; j < n; j++)
		{
			maxi = max(maxi, arr[j][i]);
		}
		s.insert(maxi);
	}

	long long sum = 0;
	for (auto i : s)
	{
		sum += i;
	}

	cout <<tot -  sum;

	return 0;
}