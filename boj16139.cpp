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

int arr[30][200003] = { 0, };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string tmp; 

	cin >> tmp;

	int q;

	cin >> q;

	for (int i = 1; i <= tmp.size(); i++)
	{
		for (int j = 0; j < 26; j++)
		{
			arr[j][i] = arr[j][i - 1];
		}

		int p = tmp[i-1] - 'a';
		arr[p][i]++;

	}

	char t;
	int a;
	int b;

	for (int i = 0; i < q; i++)
	{

		cin >> t >> a >> b;
		cout << arr[t - 'a'][b + 1] - arr[t - 'a'][a ] << "\n";
	}

	

	return 0;
}
