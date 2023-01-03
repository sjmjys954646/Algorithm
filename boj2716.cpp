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

int N;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	
	cin.get();

	while (N--)
	{
		int depth = 0;
		stack<char> s;

		string tmp;
		getline(cin, tmp);
		rep(i, tmp.size())
		{
			if (tmp[i] == '[')
			{
				s.push(tmp[i]);
				depth = max(depth, (int)s.size());
			}
			else if (tmp[i] == ']')
			{
				s.pop();
			}
		}
		unsigned long long ans = 1;
		for (int i = 0; i < depth; i++)
			ans *= 2;

		cout << ans << "\n";
	}


	return 0;
}