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
int arr[503][503];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int R, C;

	cin >> R >> C;

	rep(i, R)
	{
		string tmp;

		cin >> tmp;
		rep(j,C)
		{
			char a = tmp[j];
			if (a == 'S')
			{
				arr[i][j] = 1;
			}
			else if (a == 'W')
			{
				arr[i][j] = 5;
			}
		}
	}

	bool pos = false;
	rep(i, R)
	{
		rep(j, C)
		{
			if (arr[i][j] != 1)
				continue;

			for (int k = 0; k < 4; k++)
			{
				int nx = j + dx[k];
				int ny = i + dy[k];

				if (nx < 0 || ny < 0 || nx >= C || ny >= R)
					continue;

				if (arr[ny][nx] == 1)
					continue;

				if (arr[ny][nx] == 5)
					pos = true;

				arr[ny][nx] = 3;
			}
		}
	}

	if (pos)
		cout << "0";
	else
	{
		cout << "1\n";
		rep(i, R)
		{
			rep(j, C)
			{
				int cur = arr[i][j];
				if (cur == 0)
					cout << ".";
				else if (cur == 1)
					cout << "S";
				else if (cur == 3)
					cout << "D";
				else if (cur == 5)
					cout << "W";
				else
					cout << ".";
			}
			cout << "\n";
		}
	}

	return 0;
}
