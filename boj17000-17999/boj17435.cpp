#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;

int M, Q;
int dp[500001][20];
int N, X;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M;

	for (int i = 1; i <= M; i++)
	{
		cin >> dp[i][0];
	}

	for (int j = 1; j < 19; j++)
		for (int i = 1; i <= M; i++)
			dp[i][j] = dp[dp[i][j - 1]][j - 1];


	cin >> Q;

	for (int i = 0; i < Q; i++)
	{
		cin >> N >> X;

		for (int j = 18; j >= 0; j--)
		{
			if (N & (1 << j))
				X = dp[X][j];
		}
		cout << X <<"\n";
	}


	return 0;
}