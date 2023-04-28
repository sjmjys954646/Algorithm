#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <cstring>
#include <stack>
#include <queue>

using namespace std;

const int INF = 987654321;
int N, M;
vector<pair<int,int> > graph[1001];
vector<int> dist;
int start,fin;
int before[1001];

void Dijkstra()
{
  priority_queue<pair<int,int> > pq;
  pq.push({start,0});
  dist[start] = 0;
  before[start] = -1;

  while(!pq.empty())
  {
    int cur = pq.top().first;
    int cost = pq.top().second;

    pq.pop();

    if(dist[cur] < cost)
      continue;

    for(auto k : graph[cur])
    {
      int next = k.first;
      int nextcost = k.second + cost;

      if(dist[next] > nextcost)
      {
        dist[next] = nextcost;
        pq.push({next,nextcost});
        before[next] = cur;
      }
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  for(int i =0;i<M;i++)
  {
    int w1, w2, cost;
    cin >> w1 >> w2 >> cost;
    graph[w1].push_back({w2,cost});
  }
  dist.resize(N+1);

  cin>>start>>fin;

	fill(dist.begin(), dist.end(), INF);
  Dijkstra();

  cout<<dist[fin]<<"\n";;
 
  int t = fin;
  stack<int> s;

  while(t>=0)
  {  
    s.push(t);
    t = before[t];
  }

  cout<<s.size()<<"\n";

  while(!s.empty())
  {
    int p = s.top();
    cout<<p<<" ";
    s.pop();
  }


	return 0;
}
