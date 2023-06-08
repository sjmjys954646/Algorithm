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


string N;
int K;
string ans = "";

void bfs()
{
	queue<string> q;
	q.push({ N, 0 });
	int curK = 0;

	while (!q.empty())
	{
		if (curK >= K)
			break;

		int curQ = q.size();
		set<string> s;
		
		for (int i = 0; i < curQ; i++)
		{
			string cur = q.front();
			q.pop();

			for (int i = 0; i < N.size(); i++)
			{
				for (int j = i + 1; j < N.size(); j++)
				{
					string newtmp = cur;
					swap(newtmp[i], newtmp[j]);

					if (s.count(newtmp) != 0)
						continue;

					if (newtmp[0] == '0')
						continue;

					q.push(newtmp);
					s.insert(newtmp);

					if(curK == K -1)
						ans = max(ans, newtmp);
				}
			}
		}

		curK++;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	bfs();

	if (ans == "")
		cout << -1;
	else
		cout << ans;


	return 0;
}