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
#include <stack>
#include <cstring>
#include <list>
#include <set>
#include <string.h>
#include <map>
#include <limits.h>
#include <stdlib.h>

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
int testcase;

int arr[201][201];

int dx[4] = {-1,1,-1,1};
int dy[4] = {-1,-1,1,1};
int sum = 0;
int r, c;

void go(int y, int x, int  t)
{
	if (y < 0 || x < 0 || y >= r || x >= c)
		return;
	sum += arr[y][x];
	go(y + dy[t], x + dx[t], t);
}

int select(int y, int x)
{
	sum = arr[y][x];
	for (int i = 0; i < 4; i++)
	{
		go(y + dy[i], x + dx[i], i);
	}
	return sum;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> testcase;

	while (testcase--)
	{
		cin >> r >> c;

		rep(i, r)
		{
			rep(j, c)
			{
				cin >> arr[i][j];
			}
		}
		int ans = -1;
		rep(i, r)
		{
			rep(j, c)
			{
				ans = max(ans,select(i, j));
			}
		}
		cout << ans << "\n";
	}

	return 0;
}