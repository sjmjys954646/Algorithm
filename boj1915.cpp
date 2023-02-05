#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <string>
#include <cmath>
using namespace std;

int N, M;
int arr[1002][1002];
int cache[1002][1002];

int main()
{
	cin >> N >> M;

	string tmp;

	for (int i = 1; i <= N; i++)
	{
		cin >> tmp;
		for (int j = 1; j <= M; j++)
		{
			arr[i][j] = tmp[j - 1] - '0';
			cache[i][j] = cache[i][j - 1] + cache[i - 1][j] - cache[i - 1][j - 1] + arr[i][j];
		}
	}

	int ans = 0;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			for (int l = ans;; l++)
			{
				if (N < i + l || M < j + l)
					break;

				if (cache[i + l][j + l] + cache[i - 1][j - 1] - cache[i - 1][j + l] - cache[i + l][j - 1] == (l + 1) * (l + 1))
					ans = l + 1;
				else 
					break;
			}
		}
	}

	cout << ans*ans;

	return 0;
}
