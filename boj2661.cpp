#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
using namespace std;

vector<int> arr;
int N;

bool check()
{
	int len = arr.size();
	
	for(int i = 1;i<=len/2;i++)
	{
		string s1 = "";
		string s2 = "";
		
		for(int j = 0;j<i;j++)
		{
			s1+=to_string(arr[len - 2*i + j]);
			s2+=to_string(arr[len - i + j]);
		}
		
		if(s1 == s2) return false;
	}
	return true;
}

void dfs(int num)
{
	if(num == N)
	{
		for(int i = 0;i<arr.size();i++)
		{
			cout<<arr[i];
		}
		exit(0);
	}
	
	for(int i = 1;i<=3;i++)
	{
		arr.push_back(i);
		if(check())
		{
			dfs(num+1);
		}
		
		arr.pop_back();
	}
}

int main() 
{

	scanf("%d",&N);
	
	dfs(0);
	
	
	return 0;
}