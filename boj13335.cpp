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

int arr[1002];
int bridge[102];
int N;
int W;
int L;
int fin = 0;

void bridgeMove()
{
	for (int i = W; i >=0; i--)
	{
		if (bridge[i] == 0)
			continue;

		if (i == W )
		{
			bridge[i] = 0;
			fin++;
			continue;
		}
		bridge[i + 1] = bridge[i];
		bridge[i] = 0;
	}
}

int bridgeCount()
{
	int tot = 0;
	for (int i = 0; i < W; i++)
	{
		tot += bridge[i];
	}
	return tot;
}

int main()
{
	int curW = 0;
	int count = 0;
	int index = 0;

	scanf("%d %d %d", &N, &W, &L);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}

	while (fin != N)
	{
		bridgeMove();
		if (bridgeCount() + arr[index] <= L)
		{
			bridge[0] = arr[index];
			index++;
		}
		
		count++;
	}

	cout << count -1;

	return 0;
}