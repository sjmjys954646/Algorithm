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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> testcase;

	while (testcase--)
	{
		int x;
		string tmp;

		cin >> x;
		cin >> tmp;

		int visit[27] = { 0, };

		for (int i = 0; i < tmp.size(); i++)
		{
			visit[tmp[i] - 'a' + 1] = 1;
		}
		int p = 0;

		for (int i = 26; i >= 0; i--)
		{
			if (visit[i])
			{
				p = i;
				break;
			}
		}
			
		cout << p  <<"\n";
		
	}
	

	return 0;
}