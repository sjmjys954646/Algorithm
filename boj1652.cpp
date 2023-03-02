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

int N;
int visited[102][102];
int arr[102][102];
int r, c;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	cin >> N;

	string tmp;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		for (int j = 0; j < N; j++)
		{
			if (tmp[j] == 'X')
				arr[i][j] = -1;
			else
				arr[i][j] = 1;
		}
	}

	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visited[i][j] == 1)
				continue;

			if (arr[i][j] == -1)
				continue;

			int curY = i;
			int curX = j;

			int cur = 0;
			while (true)
			{
				if (curY >= N || curX >= N)
					break;

				if (arr[curY][curX] == -1)
					break;

				visited[curY][curX] = 1;
				curX++;
				cur++;
			}
			if(cur >= 2)
				r += 1;
		}
	}

	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visited[i][j] == 1)
				continue;

			if (arr[i][j] == -1)
				continue;

			int curY = i;
			int curX = j;

			int cur = 0;
			while (true)
			{
				if (curY >= N || curX >= N)
					break;

				if (arr[curY][curX] == -1)
					break;

				visited[curY][curX] = 1;
				curY++;
				cur++;
			}
			if (cur >= 2)
				c += 1;
		}
	}

	cout << r << " " << c;

	return 0;
}