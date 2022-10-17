#include <iostream>

using namespace std;

int arr[10000002];

int main()
{
	
	int M, N;
	
	cin>>M>>N;
	
	for(int i =1;i<10000002;i++)
		arr[i] = i;
	
	for(int i =2;i<10000002;i++)
	{
		for(int k = 2;i*k<10000002;k++)
		{	
			arr[i*k] = 0;
		}	
	}
	
	arr[1] = 0;

	for(int i =M;i<=N;i++)
	{
		if(arr[i]!=0)
			cout<<i<<"\n";
	}
	
	return 0;
}