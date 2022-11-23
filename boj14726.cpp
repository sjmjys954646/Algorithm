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

int n;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	while (n--)
	{
		string tmp;
		cin >> tmp;
		int sum = 0;
		for (int i = 15; i >= 0; i--)
		{
			if (i % 2 == 0)
			{
				int k = (tmp[i] - '0') * 2;
				if (k >= 10)
				{
					int pp = k % 10 + k / 10;
					k = pp;
				}
				sum += k;
			}
			else
				sum += (tmp[i] - '0');

		}
		if (sum % 10 == 0)
			cout << "T\n";
		else
			cout << "F\n";
	}
	

	return 0;
}