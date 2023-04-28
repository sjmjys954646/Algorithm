#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

int map[102][102] = {0,};
int visited[102][102] = {0,};
int M, N, K;
int mx[4] = {1,0,-1,0};
int my[4] = {0,1,0,-1};
int tmp = 0;

void dfs(int x,int y)
{
  for(int i = 0;i<4;i++)
  {
    int NX = x + mx[i];
    int NY = y + my[i];
    if(NX < 0 || NX >= M || NY < 0 || NY >= N)
      continue;
    if(map[NX][NY] == 1 || visited[NX][NY] == 1)
      continue;
    
    visited[NX][NY] = 1;
    tmp++;
    dfs(NX,NY);
  }
}

int main() 
{
  cin>>M>>N>>K;  

  for(int i = 0;i<K;i++)
  {
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    
    int row, col;
    row = x2 - x1;
    col = y2 - y1;
    for(int y = y1;y<y1+col;y++)
    {
      for(int x = x1;x<x1+row;x++)
      {
        map[y][x] = 1;
      }
    }
  }

  vector<int> ans;
  for(int i = 0;i<M;i++)
  {
    for(int j = 0;j<N;j++)
    {
      if(map[i][j] == 1 || visited[i][j] == 1)
        continue;
      visited[i][j] = 1;
      tmp = 1;
      dfs(i,j);
      ans.push_back(tmp);
    }
  }
  
  sort(ans.begin(),ans.end());
  cout<<ans.size()<<"\n";
  for(int i = 0;i<ans.size();i++)
  {
    cout<<ans[i]<<" ";
  }

	return 0;
}