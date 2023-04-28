
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

vector<bool> check;
vector<string> res;
string tmp;

void Arrange(vector<char> str, int index)
{
	if (index == str.size())
	{
		res.push_back(tmp);
		return;
	}

	for (int i = 0; i < str.size(); i++)
	{
		if (check[i] == false)
		{
			tmp[index] = str[i];
			check[i] = true;
			Arrange(str, ++index);
			index--;
			check[i] = false;
		}
	}
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int num;
	int arr[4];
	char arrX[4] = { 'A','B','C','D' };
	vector<char> str;

	cin >> num;
	
	vector<int> vec(num);

	check.resize(num - 1);

	for (int i = 0; i < num; i++)
	{
		cin >> vec[i];
	}

	for (int i = 0; i < 4; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < arr[i]; j++)
		{
			str.push_back(arrX[i]);
		}
	}

	tmp.resize(num - 1);

	Arrange(str, 0);

	int max = -1987654321;
	int min = 1987654321;

	for (int i = 0; i < res.size(); i++)
	{
		int ans = vec[0];
		for (int j = 1; j < num; j++)
		{
			if (res[i].at(j-1) == 'A')
				ans += vec[j];
			else if (res[i].at(j - 1) == 'B')
				ans -= vec[j];
			else if (res[i].at(j - 1) == 'C')
				ans *= vec[j];
			else
				ans /= vec[j];
		}

		if (ans > max)
			max = ans;
		if (ans < min)
			min = ans;

	}

	cout << max << "\n" << min;

	return 0;
}