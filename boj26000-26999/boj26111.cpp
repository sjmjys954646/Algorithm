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

	string tmp;
	stack<char> s;

	cin >> tmp;

	long long sum = 0;

	for (int i = 0; i < tmp.size(); i++)
	{
		if (tmp[i] == '(')
		{
			s.push(tmp[i]);
		}
		else
		{
			if (tmp[i - 1] == '(')
			{
				sum += s.size() - 1;
			}
			s.pop();
		}
	}
	cout << sum;

	return 0;
}