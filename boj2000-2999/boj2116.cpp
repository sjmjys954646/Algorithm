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

int N;
int arr[10002][7];
int dice[6] = { 5,3,4,1,2,0 };
int tot = 0;


int maxiD(int a, int b)
{
	if (max(a, b) != 6)
		return 6;
	else if (min(a, b) != 5)
		return 5;
	else
		return 4;
}

int topDice(int beforeDiceTop, int index)
{
	if (index == N)
		return 0;

	int cur;
	rep(i, 6)
	{
		if (arr[index][i] == beforeDiceTop)
		{
			cur = i;
		}
	}

	int up = dice[cur];

	return topDice(arr[index][up], index + 1) + maxiD(beforeDiceTop, arr[index][up]);
}

int main()
{
	scanf("%d", &N);

	rep(i, N)
	{
		rep(j, 6)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	rep(i, 6)
	{
		tot = max(tot,topDice(arr[0][i], 0));
	}

	cout << tot;

	return 0;
}