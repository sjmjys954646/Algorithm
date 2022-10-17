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

int N, M;
int arr[52][52];
vector<pii> shark;
int hubo[52][52];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	int ans = INF;

	rep(i, N)
	{
		rep(j, M)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 1)
				shark.pb({i, j});
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			ans = INF;
			for (int k = 0; k < shark.size(); k++)
			{
				int sY = shark[k].F;
				int sX = shark[k].S;

				int dY = abs(sY - i);
				int dX = abs(sX - j);

				int maxi = max(dY, dX);

				ans = min(ans, maxi);
			}
			hubo[i][j] = ans;
		}
	}

	ans = -1;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			ans = max(ans, hubo[i][j]);
		}
	}

	cout << ans;

	return 0;
}