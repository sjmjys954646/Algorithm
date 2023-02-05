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

struct Point {
	ll x, y;

	bool operator < (const Point& a)
	{
		if (y == a.y)
			return x < a.x;
		else
			return y < a.y;
	}
};

ll ccw(const Point& a, const Point& b, const Point& c)
{
	return a.x * b.y + b.x * c.y + c.x * a.y - b.x * a.y - c.x * b.y - a.x * c.y;
}

ll dist(Point a, Point b)
{
	return (a.y - b.y) * (a.y - b.y) + (a.x - b.x) * (a.x - b.x);
}

vector<pii> graph[10002];
int visited[10002];
int N, M, X;
int a, b, c;

int dijkstra(int start, int end)
{
    for (int i = 1; i <= N; i++)
        visited[i] = INF;

    priority_queue<pair<int, int>> pq;
    visited[start] = 0;
    pq.push({ 0, start });

    while (!pq.empty())
    {
        int cost = -pq.top().F;
        int cur = pq.top().S;

        pq.pop();

        if (cost > visited[cur])
            continue;

        for (int i = 0; i < graph[cur].size(); i++)
        {
            int next = graph[cur][i].F;
            int nextCost = graph[cur][i].S + cost;

            if (nextCost < visited[next])
            {
                pq.push({ -nextCost, next });
                visited[next] = nextCost;
            }
        }
    }
    return visited[end];
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);

    cin >> N >> M >> X;

    for (int i = 0; i < M; i++)
    {
        cin >> a >> b >> c;
        graph[a].push_back({ b, c });
    }
    int ans = -1;
    for (int i = 1; i <= N; i++)
    {
        int sum = dijkstra(i, X) + dijkstra(X, i);
        ans = max(sum, ans);
    }

    cout << ans;

	return 0;
}