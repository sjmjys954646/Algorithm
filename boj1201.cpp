#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>
#include <deque>
#define X first
#define Y second
using namespace std;

const int INF = 987654321;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

  int N,M,K;
  vector<int> arr;

  cin>>N>>M>>K;

  arr.resize(N);

  if(M+K-1 <= N && N <= M*K)
  {
    for(int i = 0;i<N;i++)
      arr[i] = i+1;
    
    int index = 0;
    for(int i = 1;i<=M;i++)
    {
      int tmp = min(index + K, N-M+i);
      reverse(arr.begin() + index, arr.begin() + tmp);
      index = tmp;
    }

    for(int i = 0;i<N;i++)
    {
      cout<<arr[i]<<" ";
    }
  }
  else
    cout<<-1<<"\n";

	return 0;
}