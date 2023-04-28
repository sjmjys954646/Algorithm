#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <stdio.h>
#include <algorithm>

using namespace std;

int cache[4][50002];
int arr[50002];
int N;
int len;


int main()
{
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		arr[i] += tmp;
		arr[i] += arr[i - 1];
	}

	scanf("%d", &len);

	int ans = 0;

	for (int i = 1; i <= 3; i++) 
	{
		for (int j = i * len; j <= N; j++) {
			if (i == 1)
				cache[i][j] = max(cache[i][j - 1], arr[j] - arr[j - len]);
			else
				cache[i][j] = max(cache[i][j - 1], cache[i - 1][j - len] + arr[j] - arr[j - len]);
			ans = max(ans, cache[i][j]);
		}
	}

	printf("%d", ans);

	return 0;
}