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

int n, m;
int c1, c2;
vi vp;
vi vq;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int tmp;

	cin >> n >> m;

	cin >> c1 >> c2;

	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		vp.push_back(tmp);
	}

	for (int i = 0; i < m; i++)
	{
		cin >> tmp;
		vq.push_back(tmp);
	}

	sort(vp.begin(), vp.end());
	sort(vq.begin(), vq.end());

	int startP = vp[0];
	int startQ = vq[0];
	int indexP = 0;
	int indexQ = 0;
	int sum = 0;
	int distance = INF;
	int mindistance = INF;

	while (true)
	{

		distance = abs(startQ - startP);

		if (distance == mindistance)
		{
			sum++;
		}

		if (distance < mindistance)
		{
			mindistance = min(mindistance, distance);
			sum = 1;
		}
			

		if (startP > startQ)
		{
			indexQ++;

			if (indexP == n || indexQ == m)
				break;

			startQ = vq[indexQ];

		}
		else
		{
			indexP++;

			if (indexP == n || indexQ == m)
				break;
			startP = vp[indexP];
		}
	}

	cout << mindistance + abs(c1 - c2) << " " << sum;


	return 0;
}