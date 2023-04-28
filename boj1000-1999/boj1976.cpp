#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

typedef struct OptimizedSet
{
  vector<int> parent, rank;
  OptimizedSet(int n) : parent(n+1),rank(n+1,1)
  {
    for(int i = 1;i<=n;i++)
    {
      parent[i] = i;
    }
  }
  int find(int u)
  {
    if(u==parent[u])
      return u;
    
    return parent[u] = find(parent[u]);
  }
  void merge(int u, int v)
  {
    u = find(u);
    v = find(v);
    if(u==v)
      return;

    if(rank[u] > rank[v])
      swap(u,v);
    
    parent[u] = v;

    if(rank[u] == rank[v])
      ++rank[v];
  }
}OS;

int matrix[201][201];

int main() 
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M;
  cin >> N >> M;

  OS os(N);

  for(int i = 0;i<N;i++)
  {
    for(int j = 0;j<N;j++)
    {
      cin >> matrix[i][j];
    }
  }

  for(int i = 0;i<N;i++)
  {
    for(int j = i;j<N;j++)
    {
      if(matrix[i][j]==1)
        os.merge(i+1,j+1);
    }
  }

  vector<int> arr(M);

  for(int i = 0;i<M;i++)
  {
    cin>>arr[i];
  }

  bool ok = true;
  int p = os.find(arr[0]);
  for(int i = 1;i<M;i++)
  {
    int a = os.find(arr[i]);
    if(a != p)
    {
      ok = false;
      break;
    }
  }

  if(ok)
    cout<<"YES";
  else
    cout<<"NO";

	return 0;
}