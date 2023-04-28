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

int N, K, School;
vector<pii> larr;
vector<pii> rarr;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tmp;
	int location;
	int ans = 0;
	cin >> N >> K >> School;

	for (int i = 0; i < N; i++)
	{
		cin >> location >> tmp;
		if (location < School)
			larr.push_back({location, tmp});
		else
			rarr.push_back({location, tmp});
	}
	sort(larr.begin(), larr.end(), greater<pii>());
	sort(rarr.begin(), rarr.end());

	int curPos = School;
	int curNum = 0;
	while (!larr.empty())
	{
		int pos = larr.back().F;
		int num = larr.back().S;

		if (num + curNum <= K)
		{
			larr.pop_back();
			curNum += num;
		}
		else
		{
			larr.back().S -= K - curNum;
			curNum += K - curNum;
		}

		ans += abs(curPos - pos);
		curPos = pos;

		if (curNum == K || larr.empty())
		{
			ans += abs(curPos - School);
			curPos = School;
			curNum = 0;
		}
	}
	curPos = School;
	curNum = 0;
	while (!rarr.empty())
	{
		int pos = rarr.back().F;
		int num = rarr.back().S;

		if (num + curNum <= K)
		{
			rarr.pop_back();
			curNum += num;
		}
		else
		{
			rarr.back().S -= K - curNum;
			curNum += K - curNum;
		}

		ans += abs(curPos - pos);
		curPos = pos;

		if (curNum == K || rarr.empty())
		{
			ans += abs(curPos - School);
			curPos = School;
			curNum = 0;
		}
	}

	cout << ans;

	return 0;
}