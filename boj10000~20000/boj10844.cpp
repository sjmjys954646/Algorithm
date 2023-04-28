#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>

using namespace std;

int min(int a, int b)
{
	return a < b ? a : b;
}

int max(int a, int b)
{
	return a < b ? b : a;
}


long long arr[101][10] = { 0, };

int main()
{
	int num;
	long long sum = 0;
	
	cin >> num;
	
	for (int i = 0; i < 10; i++)
	{
		arr[0][i] = 1;
	}

	for (int i = 1; i < 101; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 0)
				arr[i][0] += (arr[i - 1][1] % 1000000000);
			else if (j == 9)
				arr[i][9] += (arr[i - 1][8] % 1000000000);
			else
			{
				arr[i][j] = arr[i][j] + (arr[i - 1][j - 1] % 1000000000 + arr[i - 1][j + 1] % 1000000000) % 1000000000;
			}
		}
	}


	for (int i = 1; i < 10; i++)
	{
		sum += arr[num - 1][i] % 1000000000;
	}


	cout << sum % 1000000000;

	return 0;
}




