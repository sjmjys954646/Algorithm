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
int arr[1000002];
int F, S, G, U, D;

int bfs()
{
	arr[S] = 1;
	queue<pii> q;
	q.push({ S , 1});
	int dY[2] = { U,-D };

	while (!q.empty())
	{
		int cur = q.front().F;
		int cost = q.front().S;
		q.pop();

		if (cur == G)
			return cost - 1;

		for (int i = 0; i < 2; i++)
		{
			int nx = cur + dY[i];

			if (nx < 1 || nx > F)
				continue;
			if (arr[nx] == 1)
				continue;

			arr[nx] = 1;
			q.push({ nx , cost+1});
		}


	}
	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	memset(arr, -1, sizeof(arr));

	cin >> F >> S >> G >> U >> D;

	int tt = bfs();

	if (tt == -1)
		cout << "use the stairs";
	else
		cout << tt;


	return 0;
}
