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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	priority_queue<int, vector<int>, less<int> > max_heap;
	priority_queue<int, vector<int>, greater<int> > min_heap;

	int N, num;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> num;
		if (max_heap.empty() && min_heap.empty()) 
			max_heap.push(num);
		else if (max_heap.size() == min_heap.size()) 
			max_heap.push(num);
		else 
			min_heap.push(num);

		if (!max_heap.empty() && !min_heap.empty() && max_heap.top() > min_heap.top())
		{
			int tmp = max_heap.top();
			max_heap.pop();
			max_heap.push(min_heap.top());
			min_heap.pop();
			min_heap.push(tmp);
		}
		cout << max_heap.top() << "\n";
	}
	
	return 0;
}
