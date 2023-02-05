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

const int INF = 9876543210;

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

int arr[65][65];
int visited[65][65];
int dx[2] = { 1,0, };
int dy[2] = { 0,1 };

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	int N;

	cin >> N;

	rep(i, N)
	{
		rep(j, N)
			cin >> arr[i][j];
	}

	queue<pii> q;
	q.push( { 0,0 });
	visited[0][0] = 1;
	bool pos = false;

	while (!q.empty())
	{
		int curY = q.front().F;
		int curX = q.front().S;
		//cout << curY << " " << curX << " " << cost << "\n";
		q.pop();

		if (curY == N - 1 && curX == N - 1)
		{
			pos = true;
			break;
		}

		for (int i = 0; i < 2; i++)
		{
			int nY = curY + dy[i] * arr[curY][curX];
			int nX = curX + dx[i] * arr[curY][curX];

			if (nY < 0 || nX < 0 || nY >= N || nX >= N)
				continue;
			if (visited[nY][nX])
				continue;
			
			q.push({ nY,nX });
			visited[nY][nX] = 1;
		}
	}

	if (pos)
		cout << "HaruHaru";
	else
		cout << "Hing";


	return 0;
}