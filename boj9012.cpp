#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;

string s;
stack<char> st;

bool check()
{
	while (!st.empty())
	{
		st.pop();
	}
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '(' || s[i] == '[')
			st.push(s[i]);
		else if (s[i] == ')' || s[i] == ']')
		{
			if (st.size() != 0 && s[i] == ')' || s[i] == ']')
			{
				st.pop();
			}
			else
			{
				return false;
			}
		}
	}

	if (st.empty())
		return true;
	else
		return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;

	while (t--)
	{
		cin >> s;
		if (check())
			cout << "YES\n";
		else
			cout << "NO\n";

	}


	return 0;
}