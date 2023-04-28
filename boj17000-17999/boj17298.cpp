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

void Machine(vector<int> &A, stack<int> &s,vector<int> &ans, int i)
{
	if (s.empty())
	{
		ans[i] = -1;
		s.push(A[i]);
	}
	else
	{
		if (A[i] < s.top())
		{
			ans[i] = s.top();
			s.push(A[i]);
		}
		else
		{
			s.pop();
			Machine(A, s, ans, i);
		}
	}
	
}


int main()
{
	stack<int> s;
	vector<int> A;
	int N;

	cin >> N;

	vector<int> ans(N);
	
	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		A.push_back(tmp);
	}

	ans[N - 1] = -1;
	s.push(A[N - 1]);

	for (int i = N-2; i >= 0; i--)
	{
		Machine(A, s, ans, i);
	}
	
	for (int i = 0; i < N; i++)
	{
		cout << ans[i] << " ";
	}

	return 0;
}
