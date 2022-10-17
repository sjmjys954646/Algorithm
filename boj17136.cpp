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

const int INF = 987654321;

int arr[10][10];
int ans = INF;
int papercnt[6];

bool pos(int x,int y, int l, int narr[10][10])
{
  for(int i = x;i<x+l;i++)
  {
    for(int j = y;j<y+l;j++)
    {
      if(i >= 10 || j>= 10)
        return false;

      if(narr[i][j] == 0)
        return false;
    }
  }
  return true;
}

void solve(int narr[10][10],int use)
{
  int x,y;
  bool flg = false;

  for(int i = 0;i<10;i++)
  {
    for(int j = 0;j<10;j++)
    {
      if(narr[i][j] == 1)
      {
        x=i;
        y=j;
        flg = true;
        break;
      }
    }
    if(flg)
      break;
  }

  if(!flg)
  {
    if(ans > use)
      ans = use;
    return;
  }

  for(int i = 5;i>0;i--)
  {
    if(papercnt[i] == 0)
      continue;

    if(!pos(x,y,i,narr))
      continue;

    papercnt[i]-=1;

    int newtmp[10][10];
    copy(&narr[0][0], &narr[0][0]+10*10, &newtmp[0][0]);

    for(int j = x;j<x+i;j++)
    {
      for(int k = y;k<y+i;k++)
      {
        newtmp[j][k] = 0;
      }
    }

    solve(newtmp,use+1);

    papercnt[i]+=1;
  }

}

int main() 
{
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  for(int i = 0;i<10;i++)
  {
    for(int j = 0;j<10;j++)
    {
      cin>>arr[i][j];
    }
  }

  for(int i = 1;i<6;i++)
  {
    papercnt[i] = 5;
  }
  
  solve(arr,0);

  if(ans==INF)
    cout<<-1<<"\n";
  else
    cout<<ans<<"\n";

	return 0;
}