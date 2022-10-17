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

int arr[1000002];
int num[1000002];
int ans[1000002];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		arr[i] = tmp;
		num[tmp]++;
	}

	ans[N - 1] = -1;
	stack<int> s;
	s.push(arr[N - 1]);

	for (int i = N - 2; i >= 0; i--)
	{
		if (s.empty())
		{
			ans[i] = -1;
			s.push(arr[i]);
		}
		else
		{
			if (num[arr[i]] >= num[s.top()])
			{
				while (true)
				{
					s.pop();

					if (s.empty())
					{
						ans[i] = -1;
						s.push(arr[i]);
						break;
					}

					if (num[arr[i]] < num[s.top()])
					{
						ans[i] = s.top();
						s.push(arr[i]);
						break;
					}
				}
			}
			else
			{
				ans[i] = s.top();
				s.push(arr[i]);
			}
		}		
	}

	for (int i = 0; i < N; i++)
	{
		cout << ans[i] << " ";
	}



	return 0;
}