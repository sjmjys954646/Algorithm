#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int num;
	int arr[5];

	cin >> num;

	arr[0] = 1;
	arr[1] = 2;

	if (num == 1)
		cout << "1";
	else if (num == 2)
		cout << "2";
	else
	{
		for (int i = 2; i < num; i++)
		{
			arr[2] = (arr[1] % 15746 + arr[0] % 15746) % 15746;
			arr[0] = arr[1];
			arr[1] = arr[2];
		}
		cout << arr[2];
	}



	return 0;
}