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
#include <deque>
#include <stack>
#include <cstring>
#include <list>
#include <set>
#include <string.h>
#include <map>
#include <limits.h>
#include <stdlib.h>
#include <typeinfo>
#include <bitset>

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

	vector<pair<char,int>> v;

	string N1, N2;

	int n, m;
	int T;

	cin >> n >> m;

	int tot = n + m;

	cin >> N1 >> N2;

	cin >> T;

	reverse(N1.begin(), N1.end());

	for (int i = 0;i < n; i++)
	{
		v.push_back({ N1[i],1 });
	}

	for (int i = 0; i < m; i++)
	{
		v.push_back({ N2[i],-1 });
	}


	while (T--)
	{
		for (int i = 0; i < tot - 1; i++)
		{
			if (v[i].S == 1 && v[i + 1].S == -1)
			{
				swap(v[i], v[i + 1]);
				i++;
			}

		}
	}

	for (auto i : v)
		cout << i.F;

	return 0;
}