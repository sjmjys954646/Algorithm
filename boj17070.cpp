#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int arr[20][20];
int N;
int tnext[3][2] = {{1,0},{1,1},{0,1}};

int BFS(int y, int x)
{
  queue<pair<int,int> > q;
  queue<int> bef;//0 = 가로 1= 세로 2 = 대각선
  q.push({y,x});
  bef.push(0);

  int ans = 0;

  while(!q.empty())
  {
    int posY = q.front().first;
    int posX = q.front().second;
    int pos = bef.front();
    int nexY;
    int nexX;

    q.pop();
    bef.pop();

    if(posX==N-1 && posY==N-1)
    {
      ans++;
    }

    if(pos == 0)
    {
      for(int i = 1;i<3;i++)
      {
        nexY = posY + tnext[i][0];
        nexX = posX + tnext[i][1];

        if(nexY < 0 || nexX < 0 || nexY >= N || nexX >= N)
        {
          continue;
        }

        if(i==1 && (arr[nexY][nexX] == 1||arr[nexY-1][nexX] == 1||arr[nexY][nexX-1] == 1))
          continue;
        if(i==2 && arr[nexY][nexX] == 1)
          continue;
        

        q.push({nexY,nexX});
        if(i==1)
          bef.push({2});
        if(i==2)
          bef.push({0});
      } 
    }
    if(pos == 1)
    {
      for(int i = 0;i<2;i++)
      {
        nexY = posY + tnext[i][0];
        nexX = posX + tnext[i][1];

        if(nexY < 0 || nexX < 0 || nexY >= N || nexX >= N)
        {
          continue;
        }

        if(i==0 && arr[nexY][nexX] == 1)
          continue;
        if(i==1 && (arr[nexY][nexX] == 1||arr[nexY-1][nexX] == 1||arr[nexY][nexX-1] == 1))
          continue;
        if(i==2 && arr[nexY][nexX] == 1)
          continue;

        q.push({nexY,nexX});
        if(i==0)
          bef.push({1});
        if(i==1)
          bef.push({2});
        
      } 
    }
    if(pos == 2)
    {
      for(int i = 0;i<3;i++)
      {
        nexY = posY + tnext[i][0];
        nexX = posX + tnext[i][1];

        if(nexY < 0 || nexX < 0 || nexY >= N || nexX >= N)
        {
          continue;
        }

        if(i==0 && arr[nexY][nexX] == 1)
          continue;
        if(i==1 && (arr[nexY][nexX] == 1||arr[nexY-1][nexX] == 1||arr[nexY][nexX-1] == 1))
          continue;
        if(i==2 && arr[nexY][nexX] == 1)
          continue;

        q.push({nexY,nexX});
        if(i==0)
          bef.push({1});
        if(i==1)
          bef.push({2});
        if(i==2)
          bef.push({0});
      } 
    }
  }
  return ans;
}


int main() 
{
  cin >> N;
  for(int i = 0;i<N;i++)
  {
    for(int j = 0;j<N;j++)
    {
      cin>>arr[i][j];
    }
  }

  cout<<BFS(0,1);
  
	return 0;
}