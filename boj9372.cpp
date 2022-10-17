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

int root[1002];
int N, M;
vector<int> arr[1001];
int visited[1001];
int ans = 0;

int find(int a)
{
  if(root[a] == a)
    return a;
  else
    return root[a] = find(root[a]);
}

void merge(int a, int b)
{
  a = find(a);
  b = find(b);
  root[a] = b;
}

void dfs(int a)
{
  for(int i = 0;i < arr[a].size();i++)
  {
    if(visited[arr[a][i]] == 1)
      continue;
    
    visited[arr[a][i]] = 1;
    ans++;
    dfs(arr[a][i]);
  }
}

int main() 
{
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int testcase;

  cin>>testcase;

  while(testcase--)
  {
    for(int i = 0;i<1001;i++)
    {
      arr[i].clear();
      visited[i] = 0;
    }
    ans = 0;
    
    cin >> N >> M;

    for(int i = 0;i<M;i++)
    {
      int a,b;
      cin >> a >> b;
      arr[a].push_back(b);
      arr[b].push_back(a);
    }

    dfs(1);

    cout<<ans-1<<"\n";
    
    
  }

	return 0;
}