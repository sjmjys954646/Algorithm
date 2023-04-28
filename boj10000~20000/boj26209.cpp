#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;


int main()
{
	bool check = true;
	for (int i = 0; i < 8; i++)
	{
		int tmp;
		cin >> tmp;
		if (tmp != 1 && tmp != 0)
			check = false;
	}

	if (check)
		cout << "S";
	else
		cout << "F";

	return 0;
}