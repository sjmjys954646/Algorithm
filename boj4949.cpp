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
	string str;

	while (true)
	{
		stack<char> s;
		bool check = false;

		getline(cin, str);

		if (str[0] == '.' && str.length() == 1)
			break;

		for (int i = 0; i < str.length(); i++)
		{
			int tmp = str[i];

			if (tmp == '(' || tmp == '[')
			{
				s.push(tmp);
			}
			else if (tmp == ')' | tmp == ']')
			{
				if (!s.empty())
				{
					if (s.top() == '(' && tmp == ')')
					{
						s.pop();
					}
					else if (s.top() == '[' && tmp == ']')
					{
						s.pop();
					}
					else
					{
						check = true;
						break;
					}
				}
				else
				{
					check = true;
					break;
				}
				
			}
		}


		if (check == false && s.empty())
			cout << "yes\n";
		else
			cout << "no\n";

	}
	

	return 0;
}
