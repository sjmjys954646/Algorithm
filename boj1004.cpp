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

int startX, startY, finX, finY;

float dis(int x, int y, int targetx, int targety)
{
	return sqrt(pow(x-targetx,2) + pow(y-targety,2));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testcase;

	cin >> testcase;

	while (testcase--)
	{
		cin >> startX >> startY >> finX >> finY;

		int num;
		cin >> num;
		int ans = 0;

		rep(i, num)
		{
			int px, py;
			int radi;
			cin >> px >> py >> radi;

			if (dis(startX,startY,px,py) < radi && dis(finX, finY, px, py) < radi)
				continue;

			if (dis(startX, startY, px, py) < radi)
			{
				ans++;
				continue;
			}
			if (dis(finX, finY, px, py) < radi)
			{
				ans++;
				continue;
			}
		}
		cout <<ans << "\n";
	}

	return 0;
}