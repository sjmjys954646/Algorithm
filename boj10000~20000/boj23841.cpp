#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <string>

using namespace std;

int arr[52][52];
int ansarr[52][52];

int main()
{
	int N, M;

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			char t;
			cin >> t;
			if (t == '.')
				arr[i][j] = 0;
			else
				arr[i][j] = t - 'A' + 1;
		}
	}
	int index = M - 1;
	for(int i = 0;i<N;i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] > 0)
			{
				ansarr[i][index - j] = arr[i][j];
				ansarr[i][j] = arr[i][j];
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (ansarr[i][j] == 0)
				cout << '.';
			else
				cout << (char)(ansarr[i][j] + 'A' - 1);
		}
		cout << "\n";
	}

	return 0;
}