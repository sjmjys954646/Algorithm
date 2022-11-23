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

int M, N;
long long arr[1000002];
long long tmp;

bool check(long long mid)
{
	ll sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum += (arr[i] / mid);
	}
	return sum >= M;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	ll lo = 0;
	ll hi = 10000000000000002;
	while (lo + 1 < hi)
	{
		ll mid = (lo + hi) / 2;
		if (check(mid))
			lo = mid;
		else
			hi = mid;
	}
	cout << lo;


	return 0;
}