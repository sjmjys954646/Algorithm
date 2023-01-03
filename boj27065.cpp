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
#include <ctype.h>

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

int T, N;
int arr[100002];

int factor(int a) {

	int sum = 0;
	for (int i = 1; i < a; i++) 
	{
		if (a % i == 0) 
		{
			sum += i;
		}
	}

	if (sum < a)
		return -1;
	else if (sum > a)
		return 1;
	else
		return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 1; i <= 10000; i++)
	{
		arr[i] = factor(i);
	}

	cin >> T;

	while (T--)
	{
		cin >> N;
		if (arr[N] == 1)
		{
			bool check = true;
			for (int i = 1; i < N; i++)
			{
				if (N % i == 0)
				{
					if (arr[i] > 0)
						check = false;
				}
			}

			if (check)
				cout << "Good Bye\n";
			else
				cout << "BOJ 2022\n";
		}
		else
		{
			cout << "BOJ 2022\n";
		}
	}
	

	return 0;
}