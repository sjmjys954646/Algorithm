#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <utility>
#include <iostream>
#include <cmath>
#include <queue>
#include<string.h>


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
	double x, y;

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
int arr[1003][1003];
int visited[1003][1003];
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

bool check(int mid)
{
	memset(visited, 0, sizeof(visited));

	int tot = 0;
	
	queue<pii> q;
	q.push({ 0,0 });
	visited[0][0] = 1;

	while (!q.empty())
	{
		auto k = q.front();
		q.pop();


		for (int i = 0; i < 4; i++)
		{
			int nY = k.first + dy[i];
			int nX = k.second + dx[i];

			if (nY < 0 || nX < 0 || nY > N || nX > M + 1)
				continue;

			if (visited[nY][nX] == 1)
				continue;

			if (arr[nY][nX] > mid)
				continue;

			q.push({ nY,nX });
			visited[nY][nX] = 1;

			if(arr[nY][nX] != 0)
				tot++;
		}
	}

	if (tot >= K)
		return true;
	else
		return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;

	rep1(i, N)
	{
		rep1(j, M)
		{
			cin >> arr[i][j];
		}
	}

	int lo = -1;
	int hi = 1000002;

	while (lo + 1 < hi)
	{
		int mid = (lo + hi) / 2;
		if (check(mid))
		{
			hi = mid;
		}
		else
		{
			lo = mid;
		}
	}

	cout << hi;
	return 0;
}