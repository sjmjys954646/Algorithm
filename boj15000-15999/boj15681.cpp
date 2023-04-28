#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <queue>
#include <iomanip>
using namespace std;

int N, R, Q;
int parent[100001];
vector<int> graph[100001];
int query[100001];

void setparent(int num)
{
  query[num] = 1;
  for(int i = 0;i<graph[num].size();i++)
  {
    int next = graph[num][i];
    if(parent[next] > 0 || next == R)
      continue;
    parent[next] = num;
    setparent(next);
    query[num] += query[next];
  }
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> N >> R >> Q;

  for(int i = 0;i<N-1;i++)
  {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  parent[R] = -1;
  setparent(R);

  for(int i = 0;i<Q;i++)
  {
    int a;
    cin>>a;
    cout<<query[a]<<"\n";
  }
  
	return 0;
}