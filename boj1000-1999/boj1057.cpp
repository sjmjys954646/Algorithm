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


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tot, a, b;

	cin >> tot >> a >> b;

	int ans = 1;

	int mi = min(a, b);
	int ma = max(a, b);
	a = mi;
	b = ma;

	while (true)
	{
		if (abs(a - b) == 1 && a % 2 == 1 && b % 2 == 0)
		{
			break;
		}

		if (a % 2 == 0)
			a /= 2;
		else
			a = (a + 1) / 2;

		if (b % 2 == 0)
			b /= 2;
		else
			b = (b + 1) / 2;
		ans++;

	}
	cout << ans;
	return 0;
}