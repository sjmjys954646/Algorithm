#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <stdio.h>
#include <string>
#include <math.h>
#include <map>
#define Max(a,b) a < b ? b : a;
#define Min(a,b) a < b ? a : b;

using namespace std;

int main()
{
	int num;
	int tmp;
	cin >> num;

	for (int i = 0; i < num; i++)
	{
		int ans = 1;
		map<string, int> M;
		cin >> tmp;
		
		for (int j = 0; j < tmp; j++)
		{
			string a, b;
			cin >> a >> b;
			M[b]++;
		}

		for (auto t = M.begin() ; t != M.end(); t++)
		{
			ans *= t->second + 1;
		}

		cout << ans - 1<<"\n";
	}

	return 0;
}