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

long long arr[100001];
long long tree[400001];

void init(int node, int start, int end) 
{
	if (start == end) 
	{ 
		tree[node] = arr[start];
	}
	else 
	{
		init(node * 2, start, (start + end) / 2);
		init(node * 2 + 1, (start + end) / 2 + 1, end); 
		tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
	}
}

long long findsum(int node, int start, int end, int left, int right)
{
	if (left > end || right < start)
	{
		return 0;
	}
	if (left <= start && end <= right)
	{
		return tree[node];
	}
	int a =findsum(node * 2, start, (start + end) / 2, left, right);
	int b =findsum(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
	if (a == 0) return b;
	if (b == 0) return a;
	else return Min(a, b);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	
	int N, M;
	int a, b;

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	init( 1, 0, N-1);

	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		cout << findsum(1, 0, N-1, a-1, b-1) << "\n";
	}


	return 0;
}

