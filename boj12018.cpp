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
#include <deque>
#include <stack>
#include <cstring>
#include <list>
#include <set>
#include <string.h>
#include <map>
#include <limits.h>
#include <stdlib.h>
#include <typeinfo>
#include <bitset>

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

vector<int> ansv;
int n, m;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	int N = n;

	while (n--)
	{
		int p, l;
		vector<int> v;

		cin >> p >> l;

		rep(i, p)
		{
			int tmp;
			cin >> tmp;
			v.push_back(tmp);
		}

		sort(v.begin(), v.end(), greater<>());

		int need;

		if (l > p)
			need = 1;
		else
			need = v[l - 1];

		ansv.push_back(need);
	}

	sort(ansv.begin(), ansv.end());

	int index = 0;
	int cur = m;
	int ans = 0;

	while (true)
	{
		if (index >= N)
			break;
		if (ansv[index] > cur)
			break;

		cur -= ansv[index];
		index++;
		ans++;
	}
	cout << ans;

	return 0;
}