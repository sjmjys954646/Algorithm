#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <unordered_set>
#include <numeric>
#include <random>
#include <iostream>
#include <unordered_map>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define range(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;

const int INF = 2000000000;
const double pi = 3.14159265358979;
const int MOD = 100000;

void yesno(bool a)
{
	if (a)
		cout << "YES\n";
	else
		cout << "NO\n";
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string tmp;

	cin >> tmp;

	char a = tmp[0];
	char b = tmp[1];
	char c = tmp[2];

	cout << string(1, b) + string(1, c) + string(1, a) + " " + string(1, c) + string(1, a) + string(1, b);

	return 0;
}