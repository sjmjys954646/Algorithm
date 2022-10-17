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

	queue<int> q;

	for (int i = 1; i <= num; i++)
	{
		q.push(i);
	}

	while (q.size() != 1)
	{
		q.pop();
		tmp = q.front();
		q.pop();
		q.push(tmp);
	}
	cout << q.front();

	return 0;
}
