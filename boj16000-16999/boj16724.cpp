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

int N, M;


int ans = 0;
char arr[1002][1002];
int visited[1002][1002];

int dfs(int curY, int curX, int idx)
{
	visited[curY][curX] = idx;
	int nY = curY;
	int nX = curX;

	//cout << curY << "  " << curX << " " << idx << "\n";

	if (arr[curY][curX] == 'U')
	{
		nY--;
	}
	else if (arr[curY][curX] == 'D')
	{
		nY++;
	}
	else if (arr[curY][curX] == 'R')
	{
		nX++;
	}
	else if (arr[curY][curX] == 'L')
	{
		nX--;
	}  

	if (nY < 0 || nX < 0 || nY >= N || nX >= M)
		return idx;

	if (visited[nY][nX] == idx)
		return idx;

	if (visited[nY][nX] != 0 )
	{
		visited[curY][curX] = visited[nY][nX];
		ans--;
		return visited[nY][nX];
	}

	 return visited[curY][curX] = dfs(nY, nX, idx);
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
			arr[i][j] = tmp[j];
		}
	}
	rep(i, N)
	{
		rep(j, M)
		{
			if (visited[i][j])
				continue;

			ans++;
			dfs(i,j, ans);
		}
	}

	/*rep(i, N)
	{
		rep(j, M)
		{
			cout << visited[i][j] << " ";
		}
		cout << "\n";
	}*/

	cout << ans;

	return 0;
}