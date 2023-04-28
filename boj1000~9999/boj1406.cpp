#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>
#include <stdio.h>
#include <string.h>
#include <list>
#define X first
#define Y second
using namespace std;
 
const int INF = 987654321;
 
int main()
{
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cout.tie(0);
	
	char S[100005];
	list<char> L;
	scanf("%s",S);
	
	int len = strlen(S);
	
	for(int i = 0;i<len;i++)
	{
		L.push_back(S[i]);
	}
	
	auto it = L.end();
	
	int N;
	cin>> N;
	
	for(int i = 0;i<N;i++)
	{
		char command[3];
		scanf("%s",command);
		if(command[0]=='L')
		{
			if(it!=L.begin())
				it--;
		}
		else if(command[0]=='D')
		{
			if(it!=L.end())
				it++;
		}
		else if(command[0]=='B')
		{
			if (it != L.begin()) 
			{
                it--;
                it = L.erase(it);
            }
		}
		else if(command[0]=='P')
		{
			char in[3];
			scanf("%s",in);
			L.insert(it,in[0]);
		}
		
	}
	
	for(auto k = L.begin();k!=L.end();k++)
	{
		cout<<*k;
	}
	
	return 0;
}