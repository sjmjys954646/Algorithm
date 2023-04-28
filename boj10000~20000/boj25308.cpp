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

vi v;
int visited[8];
vi selected;
int ans = 0;
double coordX[8] = {0,sqrt(2)/2,1,sqrt(2)/2,0,-sqrt(2)/2,-1,-sqrt(2)/2};
double coordY[8] = {-1,-sqrt(2)/2,0,sqrt(2)/2,1,sqrt(2)/2,0,-sqrt(2)/2};

int ccw(pii a, pii b, pii c)
{
	int op = a.F * b.S + b.F * c.S + c.first * a.second;
	op -= a.S * b.F + b.S * c.F + c.S * a.F;

	if (op > 0)
		return 1;
	else if (op == 0)
		return 0;
	else
		return -1;
}


void cal()
{
	bool pos = true;

	vector<pair<double,double>> graph_coordinate;

	for (int i = 0; i < 8; i++)
	{
		graph_coordinate.push_back({ coordX[i] * selected[i], coordY[i] * selected[i] });
	}
	int index1, index2, index3;
	index1 = 0;
	index2 = 1;
	index3 = 2;

	for (int i = 0; i < 8; i++)
	{
		/*if (ccw(graph_coordinate[index1], graph_coordinate[index2], graph_coordinate[index3]) >= 0)
		{
			pos = false;
		}*/
		if (selected[index1] * selected[index3] * sqrt(2) > selected[index2] * (selected[index1] + selected[index3])) {
			pos = false;
		}


		index1 = (index1 + 1) % 8;
		index2 = (index2 + 1) % 8;
		index3 = (index3 + 1) % 8;
	}

	if (pos)
		ans++;
}

void select()
{
	if (selected.size() == 8)
	{
		cal();
	}

	for (int i = 0; i < 8; i++)
	{
		if (visited[i] == 1)
			continue;

		selected.push_back(v[i]);
		visited[i] = 1;
		select();
		selected.pop_back();
		visited[i] = 0;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	rep(i, 8)
	{
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	select();

	cout << ans;

	return 0;
}