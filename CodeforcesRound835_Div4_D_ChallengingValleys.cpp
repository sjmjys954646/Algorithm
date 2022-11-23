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
int tmp;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> testcase;


	while (testcase--)
	{
		vi v;
		int sum = 0;
		int least = INF;
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> tmp;
			v.push_back(tmp);
			least = min(least, tmp);
		}

		if (N == 1)
		{
			cout << "YES\n";
			continue;
		}

		bool pos = true;
		for (int i = 0; i < N - 1; i++)
		{
			if (v[i] < v[i + 1])
			{
				pos = false;
			}
		}
		if (pos)
		{
			cout << "YES\n";
			continue;
		}

		pos = true;
		for (int i = 0; i < N - 1; i++)
		{
			if (v[i] > v[i + 1])
			{
				pos = false;
			}
		}
		if (pos)
		{
			cout << "YES\n";
			continue;
		}

		pos = true;
		bool at = false;
		for (int i = 0; i < N - 1; i++)
		{
			if (at)
			{
				if (v[i] > v[i + 1])
				{
					pos = false;
				}
			}

			if (v[i] < v[i + 1])
			{ 
				at = true;
			}
		}
		if (pos)
		{
			cout << "YES\n";
			continue;
		}

		cout << "NO\n";

	}
	

	return 0;
}