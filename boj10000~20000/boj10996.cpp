#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define X first
#define Y second
using namespace std;

const int INF = 987654321;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;

	cin >> N;

	for (int i = 1; i <= 2 * N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (i % 2 == 1)
			{
				if (j % 2 == 1)
					cout << "*";
				else
					cout << " ";
			}
			else
			{
				if (j % 2 == 0)
					cout << "*";
				else
					cout << " ";
			}
		}
		cout << "\n";
	}
	

	return 0;
}