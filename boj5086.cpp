
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <stdio.h>
#include <string>
#include <math.h>
#define Max(a,b) a < b ? b : a;
#define Min(a,b) a < b ? a : b;

using namespace std;


int main()
{
	int a, b;

	while (true)
	{
		cin >> a >> b;
		
		if (a == 0 && b == 0)
			break;

		if (a > b)
		{
			int tmp = a / b;
			if (a == b * tmp)
			{
				cout << "multiple" << "\n";
			}
			else
			{
				cout << "neither" << "\n";
			}
		}
		else
		{
			int tmp = b / a;
			if (b == a * tmp)
			{
				cout << "factor" << "\n";
			}
			else
			{
				cout << "neither" << "\n";
			}
		}
	}

	return 0;
}