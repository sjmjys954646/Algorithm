#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

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

const int INF = 9876543210;

ll N, M;

struct bus
{
	ll a;
	ll b;
	ll index;
};

int arr[500002];

bool check(bus aa, bus bb)
{
	if (aa.a == bb.a)
		return aa.b > bb.b;
	else
		return aa.a < bb.a;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	cin >> N >> M;

	vector<bus> v;

	ll a, b;

	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;

		if (a < b)
		{
			bus t = { a,b,i };
			bus tt = { a + N,b + N,i };
			v.push_back(t);
			v.push_back(tt);
		}
		else
		{
			bus t = { a,b + N,i };
			v.push_back(t);
		}
	}

	sort(v.begin(), v.end(), check);

	bus bef = { 0,0,-1 };
	for (int i = 0; i < v.size(); i++)
	{
		if (arr[v[i].index])
			continue;

		if (bef.a <= v[i].a && v[i].b <= bef.b)
		{
			arr[v[i].index] = 1;
			continue;
		}
		bef = v[i];
	}
	for (int i = 0; i < M; i++)
	{
		if (!arr[i])
		{
			cout << i + 1 << " ";
		}
	}

	return 0;
}