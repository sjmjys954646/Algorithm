#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <queue>
#include <stack>
using namespace std;

int N, M;
vector<int> arr[32010];
bool visited[32010];
bool finish[32010];
int cycle = 0;
stack<int> st;

void dfs(int here)
{
  visited[here] = true;
  for(int i = 0;i < arr[here].size();i++)
  {
    if(visited[arr[here][i]] == false)
    {
      dfs(arr[here][i]);
    }
    else if(finish[arr[here][i]] == false)
    {
      cycle = 1;
    }
  }
  finish[here] = true;
  st.push(here);
}

int main() 
{
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N >> M;

  for(int i = 0;i<M;i++)
  {
    int a, b;
    cin >> a >> b;
    arr[a].push_back(b);
  }

  for(int i = 1;i<=N;i++)
  {
    if(!visited[i])
      dfs(i);
  }

  while(st.size())
  {
    cout<<st.top()<<" ";
    st.pop();
  }

	return 0;
}