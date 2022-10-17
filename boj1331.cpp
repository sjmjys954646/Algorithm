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
#include <typeinfo>
#include <cmath>

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

int dx[8] = { 1,2,2,1,-1,-2,-2,-1 };
int dy[8] = { -2,-1,1,2,2,1,-1,-2 };
vector<pii> v;
int arr[7][7];

bool bfs()
{
	int curX = v[0].S;
	int curY = v[0].F;
	for (int i = 1; i < 37; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			int nX = curX + dx[j];
			int nY = curY + dy[j];

			if (arr[nY][nX] == 1)
				continue;

			if (nX < 0 || nX >= 6 || nY < 0 || nY >= 6)
				continue;

			if (nX == v[i].S && nY == v[i].F)
			{
				curX = nX;
				curY = nY;

				if (arr[curY][curX] == 1)
					return false;

				arr[curY][curX] = 1;

				break;
			}
		}
	}

	int sum = 0;
	rep(i, 6)
	{
		rep(j, 6)
		{

			sum += arr[i][j];
		}
	}
		

	if (sum == 36)
		return true;
	else
		return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 36; i++)
	{
		string tmp;
		cin >> tmp;
		v.pb({ tmp[1] - '1', tmp[0] - 'A' });
	}
	v.pb({ v[0].first, v[0].second });

	if (bfs())
		cout << "Valid";
	else
		cout << "Invalid";

	return 0;
}
