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

const int INF = 1e9;

int testcase;

int N, M, K, Q;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);

	int a[100];
	int b[100];
	memset(a, -1, sizeof(a));

	for (int i = 0; i < 52; i++)
	{
		char tmp;
		cin >> tmp;

		if (a[tmp-'A'] == -1)
			a[tmp - 'A'] = i + 1;
		else
			b[tmp - 'A'] = i + 1;
	}
	int ans = 0;
	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if (a[i] < a[j] && a[j] < b[i] && b[i]< b[j])
				ans++;
		}
	}
	cout << ans;



    return 0;
}
