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

map<int, int> Mp;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N,M,tmp;
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		Mp[tmp]++;
	}

	cin >> M;

	for (int i = 0; i < M; i++)
	{
		cin >> tmp;
		cout << Mp[tmp] << " ";
	}



	return 0;
}
