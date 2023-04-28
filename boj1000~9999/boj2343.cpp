// freopen("input.txt", "r", stdin);
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

const int INF = 987654321;

int N, M;
vector<int> v;


bool check(long long value)
{
	long long sum = 0;
	int count = 1;
	for (int i = 0; i < N; i++)
	{
		if (v[i] > value)
			return false;

		sum += v[i];
		if (sum > value)
		{
			sum = v[i];
			count += 1;
		}
	}

	return count <= M;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	ll lo = 0;
	ll high = 10000 * 100000;

	while (lo + 1 < high)
	{
		ll mid = (lo + high) / 2;

		if (check(mid))
		{
			high = mid;
		}
		else
		{
			lo = mid;
		}
	}

	cout << high;

	return 0;
}