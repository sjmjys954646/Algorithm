#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>
#define X first
#define Y second
using namespace std;
 
const int INF = 987654321;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int N;

	cin>> N;
	
	vector<int> arr;
	vector<int> arr2;
	
	arr.resize(N);
	arr2.resize(N);
	for(int i = 0;i<N;i++)
	{
		cin>>arr[i];
	}
	for(int i = 0;i<N;i++)
	{
		cin>>arr2[i];
	}
	sort(arr.begin(),arr.end());
	sort(arr2.begin(),arr2.end(),greater<int>());

	int sum = 0;
	for(int i = 0;i<N;i++)
	{
		sum+=arr[i]*arr2[i];
	}
	cout<<sum;
	return 0;
}