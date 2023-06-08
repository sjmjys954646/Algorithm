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
char arr[1002][1002];
int visited[1002][1002];
map<int, int> m;
int sum = 0;
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };
int idx = 0;


void bfs(int startY, int startX)
{
	queue<pii> q;
	q.push({ startY, startX });
	visited[startY][startX] = idx;
	sum++;

	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nY = cur.first + dy[i];
			int nX = cur.second + dx[i];

			if (nY < 0 || nX < 0 || nY >= N || nX >= M)
				continue;

			if (arr[nY][nX] == '1')
				continue;

			if (visited[nY][nX])
				continue;


			q.push({ nY,nX });
			visited[nY][nX] = idx;
			sum++;
		}
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
			if (arr[i][j] == '1')
				continue;

			if (visited[i][j] != 0)
				continue;

			idx++;
			sum = 0;
			bfs(i, j);
			m[idx] = sum;
		}
	}

	/*cout << "\n";
	rep(i, N)
	{
		rep(j, M)
		{
			cout << visited[i][j] << "";
		}
		cout << "\n";
	}
	cout << "\n";

	cout << "\n";
	rep(i, N)
	{
		rep(j, M)
		{
			cout << group[i][j] << "";
		}
		cout << "\n";
	}
	cout << "\n";*/


	set<int> s;
	rep(i, N)
	{
		rep(j, M)
		{
			if (arr[i][j] == '1')
			{
				s.clear();
				int sum = 1;

				for (int t = 0; t < 4; t++)
				{
					int nY = i + dy[t];
					int nX = j + dx[t];

					if (nY < 0 || nX < 0 || nY >= N || nX >= M)
						continue;

					if (s.find(visited[nY][nX]) != s.end())
						continue;

					sum += m[visited[nY][nX]];
					s.insert(visited[nY][nX]);
				}
				cout << sum % 10;
			}
			else
			{
				cout << 0;
			}
		}
		cout << "\n";
	}


	return 0;
}