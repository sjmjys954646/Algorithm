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
vector<long long> arr;
vector<int> selected;
int visited[21];
long long ret = -2147483650;

long long cal()
{
  vector<long long> tarr;
  tarr.assign(arr.begin(),arr.end());
  for(int i = 0;i<selected.size();i+=2)
  {
    long long a = tarr[selected[i]];
    long long b = tarr[selected[i+1]];
    long long sign = tarr[selected[i]+1];
    long long res;

    if(sign == 43)
    {
      res = a+b;
    }
    else if(sign == 45)
    {
      res = a-b;
    }
    else if(sign == 42)
    {
      res = a*b;
    }
    tarr[selected[i]] = res;
    tarr[selected[i+1]] = -2147483650;
    tarr[selected[i]+1] = -2147483650;
  }

  queue<long long> q;
  for(int i = 0;i<tarr.size();i++)
  {
    if(tarr[i]!=-2147483650)
      q.push(tarr[i]);
  }

  long long result = q.front();
  q.pop();
  int p = 0;
  while(!q.empty())
  {  
    if(q.front() == 43)
    {
      q.pop();
      result+=q.front();
      q.pop();
    }
    else if(q.front() == 45)
    {
      q.pop();
      result-=q.front();
      q.pop();
    }
    else if(q.front() == 42)
    {
      q.pop();
      result*=q.front();
      q.pop();
    }
  }
  return result;
}

void solve(int size,int pos)
{
  if(selected.size() == size)
  {  
    // for(int i = 0;i<selected.size();i++)
    // {
    //   cout<<selected[i]<<" ";
    // }
    // cout<<"\n";
    ret = max(ret,cal());
    //cout<<size<<" "<<ret<<"\n";
  }

  for(int i = pos;i<N-1;i+=2)
  {
    if(visited[i]==1)
      continue;
    selected.push_back(i);
    selected.push_back(i+2);
    visited[i] = 1;
    visited[i+2] = 1;
    solve(size,i+4);
    selected.pop_back();
    selected.pop_back();
    visited[i] = 0;
    visited[i+2] = 0;
  }
}

int main() 
{
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N;

  string tmp;
  cin >> tmp;

  memset(visited,0,sizeof(visited));

  for(int i = 0;i<N;i++)
  {
    if(i%2==0)
      arr.push_back(tmp[i] - 48);
    else
      arr.push_back(tmp[i]);
  }

  if(N==1)
  {
    cout<<arr[0];
    exit(0);
  }

  long long ans = -2147483650;

  for(int i = 0;i*2<N;i++)
  {
    solve(i*2,0);
    ans = max(ans,ret);
  }

  cout<<ans;

	return 0;
}