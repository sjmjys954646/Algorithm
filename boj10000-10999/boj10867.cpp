#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <algorithm>
#define X first
#define Y second
using namespace std;

const int INF = 987654321;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int arr[2004];
	int N;
	
	memset(arr,-1,sizeof(arr));
	
	cin>>N;
	for(int i = 0;i<N;i++)
	{	
		int t;
		cin>>t;
		arr[t+1000]++;
	}
	
	for(int i = 0;i<2003;i++)
	{	
		if(arr[i]!=-1)
		{
			cout<<i-1000<<" ";
		}
	}
	
	return 0;
}