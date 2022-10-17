#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#define X first
#define Y second
using namespace std;

int N;
vector<int> S;
int ans[6];

void Search(int num, int index)
{
	if(index==6)
	{
		for(int i = 0;i<6;i++)
		{
			cout<<ans[i]<<" ";
		}
		cout<<"\n";
		return;
	}
	
	for(int i = num;i<N;i++)
	{
		ans[index] = S[i];
		Search(i+1,index+1);
	}
}

int main()
{
	while(true)
	{
		cin >> N;
		
		if(N==0)
			break;
		
		S.resize(N);
		
		for(int i = 0;i<N;i++)
		{
			cin >> S[i];
		}
		Search(0,0);
		cout<<"\n";
	}	

	return 0;
}