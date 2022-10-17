#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

struct Point
{
	int zero;
	int one;
};

int main()
{
	Point arr[41];
	int num;
	int T;

	cin >> num;

	arr[0].zero = 1;
	arr[0].one = 0;
	arr[1].zero = 0;
	arr[1].one = 1;

	for (int i = 2; i < 41; i++)
	{
		if (i == 2)
		{
			arr[i].zero = 1;
			arr[i].one = 1;
		}
		else if (i == 3)
		{
			arr[i].zero = 1;
			arr[i].one = 2;
		}
		else
		{
			arr[i].zero = arr[i - 1].zero + arr[i - 2].zero;
			arr[i].one = arr[i - 1].one + arr[i - 2].one;
		}
	}

	for (int i = 0; i < num; i++)
	{
		cin >> T;
		cout << arr[T].zero << " " << arr[T].one << "\n";
	}


	return 0;
}