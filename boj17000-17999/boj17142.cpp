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


int manhat(int startX, int startY, int endX, int endY)
{
	return abs(startX - endX) + abs(startY - endY);
}

int gcd(int x, int y)
{
	if (y == 0)
		return x;
	else
		return gcd(y, x % y);
}

/*
1. 바이러스 위치 bruteforce dfs
2. 바이러스 뿌리기
3. 종료후 빈칸확인
4. 1,3 확인
*/

int N, M;
int arr[52][52];
vector<pii> virusHubo;
vector<pii> selected;
int visited[52][52];
int totWall = 0;
int ans = INF;
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };
int tot;

struct viru
{
	int Y;
	int X;
	int time;
};

bool check()
{
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (!visited[i][j])
				sum++;
		}
	}

	if (sum == totWall)
		return true;
	else
		return false;
}

int bfs()
{
	int left = tot;
	int ansTime = 0;
	queue<viru> q;

	if (left == 0)
		return 0;

	for (int i = 0; i < selected.size(); i++)
	{
		q.push({ selected[i].first , selected[i].second, 1 });
		visited[selected[i].first][selected[i].second] = 1;
	}

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		ansTime = max(ansTime, cur.time);

		for (int i = 0; i < 4; i++)
		{
			int nY = cur.Y + dy[i];
			int nX = cur.X + dx[i];

			if (nY < 0 || nX < 0 || nY >= N || nX >= N)
				continue;

			if (visited[nY][nX] != 0)
				continue;

			if (arr[nY][nX] == 1)
				continue;

			q.push({ nY, nX , cur.time + 1 });
			visited[nY][nX] = cur.time + 1;

			if(arr[nY][nX] == 0)
				left--;

			if (left == 0)
				return ansTime;
		}
	}

	return -1;
}

void findVirusPos(int idx)
{
	if (selected.size() == M)
	{
		//init
		memset(visited, 0, sizeof(visited));

		//simul
		int hubo = bfs();

		/*cout << hubo << "\n";

		rep(i, N)
		{
			rep(j, N)
			{
				cout << visited[i][j];
			}
			cout << "\n";
		}
		cout << "\n";*/

		if(hubo != -1)
			ans = min(ans, hubo);

		return;
	}

	for (int i = idx; i < virusHubo.size(); i++)
	{
		selected.push_back(virusHubo[i]);
		findVirusPos(i + 1);
		selected.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	rep(i, N)
	{
		rep(j, N)
		{
			cin >> arr[i][j];

			if (arr[i][j] == 2)
				virusHubo.push_back({ i,j });
			else if (arr[i][j] == 1)
				totWall++;
			else if (arr[i][j] == 0)
				tot++;
		}
	}

	findVirusPos(0);

	if (ans == INF)
		cout << -1;
	else
		cout << ans;

	return 0;
}