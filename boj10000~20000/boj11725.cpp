#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <functional>
#include <cstring>
#include <stack>
#include <queue>

using namespace std;

vector<int> arr[100001];
int deep[100001];

void Makedeep(int a, int b)
{
  queue<pair<int,int>> q;
  q.push({a,b});
  while(!q.empty())
  {
    int idx = q.front().first;
    int deeps = q.front().second;
    
    q.pop();

    for(int i = 0;i<arr[idx].size();i++)
    {
      if(deep[arr[idx][i]] != -1)
        continue;
      deep[arr[idx][i]] = deeps;
      deeps++;
      q.push({arr[idx][i],deeps});
      deeps--;
    }
  }
}


int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int N;

  cin>>N;

  memset(deep,-1,sizeof(deep));

  for(int i = 0;i<N-1;i++)
  {
    int w1,w2;
    cin >> w1 >> w2;
    arr[w1].push_back(w2);
    arr[w2].push_back(w1);
  }
  deep[1] = 0;
  Makedeep(1,1);

  for(int i = 2 ;i<=N;i++)
  {
    int maximum = 987654321;
    int ans;
    for(int j = 0;j<arr[i].size();j++)
    {
      if(maximum > deep[arr[i][j]])
      {
        maximum = deep[arr[i][j]];
        ans = arr[i][j];
      }
    }
    cout<<ans<<"\n";
  }
  

	return 0;
}
