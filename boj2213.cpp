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

int N;
int cost[10002];
vector<int> graph[10002];
int cache[10002][2];
bool visited[10002];
vector<int> chd[10002];
vector<int> selected;

pair<int, int> dp(int a)
{
  cache[a][0] = cost[a];
  cache[a][1] = 0;
  visited[a] = true;

  for(int i = 0;i < graph[a].size();i++)
  {
    int k = graph[a][i];
    if(!visited[k])
    {
      pair<int, int> pii = dp(k);
      cache[a][0]+=pii.second;;
      cache[a][1]+=max(pii.first,pii.second);
    }  
  }
  return {cache[a][0],cache[a][1]};
}

void find(int cur, bool tog)
{
  bool sel = false;
  visited[cur] = true;
  if(tog == false && cache[cur][0] > cache[cur][1])
  {
    sel=true;
    selected.push_back(cur);
  }

  for(int i = 0;i < graph[cur].size();i++)
  {
    int k = graph[cur][i];
    if(!visited[k])
      find(k,sel); 
  }


}

int main() 
{
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int tmp;
  int a, b;

  cin >> N;

  for(int i = 1;i<=N;i++)
  {
    cin>>tmp;
    cost[i] = tmp;
  }

  for(int i = 0;i<N-1;i++)
  {
    cin>>a>>b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  dp(1);

  cout<<max(cache[1][0],cache[1][1])<<"\n";

  fill(visited,visited+10002, false);
  find(1,false);
  sort(selected.begin(),selected.end());
  for(int i = 0;i<selected.size();i++)
  {
    cout<<selected[i]<<" ";
  }

	return 0;
}