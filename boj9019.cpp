#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <stdio.h>
#include <string>
#include<string.h>
#include <math.h>
#include <map>
#include <queue>
#define X first
#define Y second

using namespace std;

vector<int> graph[10002];
int check[10002];
pair<char,int> before[10002];
queue<int> q;
int N, K;
vector<char> arr;

void bfs(int s)
{
	q.push(s);
	check[s] = 1;

	while (!q.empty())
	{   
		int tmp = q.front();
		q.pop();

		if (tmp == K)
			break;

		for (int i = 0; i < graph[tmp].size(); i++) 
		{
			if (check[graph[tmp][i]] == 0)
			{
				q.push(graph[tmp][i]);
				  
        if(graph[tmp][i] == tmp - 1 || (tmp == 0 && graph[tmp][i] == 9999))
        {
          before[graph[tmp][i]].first = 'S';
          before[graph[tmp][i]].second = tmp;
          check[graph[tmp][i]] = check[tmp] + 1;
        }
        else if(graph[tmp][i] == 2*tmp%10000)
        {
          before[graph[tmp][i]].first = 'D';
          before[graph[tmp][i]].second = tmp;
          check[graph[tmp][i]] = check[tmp] + 1;
        }
        else if(graph[tmp][i] == tmp*10%10000+(tmp/1000))
        {
          before[graph[tmp][i]].first = 'L';
          before[graph[tmp][i]].second = tmp;
          check[graph[tmp][i]] = check[tmp] + 1;
        }
        else if(graph[tmp][i] == tmp/10+(tmp%10)*1000)
        {
          before[graph[tmp][i]].first = 'R';
          before[graph[tmp][i]].second = tmp;
          check[graph[tmp][i]] = check[tmp] + 1;
        }      
			}
		}
	}
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

  int testcase;
  cin>>testcase;
  while(testcase--)
  {
    cin >> N >> K;
    memset(check, 0, sizeof(check));
    memset(before,0,sizeof(before));
    for (int i = 0; i < 10000; i++)
	  {
		  graph[i].clear();
  	}
    while(!q.empty())
    {
      q.pop();
    }
    arr.clear();

    graph[0].push_back(9999);
    
	  for (int i = 1; i < 10000; i++)
	  {
		  graph[i].push_back(i - 1);
		  graph[i].push_back(2*i%10000);
	  	graph[i].push_back(i*10%10000+(i/1000));
      graph[i].push_back(i/10+(i%10)*1000);
  	}

    bfs(N);

    int p = K;
    int i = 1;

    while(true)
    {
      if(p==N)
        break;     
      //cout<<p<<"\n";
      arr.push_back(before[p].first);      
      p = before[p].second;
    }

    reverse(arr.begin(),arr.end());

    for(int i = 0;i<arr.size();i++)
    {
      cout<<arr[i];
    }
    cout<<"\n";
  }

	return 0;
}
