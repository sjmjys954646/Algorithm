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

int testcase;
int N;
vi v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> testcase;


	while (testcase--)
	{
		v.clear();
		vi vv;
		cin >> N;
		rep(i, N)
		{
			int tmp;
			cin >> tmp;
			v.push_back(tmp);
			vv.push_back(tmp);
		}
		sort(vv.begin(), vv.end());
		int maxi = vv[N - 1];
		int maximaxi = vv[N - 2];

		rep(i, N)
		{
			if (v[i] == maxi)
				cout << v[i] - maximaxi << " ";
			else
				cout << v[i] - maxi << " ";
		}
		cout << "\n";

	}
	

	return 0;
}