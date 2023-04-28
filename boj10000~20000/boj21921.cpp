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

int sum[250002];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int X, N;
	int tmp;
	int ans = 0;
	int count = 0;

	cin >> X >> N;
	
	for (int i = 1; i <= X; i++)
	{
		cin >> tmp;
		sum[i] += (sum[i - 1] + tmp);
	}

	for (int i = 0; i <= X - N; i++)
	{
		ans = max(ans, sum[i + N] - sum[i]);
	}

	if (ans)
		cout << ans <<"\n";
	else
		cout << "SAD";

	
	if (ans)
	{
		for (int i = 0; i <= X - N; i++)
		{
			if (sum[i + N] - sum[i] == ans)
			{
				count++;
			}
		}
		cout << count;
	}

	return 0;
}