#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#define X first
#define Y second
using namespace std;

int N, S;
vector<int> arr;
int selected[21];
int ans = 0;

void select(int goal, int index,int start)
{
	if(index == goal)
	{
		int t= 0;
		for(int i =0;i<goal;i++)
		{
			t+=selected[i];
		}
		if(t==S)
			ans++;
		return;
	}
	
	for(int i = start;i<N;i++)
	{
		selected[index] = arr[i];
		select(goal,index+1,i+1);
	}
}

int main() 
{
	cin >> N >> S;
	arr.resize(N);

	for(int i = 0;i<N ;i++)
	{
		cin >> arr[i];
	}
	
	for(int i = 1;i<=N;i++)
	{
		select(i,0,0);
	}
	cout<<ans;
	
	return 0;
}