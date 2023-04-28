#include <iostream>

using namespace std;

void Draw(bool(*arr)[6561], int a, int b, int num);

bool arr[6561][6561];

int main()
{
	int num;

	cin >> num;

	Draw(arr,0, 0 ,num);

	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			if (arr[i][j] == true)
			{
				cout << '*';
			}
			else
			{
				cout << ' ';
			}
		}
		cout << "\n";
	}

	return 0;
}

void Draw(bool(*arr)[6561],int a, int b ,int num)
{
	num /= 3;

	if (num < 1)
	{
		arr[a][b] = true;
	}
	else
	{
		Draw(arr, a, b, num);
		Draw(arr, a + num, b, num);
		Draw(arr, a + 2*num, b, num);
		Draw(arr, a, b + num, num);
		Draw(arr, a + 2 * num, b + num, num);
		Draw(arr, a, b + 2 * num, num);
		Draw(arr, a + num, b + 2 * num, num);
		Draw(arr, a + 2 * num, b + 2 * num, num);
	}
}