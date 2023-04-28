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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	vi v;

	cin >> N >> M;
	
	rep(i,N)
	{
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());

	int l = 0;
	int r = N-1;
	int ans = 0;

	while (l < r)
	{
		int sum = v[r] + v[l];
		if (sum > M)
		{
			r--;
		}
		else if(sum < M)
		{
			l++;
		}
		else if (sum == M)
		{
			ans++;
			r--;
			l++;
		}
	}

	cout << ans;

	return 0;
}