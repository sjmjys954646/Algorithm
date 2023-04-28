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

vector<ll> v;
vector<ll> vv;
int N, tmp;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	cin >> N;

	rep(i, N)
	{
		cin >> tmp;
		v.push_back(tmp);
	}
	//� �̴���
	for (int i = 1; i <= N; i++)
	{
		//idx
		for (int j = 0; j < N; j++)
		{
			bool overflow = false;
			ll sum = 0;
			for (int k = j; k < j + i; k++)
			{
				if (k >= N)
				{
					overflow = true;
					break;
				}
				sum += pow(10,i- k+j - 1) * v[k];
				if (sum < 0)
				{
					overflow = true;
					break;
				}
			}
			if (overflow)
				break;
			vv.push_back(sum);
		}
	}

	sort(vv.begin(), vv.end());
	vv.erase(unique(vv.begin(), vv.end()), vv.end());


	for (int i = 0;; i++)
	{
		if (vv[i] == i)
			continue;
		else
		{
			cout << i;
			break;
		}
	}
	

	return 0;
}