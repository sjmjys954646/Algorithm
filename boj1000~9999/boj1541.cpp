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
	string sarr;
	string temp = "";
	int storesum = 0;
	bool firstcheck = false;

	cin >> sarr;

	for (int i = 0; i <= sarr.size(); i++)
	{
		if (sarr[i] == '+' || sarr[i] == '-' || sarr[i] == '\0')
		{
			if (firstcheck)
				storesum -= stoi(temp);
			else
				storesum += stoi(temp);

			temp = ""; 

			if (sarr[i] == '-')
				firstcheck = true;
			continue;
		}
		temp += sarr[i];
	}

	cout << storesum;

	return 0;
}

