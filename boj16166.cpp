#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define range(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int INF = 987654321;

vi graph[15];
vi arr[15];
map<long long , int> m;

int N;
int ans = INF;
int findNum;
int visited[15];
vi startpointHubo;
int startpoint;

void bfs()
{
	
	queue<pii> q;
	for (int i = 0; i < arr[startpoint].size(); i++)
	{
		if (arr[startpoint][i] == findNum)
		{
			ans = 0;
			break;
		}
	}

	if (ans == 0)
		return;

	visited[startpoint] = 1;
	q.push({ startpoint,0 });

	while (!q.empty())
	{
		int cur = q.front().F;
		int depth = q.front().S;
		q.pop();
		for (int i = 0; i < arr[cur].size(); i++)
		{
			if (arr[cur][i] == findNum)
			{
				ans = min(depth, ans);
			}
		}

		for (int i = 0; i < graph[cur].size(); i++)
		{
			if (visited[graph[cur][i]])
				continue;

			q.push({ graph[cur][i], depth + 1 });
			visited[graph[cur][i]] = 1;
		}

	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	int t;
	long long tmp;
	int index = 1;
	for (int i = 0; i < N; i++)
	{
		cin >> t;

		for (int j = 0; j < t; j++)
		{
			cin >> tmp;

			if (tmp == 0)
				startpointHubo.push_back(i);

			if (m.find(tmp) == m.end())
			{
				m[tmp] = index;
				tmp = index;
				index++;
			}
			else
			{
				tmp = m[tmp];
			}

			arr[i].push_back(tmp);
		}
	}

	cin >> findNum;
	findNum = m[findNum];

	//cout << "findNUm : " << findNum << "\n";

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < arr[i].size(); j++)
		{
			int cur = arr[i][j];
			for (int k = i + 1; k < N; k++)
			{
				for (int l = 0; l < arr[k].size(); l++)
				{
					if (cur == arr[k][l])
					{
						graph[i].push_back(k);
						graph[k].push_back(i);
					}
				}
			}
		}
	}

	for (int i = 0; i < startpointHubo.size(); i++)
	{
		memset(visited, 0, sizeof(visited));
		startpoint = startpointHubo[i];
		bfs();
	}


	if(ans == INF)
		cout<<-1;
	else
		cout << ans;

	return 0;
}