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
	
	int N, M;
	vector<int> arr;
	
	cin >> N;
	arr.resize(N);
	
	for(int i = 0;i<N;i++)
	{
		cin>>arr[i];
	}
	sort(arr.begin(),arr.end());

	cin>>M;
	for(int i = 0;i<M;i++)
	{
		int t;
		cin>>t;
		cout<<binary_search(arr.begin(),arr.end(),t)<<" ";
	}
	
	return 0;
}