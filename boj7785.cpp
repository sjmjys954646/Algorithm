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

map<string, int> m;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;

	cin >> N;

	string tmp;
	string enter;

	for (int i = 0; i < N; i++)
	{
		cin >> tmp >> enter;
		if (enter == "enter")
			m[tmp]++;
		else
			m[tmp]--;
	}

	vector<string> s;

	for (auto i : m)
		if (i.second)
			s.push_back(i.first);

	sort(s.begin(), s.end(), greater<>());

	for (auto i : s)
		cout << i << "\n";

	return 0;
}