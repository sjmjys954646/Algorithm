#include <iostream>

using namespace std;

int main()
{
	int b, c, d;

	while (true)
	{
		cin >> b >> c >> d;
		if (b + c + d == 0)
			break;

		if (b * b + c * c == d * d || b * b + d * d == c * c || c * c + d * d == b * b)
			cout << "right" << '\n';
		else
			cout << "wrong" << '\n';
		
	}

	return 0;
}