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
    for(int i = 0;i<=n;i++)
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

int main() 
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M;
  cin >> N >> M;

  OS os(N);

  for(int i = 0;i<M;i++)
  {
    int order, a, b;
    cin >> order >> a >> b;
    if(order == 0)
    {
      os.merge(a,b);
    }
    else if(order == 1)
    {
      int p1, p2;
      p1 = os.find(a);
      p2 = os.find(b);
      if(p1 == p2)
        cout<<"YES"<<"\n";
      else
        cout<<"NO"<<"\n";
    }
  }


	return 0;
}