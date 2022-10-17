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

	int N, tmp;
	cin >> N;

	vi v;

	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		v.push_back(tmp);
	}

	sort(v.begin(), v.end());

	int ans = 0;
	int index = 0;
	int cur = -1;
	while (true)
	{
		if (index >= v.size())
		{
			if(cur != -1)
				ans++;
			break;
		}

		if(cur == -1)
			cur = v[index];

		if (cur == 1)
		{
			ans++;
			index++;
			cur = -1;
		}
		else
		{
			cur--;
			index++;
		}
	}

	cout << ans;


	return 0;
}