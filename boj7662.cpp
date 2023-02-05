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

int visited[3000000];
int N;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	int testcase;
	cin >> testcase;

	while (testcase--)
	{
		int idx = 0;
		cin >> N;
		memset(visited, 0, sizeof(visited));

		priority_queue<pair<int,int>,vector<pii>, greater<pii>> pqG;//작은거우선
		priority_queue<pair<int, int>, vector<pii>, less<pii>> pqL;//큰거우선

		cin.ignore();
		while (N--)
		{
			string tmp;
			getline(cin, tmp);
			char order = tmp[0];
			string num = tmp.substr(2);
			int nn = stoi(num);

			if (order == 'I')
			{
				pqG.push({ nn, idx });
				pqL.push({ nn, idx });
				idx++;
			}
			else if (order == 'D')
			{
				if (nn == 1)
				{
					while (true)
					{
						if (pqL.empty())
							break;

						if (visited[pqL.top().S] == 0)
						{
							visited[pqL.top().S] = 1;
							pqL.pop();
							break;
						}

						pqL.pop();
					}
				}
				else
				{
					while (true)
					{
						if (pqG.empty())
							break;

						if (visited[pqG.top().S] == 0)
						{
							visited[pqG.top().S] = 1;
							pqG.pop();
							break;
						}

						pqG.pop();
					}
				}
			}
		}

		int maxi = -INF;
		int mini = INF;

		while (true)
		{
			if (pqL.empty())
				break;

			if (visited[pqL.top().S] == 0)
			{
				maxi = pqL.top().F;
				break;
			}

			pqL.pop();
		}

		while (true)
		{
			if (pqG.empty())
				break;

			if (visited[pqG.top().S] == 0)
			{
				mini = pqG.top().F;
				break;
			}

			pqG.pop();
		}

		if (pqL.empty() && pqG.empty())
		{
			cout << "EMPTY\n";
		}
		else
		{
			cout << pqL.top().first << " " << pqG.top().first << "\n";
		}
	}

	return 0;
}