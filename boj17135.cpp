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

int arr[20][20];
int N, M, D;
vector<int> selectedPos;
int nX[4] = {-1,0,1,0};
int nY[4] = {0,-1,0,1};
int ans = -1;

vector<pair<int,int> > BFS(int board[][20])
{
  vector<pair<int,int> > Arch(3);
  vector<pair<int,int> > Ene(3);

  for(int i = 0;i<3;i++)
  {
    Arch[i].first = N;
    Arch[i].second = selectedPos[i];
    Ene[i].first = -1;
    Ene[i].second = -1;
  }
  
  for(int t = 0;t<3;t++)
  {
    queue<pair<int,pair<int,int> > > q; //거리, <Y,X>
    q.push({0,{Arch[t].first,Arch[t].second}});

    while(!q.empty())
    {
      int curY = q.front().second.first;
      int curX = q.front().second.second;
      int dis = q.front().first + 1;
      q.pop();

      for(int i = 0;i<3;i++)
      {
        int nextY = curY + nY[i];
        int nextX = curX + nX[i];

        if(nextX < 0 || nextY < 0 || nextX >= M || nextY > N)
          continue;
        
        if(dis>D)
          continue;

        if(board[nextY][nextX] == 1)
        {
          Ene[t].first = nextY;
          Ene[t].second = nextX;
          break;
        }
        q.push({dis,{nextY,nextX}});
      }

      if(Ene[t].first >= 0 && Ene[t].second >= 0)
        break;
    }

  }

  return Ene;
}

bool finish(int board[][20])
{
  int enemyleft = 0;
  for(int i = 0;i<N;i++)
  {
    for(int j = 0;j<M;j++)
    {
      if(board[i][j] == 1)
        enemyleft++;
    }
  }
  if(!enemyleft) 
    return true;
  else
    return false;
}

  
int Simulating()
{
  int simulBoard[20][20];
  copy(&arr[0][0], &arr[0][0]+20*20, &simulBoard[0][0]);
  int kill = 0;
  ////DEBUG////
  // for(int i = 0;i<3;i++)
  // {
  //   cout<<selectedEne[i].first<<" "<<selectedEne[i].second<<"\n";
  // }
  // cout<<"\n";   
  ////DEBUG////
  while(!finish(simulBoard))
  {

    vector<pair<int,int> > selectedEne = BFS(simulBoard);
    for(int i = 0;i<3;i++)
    {
      int killY = selectedEne[i].first;
      int killX = selectedEne[i].second;

      if( killY == -1 || killX == -1)
        continue;
      
      if(simulBoard[killY][killX] == 1)
      {
        kill++;
        simulBoard[killY][killX] = 0;
      }
    }
    for(int i = N-1;i>=0;i--)
    {
      for(int j = M-1;j>=0;j--)
      {
        if(simulBoard[i][j]==1)
        {
          simulBoard[i][j] = 0;
          if(i!=N-1)
            simulBoard[i+1][j] = 1;
        }
      }
    }
    ////DEBUG////
    // for(int i = 0;i<N;i++)
    // {
    //   for(int j = 0;j<M;j++)
    //   {
    //     cout<<simulBoard[i][j]<<" ";
    //   }
    //   cout<<"\n";
    // }
    // cout<<"\n";
    ////DEBUG////
  }

  return kill;  
}

void ArcherPos(int pos)
{
  if(selectedPos.size() == 3)
  {
    ////DEBUG////
    // for(int i = 0;i<selectedPos.size();i++)
    // {
    //   cout<<selectedPos[i]<<" ";
    // }
    // cout<<"\n";
    ////DEBUG////
    int tmp = Simulating();
    ans = max(ans,tmp);
    //처치적기록 갱신
  }

  for(int i = pos;i<M;i++)
  {
    selectedPos.push_back(i);
    ArcherPos(i+1);
    selectedPos.pop_back();
  }
}

int main() 
{
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N >> M >> D;

  for(int i = 0;i<N;i++)
  {
    for(int j = 0;j<M;j++)
    {
      cin>>arr[i][j];
    }
  }

  ArcherPos(0);
  cout<<ans;

	return 0;
}