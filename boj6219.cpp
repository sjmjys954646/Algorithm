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

int A, B, D;
int arr[4000002];
vi v;

void Eratos()
{
	for (int i = 2; i <= B; i++) {
		arr[i] = i;
	}

	for (int i = 2; i <= B; i++) {
		if (arr[i] == 0) continue; 

		
		for (int j = 2 * i; j <= B; j += i) {
			arr[j] = 0;
		}
	}


	for (int i = A; i <= B; i++) {
		if(arr[i])
			v.pb(i);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> A >> B >> D;

	Eratos();

	int ans = 0;

	for (auto i : v)
	{
		string p = to_string(i);
		for (int j = 0; j < p.size(); j++)
		{
			if (p[j] - '0' == D)
			{
				ans++;
				break;
			}
		}
	}
	cout << ans;
	

	return 0;
}