//freopen("input.txt", "r", stdin);
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

ll seg[8000001];

void update(int node, int start, int end, int index, int val) {
	if (index < start || index > end) 
		return;

	if (start == end) 
	{
		seg[node] += val; 
		return;
	}
	update( node * 2, start, (start + end) / 2, index, val);
	update( node * 2 + 1, (start + end) / 2 + 1, end, index, val);
	seg[node] = seg[node * 2] + seg[node * 2 + 1];
}
ll query(int node, int start, int end, int k) {
	if (start == end) 
		return start;
	else {
		if (k <= seg[node * 2]) 
			return query( node * 2, start, (start + end) / 2, k);
		else 
			return query( node * 2 + 1, (start + end) / 2 + 1, end, k - seg[node * 2]);
	}
}
int main() {
	int N;
	int a, b;

	scanf("%d", &N);

	while(N--)
	{
		scanf(" %d %d", &a, &b);
		if (a == 1) 
			update(1, 1, 2000002, b, 1);
		else 
		{
			int pos = query(1, 1, 2000002, b);
			update(1, 1, 2000002, pos, -1);
			printf("%d\n", pos);
		}
	}
	return 0;
}
