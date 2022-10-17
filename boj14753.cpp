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

int N;
vi vp;
vi vn;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tmp;
	int ans = -INF;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		if (tmp < 0)
			vn.push_back({ tmp });
		else
			vp.push_back({ tmp });
	}

	sort(vp.begin(), vp.end(), greater<>());
	sort(vn.begin(), vn.end(), less<>());

	

	if (vp.size() >= 3)
		ans = max(ans, vp[0] * vp[1] * vp[2]);

	if (vp.size() >= 2)
		ans = max(ans, vp[0] * vp[1]);

	if (vn.size() >= 2)
		ans = max(ans, vn[0] * vn[1]);

	if (vn.size() >= 2 && vp.size() >= 1)
		ans = max(ans, vn[0] * vn[1] * vp[0]);
	
	cout << ans;


	return 0;
}