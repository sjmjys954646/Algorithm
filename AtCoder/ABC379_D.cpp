#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_set>
#include <numeric>
#include <random>
#include <iostream>
#include <unordered_map>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define range(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;

const int INF = 2000000000;
const double pi = 3.14159265358979;
const int MOD = 100000;

void yesno(bool a)
{
	if (a)
		cout << "YES\n";
	else
		cout << "NO\n";
}

ll Q;
ll T, H;
map<ll, ll> m;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> Q;

	int ord;
	while (Q--)
	{
		cin >> ord;

		if (ord == 1)
		{
			m[0]++;
		}
		else if (ord == 2)
		{
			ll add;
			cin >> add;
			map<ll, ll> nm;
			for (auto it : m)
			{
				ll size = it.first;
				ll val = it.second;
				nm[size + add] = val;
			}
			m = nm;
		}
		else if (ord == 3)
		{
			ll add;
			cin >> add;

			auto it = m.lower_bound(add);
			ll ans = 0;

			while (it != m.end())
			{
				ans += it->second;
				it = m.erase(it);  
			}

			cout << ans << "\n";
		}
	}

	return 0;
}