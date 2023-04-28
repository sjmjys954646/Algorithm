#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N;
	int arr[2][70];
	
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> arr[0][i] >> arr[1][i];
	}

	for (int i = 0; i < N; i++)
	{
		int k = 1;

		for (int j = 0; j < N; j++)
		{
			if (arr[0][i] < arr[0][j] && arr[1][i] < arr[1][j])
			{
				k++;
			}
		}

		if (i != N - 1)
			cout << k << " ";
		else
			cout << k;
	}

	return 0;
}
