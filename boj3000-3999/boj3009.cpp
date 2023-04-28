#include <iostream>

using namespace std;

int main()
{
	int x[3];
	int y[3];

	for (int i = 0; i < 6; i++)
	{
		if (i % 2 == 0)
			cin >> x[i/2];
		else
			cin >> y[i/2];
	}

	if (x[0] == x[1])
		cout << x[2] << ' ';
	else if(x[0] == x[2])
		cout << x[1] << ' ';
	else
		cout << x[0] << ' ';

	if (y[0] == y[1])
		cout << y[2];
	else if (y[0] == y[2])
		cout << y[1];
	else
		cout << y[0];

	return 0;
}