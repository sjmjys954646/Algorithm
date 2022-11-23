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
int arr[102][102];
int visited[102];
vi v[102];
int ans = 0;

bool check(int x) {
	bool pos = false;
	for (int i = 0; i < N; i++) 
	{
		if (i == x) continue;

		if (arr[x][i] == 0) 
			pos = true;
	}
	return pos;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j < N; j++) 
		{
			cin >> arr[i][j];
		}
	}

	bool pos = true;
	int cnt = 1;
	for (int i = 0; i < N; i++) 
	{
		if (!check(i)) {
			pos = false;
			break;
		}

		if (visited[i]) 
			continue;

		visited[i] = cnt;

		for (int j = 0; j < N; j++) 
		{

			if (i == j) 
				continue;

			if (arr[i][j] == 0) 
			{
				if (visited[j] != 0 && visited[j] != cnt) 
				{
					pos = false;
					break;
				}
				else 
				{
					visited[j] = cnt;
				}
			}

			if(!pos)
				break;
		}
		cnt++;
	}

	if (pos) 
	{
		for (int i = 0; i < N; i++) 
		{
			v[visited[i]].push_back(i + 1);
		}

		for (int i = 0; i < 101; i++) 
		{
			if (v[i].empty()) 
				continue;
			ans++;
			sort(v[i].begin(), v[i].end());
		}

		cout << ans << "\n";

		for (int i = 0; i < 101; i++) 
		{
			if (v[i].empty())
				continue;

			for (int j = 0; j < v[i].size(); j++) 
			{
				cout << v[i][j] << " ";
			}
			cout << "\n";
		}
	}
	else
		cout << "0";

    return 0;

}