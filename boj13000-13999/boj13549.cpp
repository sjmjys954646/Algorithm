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
int check[100002];
queue<pii> q;
int N, K;

int bfs()
{
	q.push({N,0});
	check[N] = 1;

	while (!q.empty())
	{
		int tmp = q.front().F;
		int cost = q.front().S;


		if (tmp == K)
			return cost;

		q.pop();

		if (tmp * 2 <= 100000 && !check[tmp * 2]) {
			check[tmp * 2] = true;
			q.push({ 2 * tmp, cost });
		}

		if (tmp - 1 >= 0 && !check[tmp - 1]) {
			check[tmp - 1] = true;
			q.push({ tmp - 1, cost + 1 });
		}

		if (tmp + 1 <= 100000 && !check[tmp + 1]) {
			check[tmp + 1] = true;
			q.push({ tmp + 1, cost + 1 });
		}

	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;

	memset(check, 0, sizeof(check));

	if (N == K)
	{
		cout << "0";
		return 0;
	}
	cout << bfs();

	return 0;
}
