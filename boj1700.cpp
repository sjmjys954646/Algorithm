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

int N, K;
vi v;
int tmp;
int plug[102];

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	cin >> N >> K;

	rep(i, K)
	{
		cin >> tmp;
		v.push_back(tmp);
	}

	int ans = 0;
	rep(i, K)
	{
		int cur = v[i];
		int isPlugFull = -1;

		for (int j = 0; j < N; j++)
		{
			if (plug[j] == 0 || plug[j] == cur)
			{
				isPlugFull = j;
				break;
			}
		}
		//플러그가 풀일떄는 한번빼야된다.
		if (isPlugFull == -1)
		{
			int hubo = -1;
			int minCost = -1;
			//빼야될 친구는 가장 나중에 쓰이는애 혹은 이제 안쓰이는애
			for (int j = 0; j < N; j++)
			{
				int pos = 0;
				int tmpCur = i + 1;
				while (true)
				{
					if (tmpCur >= K)
						break;

					if (v[tmpCur] == plug[j])
						break;

					pos++;
					tmpCur++;
				}

				if (minCost < pos)
				{
					hubo = j;
					minCost = pos;
				}
			}

			ans++;
			plug[hubo] = cur;
		}
		else
		{
			plug[isPlugFull] = cur;
		}
	}

	cout << ans;

	

	return 0;
}