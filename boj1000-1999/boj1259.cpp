#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#define X first
#define Y second

using namespace std;

const int INF = 987654321;

int main()
{
	string N;
	
	while(true)
	{
		cin >> N;
		
		if(N=="0")
		{
			break;
		}
		
		bool check = true;
		for(int i = 0;i < N.length()/2;i++)
		{
			if(N[i]!=N[N.length()-i-1])
			{
				check = false;
				break;
			}
		}
		if(check)
		{
			cout<<"yes\n";
		}
		else
		{
			cout<<"no\n";
		}
		
	}
	
	return 0;
}