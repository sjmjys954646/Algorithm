#include<iostream>
#include<cstring>
using namespace std;

int V, E;
int graph[401][401];
const int INF = 987654321;

int main() 
{
	cin>>V>>E;
	
	for(int i = 0;i<401;i++)
	{
		for(int j = 0;j<401;j++)
		{
			graph[i][j] = INF;
		}
	}
	
	for(int i = 0;i<E;i++)
	{
		int v1, v2, d;
		cin >> v1 >> v2 >>d;
		graph[v1][v2] = min(graph[v1][v2],d);
	}
	
	for (int k = 1; k <= V; k++)
	{
		for (int j = 1; j <= V; j++)
		{
			for (int i = 1; i <= V; i++)
			{
				graph[i][j] = min(graph[i][j],graph[i][k]+graph[k][j]);
			}
		}
	}
	int ans = INF-1;
	for(int i = 1;i<=V;i++)
	{
		for(int j = 1;j<=V;j++)
		{
			ans = min(ans,graph[i][j] + graph[j][i]);
		}
	}
	if(ans == INF-1)
		cout<<-1;
	else
		cout<<ans;
	
	return 0;
}