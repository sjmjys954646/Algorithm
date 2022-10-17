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

int root[7];
int N, M;
int arr[11][11];
int isl[11][11];
int kx[4] = {1,-1,0,0};
int ky[4] = {0,0,1,-1};
vector<pair<int, pair<int, int> > > vec;

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
  root[b] = a;
}

void bfs(int y, int x, int idx)
{
  queue<pair<int,int> > q;
  q.push({y,x});
  isl[y][x] = idx;

  while(!q.empty())
  {
    int tmy = q.front().first;
    int tmx = q.front().second;
    q.pop();

    for(int i=0;i<4;i++)
    {
      int ny = tmy + ky[i];
      int nx = tmx + kx[i];
      if(nx< 0 || ny < 0 || nx >= M || ny >= N)
        continue;
      if(arr[ny][nx] == 0)
        continue;
      if(isl[ny][nx]!=0)
        continue;

      q.push({ny,nx});
      isl[ny][nx] = idx;
    }
  }
}

void bridge(int u, int v)
{
  queue<pair<int,int> > q;

  for (int i = 0; i < N; i++) 
  {
    for (int j = 0; j < M; j++) 
    {
      if (isl[i][j] == u) 
      {
        q.push(make_pair(i, j));
      }
    }
  }

  int mindist = 10;
  while(!q.empty())
  {
    int y = q.front().first;
    int x = q.front().second;
    q.pop();
    for(int i = 0;i<4;i++) 
    {
      int nx = x + kx[i];
      int ny = y + ky[i];
      int dist = 0;

      while(true)
      {
        if(nx< 0 || ny < 0 || nx >= M || ny >= N)
          break;
        if(isl[ny][nx] == u)
          break;
        
        if(isl[ny][nx] == v)
        {
          if(dist >= 2 && mindist > dist)
            mindist = dist;
          
          break;
        }
        else if(isl[ny][nx] == 0)
        {
          dist++;
          nx+=kx[i];
          ny+=ky[i];
        }
        else  
          break;
      }
    }
  }
  if(mindist!=10)
    vec.push_back({mindist,{u,v}});
}

int main() 
{
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N >> M;

  for(int i = 0;i<N;i++)
  {
    for(int j = 0;j<M;j++)
    {
      cin>>arr[i][j];
    }
  }

  int idx = 0;
  for(int i = 0;i<N;i++)
  {
    for(int j = 0;j<M;j++)
    {
      if(arr[i][j] ==0 || isl[i][j]!=0)
        continue;
      
      bfs(i,j,++idx);
    }
  }

  for(int i = 1;i<idx;i++)
  {
    for(int j = i+1;j<=idx;j++)
    {
      bridge(i,j);//i->j로 가는 다리
    }
  }

  sort(vec.begin(),vec.end());

  for(int i = 1;i<=idx;i++)
  {
    root[i] = i;
  }

  int sum = 0;
  int cnt = 0;
  int index = 0;
  int size = vec.size();
  int u,v,dist;

  while(cnt < idx - 1)
  {
    if(index == size)
    {
      cout<<-1<<"\n";
      return 0;
    }

    dist = vec[index].first;
    u = vec[index].second.first;
    v = vec[index].second.second;

    index++;
    if(find(u) == find(v))
      continue;
    else
    {
      merge(u,v);
      cnt++;
      sum+=dist;
    }
  }
  cout<<sum<<"\n";

	return 0;
}