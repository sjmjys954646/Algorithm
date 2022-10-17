#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> vec;
	int num;

	cin >> num;
	
	for (int i = 600; i < 10000000; i++)
	{
		int M = i;
		int k = 0;
		int arr[10];

		while (M != 0)
		{
			arr[k] = M % 10;
			M /= 10;
			k++;
		}

		for (int j = k - 2; j >= 0; j--)
		{
			if (arr[j] == 6 && arr[j + 1] == 6 && arr[j + 2] == 6)
			{
				vec.push_back(i);
				break;
			}
		}
	}

	cout << vec[num - 1];

	return 0;
}