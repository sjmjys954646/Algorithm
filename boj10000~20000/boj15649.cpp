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
#define Max(a,b) a < b ? b : a;
#define Min(a,b) a < b ? a : b;

using namespace std;

int N;
int M;
vector<int> picked;
bool check[10];

void backtrack(int toPick)
{
	if (toPick == 0)
	{
		for (int i = 0; i < picked.size(); i++)
		{
			cout << picked[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		if (check[i-1] == true)
			continue;
		picked.push_back(i);
		check[i-1] = true;
		backtrack(toPick - 1);
		picked.pop_back();
		check[i-1] = false;
	}
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;

	backtrack(M);

	return 0;
}