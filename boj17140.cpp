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

int r, c, k;
int arr[102][102];
int tmparr[102][102];
int ans = 0;
int curR = 3;
int curC = 3;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	cin >> r >> c >> k;

	for (int i = 0; i < curR; i++)
		for (int j = 0; j < curC; j++)
			cin >> arr[i][j];

	while (true)
	{
		memset(tmparr, 0, sizeof(tmparr));

		if (arr[r - 1][c - 1] == k)
			break;

		if (ans == 100)
		{
			ans = -1;
			break;
		}

		if (curR >= curC)
		{
			int curHubo = curC;
			//R연산
			for (int i = 0; i < curR; i++)
			{
				map<int, int> m;
				for (int j = 0; j < curR; j++)
				{
					if (arr[i][j] == 0)
						continue;

					if (m.count(arr[i][j]) == 0)
						m[arr[i][j]] = 1;
					else
						m[arr[i][j]]++;
				}
				vector<pair<int,int>> v;
				for (auto j : m)
				{
					v.push_back({ j.second, j.first});
				}

				sort(v.begin(), v.end());

				for (int j = 0; j < min((int)v.size()*2, 100); j++)
				{
					if(j%2 == 0)
						tmparr[i][j] = v[j/2].second;
					else
						tmparr[i][j] = v[j/2].first;
				}

				curHubo = max(curHubo, min((int)v.size()*2,100));
			}
			curC = curHubo;
		}
		else
		{
			//C연산
			int curHubo = curR;
			//R연산
			for (int i = 0; i < curC; i++)
			{
				map<int, int> m;
				for (int j = 0; j < curC; j++)
				{
					if (arr[j][i] == 0)
						continue;
					if (m.count(arr[j][i]) == 0)
						m[arr[j][i]] = 1;
					else
						m[arr[j][i]]++;
				}
				vector<pair<int, int>> v;
				for (auto j : m)
				{
					v.push_back({ j.second,j.first });
				}

				sort(v.begin(), v.end());

				for (int j = 0; j < min((int)v.size() * 2, 100); j++)
				{
					if (j % 2 == 0)
						tmparr[j][i] = v[j / 2].second;
					else
						tmparr[j][i] = v[j / 2].first;
				}

				curHubo = max(curHubo, min((int)v.size() * 2, 100));
			}
			curR = curHubo;
		}
		for (int i = 0; i < curR; i++)
		{
			for (int j = 0; j < curC; j++)
			{
				arr[i][j] = tmparr[i][j];
			}
		}


		ans++;
	}

	cout << ans;


	return 0;
}