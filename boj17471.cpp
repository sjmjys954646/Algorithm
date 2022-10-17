#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>
#include <queue>
#define X first
#define Y second
using namespace std;

const int INF = 987654321;
 
int N;
int ans = INF;
int pop[11];       
vector<int> arr[11]; 
bool Select[11];        
bool Visit[11];        

 
bool Check_Connection(vector<int> V, bool T)
{
    
    memset(Visit, false, sizeof(Visit));
    queue<int> q;
    q.push(V[0]);        
    Visit[V[0]] = true;
    int Cnt = 1;
 
    while (!q.empty())
    {
        int here = q.front();
        q.pop();
        for (int i = 0; i < arr[here].size(); i++)
        {
            if (Select[arr[here][i]] == T && Visit[arr[here][i]] == false)
            {
                Visit[arr[here][i]] = true;
                Cnt++;     
                q.push(arr[here][i]);
            }
        }
    }
 

    if (V.size() == Cnt) return true;
    return false;
}
 
bool Check()
{
 
    vector<int> A, B;
    for (int i = 1; i <= N; i++)
    {
        if (Select[i] == true) A.push_back(i);
        else B.push_back(i);                   
    }
 
    if (A.size() == 0 || B.size() == 0) 
      return false;
 
    if (!Check_Connection(A, true)) 
      return false;
 
    if (!Check_Connection(B, false)) 
      return false;
 
    return true;
}
 
void Calculate()
{
    int A, B, Diff;
    A = B = 0;
 
    for (int i = 1; i <= N; i++)
    {
        if (Select[i] == true) A += pop[i];
        else B += pop[i];
    }
    if (ans > abs(A - B)) ans = abs(A - B);
}
 
void DFS(int Idx, int Cnt)
{
    if (Cnt >= 1)
    {    
        if (Check() == true)
        {
          Calculate();
        }
    }
 
    for (int i = Idx; i <= N; i++)
    {
        if (Select[i] == true) continue;
        Select[i] = true;
        DFS(i, Cnt + 1);
        Select[i] = false;
    }
}


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> pop[i];
	}

	for (int i = 1; i <= N; i++)
	{
		int p;
		cin >> p;
		for (int j = 0; j < p; j++)
		{
			int tmp;
			cin >> tmp;
			arr[i].push_back(tmp);
		}
	}
 
  DFS(1, 0);   
 
 if (ans == INF)
		cout << -1;
	else
		cout << ans;
  return 0;
}

