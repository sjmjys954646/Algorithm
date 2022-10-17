
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
	int Testcase;

	cin >> Testcase;
	int tmp;

	for (int i = 0; i < Testcase; i++)
	{
		vector<int> v;
		queue<int> q;
		int N;
		int pos;
		int outnum = 0;
		int index = 0;

		cin >> N >> pos;

		for (int j = 0; j < N; j++)
		{
			cin >> tmp;
			v.push_back(tmp);
			q.push(tmp);
		}

		sort(v.begin(), v.end(), greater<int>());

		while (pos != -1)
		{
			if (q.front() == v[index])
			{
				q.pop();
				index++;
				pos -= 1;
				outnum++;
			}
			else
			{
				tmp = q.front();
				q.pop();
				q.push(tmp);
				pos -= 1;
				if (pos < 0)
					pos = q.size() - 1;
			}
		}
		cout << outnum<<"\n"; 
	}

	return 0;
}