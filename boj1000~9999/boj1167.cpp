#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <math.h>
#include <queue>
using namespace std;

int V;
vector<pair<int,int> > graph[100001];
int dist[100001];
const int INF = 987654321;
int visit[100001];

void NDijkstra(int start)
{
  queue<int> q;
  q.push(start);
  visit[start] = 1;

  while(!q.empty())
  {
    int node = q.front();
    q.pop();

    for(auto k: graph[node])
    {
      if(visit[k.first] == 1)
        continue;

      int nextnode = k.first;
      q.push(nextnode);
      visit[nextnode] = 1;

      if(dist[nextnode] < k.second + dist[node])
      {
        dist[nextnode] = k.second + dist[node];
      }
    }
  }
}

int main() 
{
  cin >> V;
  
  int u1,u2,w;
  for(int i = 0; i < V;i++)
  {  
    cin >> u1;
    while(true)
    {
      cin >> u2;   
      if(u2==-1)
        break;
      cin >> w;
      graph[u1].push_back({u2,w});  
    }  
  }

  fill(dist,dist+100001,0);
  fill(visit,visit+100001,0);
  NDijkstra(1);
  int nans = -1;
  int index;
  for(int i = 1;i<=V;i++)
  {
    if(nans < dist[i])
    {
      nans = dist[i];
      index = i;
    }
  }
  fill(dist,dist+100001,0);
  fill(visit,visit+100001,0);
  NDijkstra(index);
  int ans = -1;
  for(int i = 1;i<=V;i++)
  {
    ans = max(ans,dist[i]);
  }

  cout<<ans;

	return 0;
}