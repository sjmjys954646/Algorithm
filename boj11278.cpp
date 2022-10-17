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
vector<pii> sik;
int tf[21];
int pos = false;
int sc[21];

bool cal()
{
	for (int i = 0; i < M; i++)
	{
		int f = sik[i].first;
		int s = sik[i].second;

		int a = tf[abs(f)-1];
		int b = tf[abs(s)-1];
		if (f < 0)
			a = !a;
		if (s < 0)
			b = !b;
		if (a + b == 0)
			return false;
	}
	for (int i = 0; i < N; i++)
	{
		sc[i] = tf[i];
	}

	return true;
}

void select(int cur)
{
	if (cur == N)
	{
		if (cal())
			pos = true;
		return;
	}

	tf[cur] = 1;
	select(cur + 1);
	tf[cur] = 0;
	select(cur + 1);
}

int main()
{
	scanf("%d %d", &N, &M);

	rep(i, M)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		sik.push_back({ a,b });
	}
	
	select(0);

	if (pos)
	{
		cout << 1 <<"\n";
		for (int i = 0; i < N; i++)
		{
			cout << sc[i] << " ";
		}
	}
	else
		cout << 0;

	return 0;
}