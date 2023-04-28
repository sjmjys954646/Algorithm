#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> arr;

int GCD(int a, int b)
{
	while(b> 0)
	{
		int tmp = b;
		b = a%b;
		a = tmp;
	}
	return a;
	
	/*if(b == 0)
		return a;
	GCD(b , a%b);*/
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>N;
	arr.resize(N);
	
	for(int i = 0;i<N;i++)
	{
		cin>>arr[i];
	}
	sort(arr.begin(),arr.end());
	
	int p = GCD(arr[2] - arr[1],arr[1] - arr[0]);
	for(int i = 1;i<N-1;i++)
	{
		p = GCD(p,arr[i+1] - arr[i]);
	}
	cout<<(arr[N-1] - arr[0])/p - N + 1;
	
	return 0;
}