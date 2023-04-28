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

int N;
string tmp;
int ans = 0;
int sumA = 0;
int sumB = 0;
bool manCheck = false;

void mm(bool t)
{
	if (t)
		sumA--;
	else
		sumB--;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	cin >> N;

	cin >> tmp;


	for (int i = 0; i < tmp.size(); i++)
	{
		if (tmp[i] == 'M')
		{
			manCheck = true;
			sumA++;
		}
		else
		{
			manCheck = false;
			sumB++;
		}

		if (abs(sumA - sumB) > N)
		{
			if (i == tmp.size() - 1 )
			{
				mm(manCheck);
				break;
			}
			else
			{
				if (tmp[i] == tmp[i + 1])
				{
					mm(manCheck);
					break;
				}
				else
				{
					mm(manCheck);
					tmp[i] ^= tmp[i + 1] ^= tmp[i] ^= tmp[i + 1];
					i--;
				}
			}
		}	
	}

	cout << sumA + sumB;;


	return 0;
}