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
bool visited[5002];
int A[5002];
int B[5002];
vector<int> arr[5002];
int n, m;
int tmp;
int ans = 0;
char graph[102][102];
int graphNumRow[102][102];
int graphNumCol[102][102];

bool dfs(int a)
{
	visited[a] = true;
	for (int b : arr[a])
	{
		if (B[b] == -1 || !visited[B[b]] && dfs(B[b]))
		{
			A[a] = b;
			B[b] = a;
			return true;
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;

	cin >> N;

	rep(i, N)
	{
		rep(j, N)
		{
			cin >> graph[i][j];
		}
	}

	int idx = 1;
	rep(i, N)
	{
		rep(j, N)
		{
			if (graph[i][j] == 'X')
				continue;

			if (graphNumRow[i][j] != 0)
				continue;

			for(int k = j; k < N; k++)
			{
				if (graph[i][k] == 'X')
					break;

				graphNumRow[i][k] = idx;
			}
			idx++;
		}
	}

	idx = 1;
	rep(i, N)
	{
		rep(j, N)
		{
			if (graph[i][j] == 'X')
				continue;

			if (graphNumCol[i][j] != 0)
				continue;

			for (int k = i; k < N; k++)
			{
				if (graph[k][j] == 'X')
					break;

				graphNumCol[k][j] = idx;
			}
			idx++;
		}
	}


	memset(A, -1, sizeof(A));
	memset(B, -1, sizeof(B));

	rep(i, N)
	{
		rep(j, N)
		{
			if (graph[i][j] == 'X')
				continue;

			arr[graphNumRow[i][j]].push_back(graphNumCol[i][j]);
		}
	}



	for (int i = 0; i < 5001; i++)
	{
		if (A[i] != -1)
			continue;

		memset(visited, 0, sizeof(visited));

		if (dfs(i))
			ans++;
	}

	cout << ans << "\n";

	

	return 0;
}