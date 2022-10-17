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
	int n;
	int i = 2;
	cin >> n;

	if (n == 1)
	{
		return 0;
	}

	while (n != 1)
	{
		if (n % i == 0)
		{
			cout << i << "\n";
			n /= i;
			i = 1;
		}
		i++;
	}

	

	return 0;
}