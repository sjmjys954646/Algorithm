#include <iostream>

using namespace std;

int main()
{
	char arr[120];
	int i = 0;
	int minus = 0;
	
	cin >> arr;

	while (arr[i] != 0)
	{
		if(arr[i] == '=')
		{
			if (arr[i - 1] == 'c')
			{
				minus++;
			}
			else if(arr[i - 1] == 'z')
			{
				if (arr[i - 2] == 'd')
				{
					minus += 2;
				}
				else
				{
					minus++;
				}
			}
			else if (arr[i - 1] == 's')
			{
				minus++;
			}
		}
		else if(arr[i] == '-')
		{
			if (arr[i - 1] == 'c')
			{
				minus++;
			}
			else if (arr[i - 1] == 'd')
			{
				minus++;
			}
		}
		else if (arr[i] == 'j')
		{
			if (arr[i - 1] == 'l')
			{
				minus++;
			}
			else if (arr[i - 1] == 'n')
			{
				minus++;
			}
		}
		i++;
	}

	cout << i - minus;



	return 0;
}