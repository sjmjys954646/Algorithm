#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <queue>
using namespace std;

int V, E;
vector<pair<long long, long long>> arr[10002];
bool visit[10002];

int main() 
{
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin>>V>>E;

  for(int i = 0;i < E;i++)
  {
    long long u1,u2, d; 
    cin>> u1>>u2>>d;
    arr[u1].push_back({u2,d});
    arr[u2].push_back({u1,d});
  }

  priority_queue<pair<long long, long long>> pq;
  long long ans = 0;

  for(int i = 0;i<arr[1].size();i++)
  {
    long long next = arr[1][i].first;
    long long dis = arr[1][i].second;
    pq.push({-dis,next});
  }
  visit[1] = true;
  while(!pq.empty())
  {
    long long dis = -pq.top().first;
    long long cur = pq.top().second;
    pq.pop();

    if(visit[cur] == false)
    {
      visit[cur] = true;
      ans+=dis;
      for(int i = 0;i<arr[cur].size();i++)
      {
        long long next = arr[cur][i].first;
        long long ndis = arr[cur][i].second;
        if(visit[next] == false)
          pq.push({-ndis,next});
      }
    }
  }

  cout<<ans;

	return 0;
}