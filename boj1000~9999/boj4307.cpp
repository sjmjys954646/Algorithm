// freopen("input.txt", "r", stdin);
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <queue>
#include <stack>
#include <cstring>
#include <list>
#include <set>
#include <string.h>
#include <map>
#include <limits.h>
#include <stdlib.h>
#include <typeinfo>
#include <cmath>

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
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> testcase;

	while (testcase--)
	{
		int n, l;
		int a = 0, b = 0;
		cin >> l >> n;
		rep(i, n)
		{
			int tmp;
			cin >> tmp;
			
			int minGo = min(tmp, l- tmp);
			int maxGo = max(tmp, l - tmp);

			a = max(a, minGo);
			b = max(b, maxGo);

		}
		cout << a << " " << b << "\n";
	}


	return 0;
}
