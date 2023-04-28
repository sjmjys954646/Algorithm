#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <stack>
#include <stdio.h>
#include <string>
#include <math.h>
#include <map>
#define Max(a,b) a < b ? b : a;
#define Min(a,b) a < b ? a : b;

using namespace std;


int main()
{
	int sum = 0;
	stack<int> s;
	int K;
	int tmp;

	cin >> K;

	for (int i = 0; i < K; i++)
	{
		cin >> tmp;

		if (tmp != 0)
		{
			s.push(tmp);
			sum += s.top();
		}
		else
		{
			sum -= s.top();
			s.pop();
		}
	}

	cout << sum;

	return 0;
}