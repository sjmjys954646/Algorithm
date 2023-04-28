//freopen("input.txt", "r", stdin);
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

int door[22][22];
vi order;
int orderNum;
int mv = INF;

void dp(int a, int b, int index)
{
	if (index == orderNum)
	{
		mv = min(mv, door[a][b]);
		return;
	}

	int cur = order[index];
	
	int bef = door[cur][b];
	door[cur][b] = abs(a - cur) + door[a][b];
	dp(cur, b, index + 1);
	door[cur][b] = bef;

	bef = door[a][cur];
	door[a][cur] = abs(b - cur) + door[a][b];
	dp(a, cur, index + 1);
	door[a][cur] = bef;
}

int main()
{
	memset(door, 0, sizeof(door));

	int N;
	int a, b;

	scanf("%d", &N);
	
	scanf("%d %d", &a, &b);

	scanf("%d", &orderNum);

	rep(i, orderNum)
	{
		int tmp;
		scanf("%d", &tmp);
		order.pb(tmp);
	}

	dp(a, b, 0);

	printf("%d", mv);

	return 0;
}