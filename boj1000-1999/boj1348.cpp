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


int N, M, K;
bool visited[502];
int A[502];
int B[502];
int n, m;
int ans = 0;
char graph[52][52];
int relation[102][102];
vector<pii> arr[5002];
map<pii,int> mpC;
map<pii, int> mpP;
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };
int vst[52][52];
int indexC = 1;
int indexP = 1;

void bfs(int startY, int startX)
{
	memset(vst, 0, sizeof(vst));
	queue<pair<pii,int>> q;
	q.push({ { startY, startX },0 });
	vst[startY][startX] = 1;

	while (!q.empty())
	{
		auto k = q.front();
		q.pop();

		if (graph[k.first.first][k.first.second] == 'P')
		{
			int from = mpC[{startY, startX}];
			int to = mpP[{k.first.first, k.first.second}];
			relation[from][to] = k.second;
		}

		for (int i = 0; i < 4; i++)
		{
			int nY = k.first.first + dy[i];
			int nX = k.first.second + dx[i];

			if (nY < 0 || nX < 0 || nY >= N || nX >= M)
				continue;

			if (vst[nY][nX])
				continue;

			if (graph[nY][nX] == 'X')
				continue;

			q.push({ { nY, nX },k.second + 1 });
			vst[nY][nX] = 1;
		}
	}

}

bool dfs(int a, int val)
{
	visited[a] = true;
	for (auto t : arr[a])
	{
		int b = t.first;
		if (t.second  <= val &&  (B[b] == -1 || !visited[B[b]] && dfs(B[b],val)))
		{
			A[a] = b;
			B[b] = a;
			return true;
		}
	}
	return false;
}

int check(int mid)
{
	memset(A, -1, sizeof(A));
	memset(B, -1, sizeof(B));

	int cnt = 0;
	for (int i = 1; i <= indexC; i++)
	{
		if (A[i] != -1)
			continue;

		memset(visited, 0, sizeof(visited));

		if (dfs(i,mid))
			cnt++;
	}

	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	rep(i, N)
	{
		string tmp;
		cin >> tmp;

		rep(j, M)
		{
			graph[i][j] = tmp[j];
			if (graph[i][j] == 'P')
			{
				mpP[{i, j}] = indexP;
				indexP++;
			}
			else if (graph[i][j] == 'C')
			{
				mpC[{i, j}] = indexC;
				indexC++;
			}
		}
	}

	indexP = mpP.size();
	indexC = mpC.size();

	rep(i, N)
	{
		rep(j, M)
		{
			if (graph[i][j] == 'C')
			{
				bfs(i, j);
			}
		}
	}


	for (int i = 1; i <= indexC; i++)
	{
		for (int j = 1; j <= indexP; j++)
		{
			if (relation[i][j] == 0)
				continue;

			arr[i].push_back({ j,relation[i][j] });
		}
	}

	int lo = -1;
	int hi = 2600;
	while (lo + 1 < hi)
	{
		int mid = (hi + lo) / 2;
		if (check(mid) < indexC)
		{
			lo = mid;
		}
		else
		{
			hi = mid;
		}
	}

	if (indexC == 0)
		cout << 0;
	else if (check(hi) == indexC)
		cout << hi;
	else
		cout << -1;

	return 0;
}