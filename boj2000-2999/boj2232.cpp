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


int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	int N;
	cin >> N;

	vector<pii> v;
	vector<pii> vv;
	vi ans;

	rep(i, N)
	{
		int tmp;
		cin >> tmp;
		v.push_back({ tmp,i });
	}
	vv = v;

	sort(vv.begin(), vv.end(), greater<>());

	int p = 0;
	int idx = 0;
	while (true)
	{
		if (idx == N)
			break;

		int pos = vv[idx].second;
		int cur = vv[idx].first;


		if (v[pos].first == 0)
		{
			idx++;
			continue;
		}
		ans.push_back(pos + 1);

		int newpos = pos + 1;
		int newcur = cur;
		while (newpos < N)
		{
			if (v[newpos].first >= newcur)
				break;
			else
			{
				p++;
				newcur = v[newpos].first;
				v[newpos] = { 0,0 };
				newpos = newpos + 1;
			}
		}
		newpos = pos - 1;
		newcur = cur;
		while (newpos >= 0)
		{
			if (v[newpos].first >= newcur)
				break;
			else
			{
				p++;
				newcur = v[newpos].first;
				v[newpos] = { 0,0 };
				newpos = newpos - 1;
			}
		}

		p++;
		v[pos] = { 0,0 };
		idx++;

	}

	sort(ans.begin(), ans.end());

	for (auto i : ans)
		cout << i << "\n";


	return 0;
}