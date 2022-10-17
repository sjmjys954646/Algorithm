#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <stdio.h>
#include <string>
#include<string.h>
#include <math.h>
#include <map>
#include <stack>
#define Max(a,b) a < b ? b : a;
#define Min(a,b) a < b ? a : b;

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	int num, p,testcase;

	int m1 =1, m2 = 1;



	cin >> testcase;

	while (testcase > 0)
	{
		int pisano = 0;

		cin >> num >> p;

		do
		{
			int temp = m1;
			m1 = m2;
			m2 = (temp + m2) % p;
			pisano++;
		} while (m1 != 1 || m2 != 1);

		cout << num << " " << pisano << "\n";

		testcase--;
	}

	

	return 0;
}
