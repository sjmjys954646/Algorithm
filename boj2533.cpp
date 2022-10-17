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
vector<int> graph[1000003];
bool visited[1000003];
int cache[1000003][2];

int dp(int here, int early)
{
  int &ret = cache[here][early];
  if(ret!=-1)
    return ret;

  int retEarly = 0;
  int retNEarly = 0;

  visited[here] = true;
  for(int i = 0;i<graph[here].size();i++)
  {
    int next = graph[here][i];
    if(visited[next] == true) 
      continue;

    retEarly+=min(dp(next,0),dp(next,1));

    if(early==0)
      retNEarly+=dp(next,1);
  }

  retEarly+=1;
  visited[here] = false;

  if(early==0)
    return ret = min(retEarly,retNEarly);
  
  return ret = retEarly;
}

int main() 
{
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin>>N;

  int a, b;

  for(int i = 0;i<N-1;i++)
  {
    cin>>a>>b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }
  fill(&cache[0][0], &cache[1000003][2], -1);

  cout<<dp(1,0);

	return 0;
}