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
int testcase;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> testcase;

	while (testcase--)
	{
		int n, q;
		cin >> n >> q;

		vector<int> v;
		int sum = 0;
		vi psum;

		rep(i, n)
		{
			int tmp;
			cin >> tmp;
			v.push_back(tmp);
			sum += tmp;
		}
		sort(v.begin(), v.end(), greater<int>());
		int cur = 0;
		psum.resize(n);
		rep(i, n)
		{
			cur += v[i];
			psum[i] = cur;
		}

		rep(i, q)
		{
			int tmp;
			cin >> tmp;

			if (tmp > sum)
			{
				cout << "-1\n";
				continue;
			}

			auto it = lower_bound(psum.begin(), psum.end(), tmp);
			int ans = it - psum.begin() + 1;
			cout << ans << "\n";
		}
	}

	return 0;
}