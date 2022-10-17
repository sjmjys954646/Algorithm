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
	stack<int> s;
	vector<int> v;
	vector<char> charv;
	int pos = 0;
	int index = 1;
	int num;
	int tmp;
	bool check = true;

	cin >> num;

	for (int i = 0; i < num; i++)
	{
		cin >> tmp;
		v.push_back(tmp);
	}

	while (pos != num)
	{
		if (s.empty())
		{
			s.push(index);
			index++;
			charv.push_back('+');
		}

		if (v[pos] == s.top())
		{
			s.pop();
			charv.push_back('-');
			pos++;
		}
		else
		{
			if (v[pos] < s.top())
			{
				cout << "NO";
				check = false;
				break;
			}

			while (v[pos] != s.top())
			{
				s.push(index);
				index++;
				charv.push_back('+');
			}
		}
	}

	if (check)
	{
		for (auto it = charv.begin(); it != charv.end(); it++)
		{
			cout << *it << "\n";
		}
	}

	return 0;
}

