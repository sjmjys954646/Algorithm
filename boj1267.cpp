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
	int N;
	vi v;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	int Y = 0, M = 0;
	for (int i = 0; i < N; i++)
	{
		Y += 10 * (v[i] / 30 + 1);
		M += 15 * (v[i] / 60 + 1);
	}
	if (Y > M)
		cout << "M " << M;
	else if(Y < M)
		cout << "Y " << Y;
	else
		cout << "Y M " << Y;

	return 0;
}