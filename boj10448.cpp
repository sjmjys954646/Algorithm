#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>
#define X first
#define Y second
using namespace std;

vector<int> Eureka;
int N;
int arr[1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int ans;

	for (int i = 1;; i++)
	{
		int p = i * (i + 1) / 2;

		if (p > 1000)
			break;

		Eureka.push_back(p);
	}

	memset(arr, 0, sizeof(arr));

	for (int i = 0; i < Eureka.size(); i++)
	{
		for (int j = 0; j < Eureka.size(); j++)
		{
			for (int k = 0; k < Eureka.size(); k++)
			{
				int tot = Eureka[i] + Eureka[j] + Eureka[k];
				if (tot > 1000)
					continue;
				arr[tot] = 1;
			}
		}
	}

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> ans;
		if (arr[ans] == 1)
			cout << "1\n";
		else
			cout << "0\n";
	}
	return 0;
}