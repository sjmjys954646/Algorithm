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
#include <queue>
#define Max(a,b) a < b ? b : a;
#define Min(a,b) a < b ? a : b;

using namespace std;


priority_queue<pair<int,int> > pq;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	long long a;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> a;
		
		if (a == 0 && pq.empty())
		{
			cout << "0\n";
		}
		else if (a == 0)
		{
			cout << -pq.top().second << "\n";
			pq.pop();
		}
		else
			pq.push({ -abs(a),-a });
	}
	
	return 0;
}
