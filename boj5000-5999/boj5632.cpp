#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <ext/rope>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define range(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second

using namespace __gnu_cxx;
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


string s;
rope<char> r[50005];
int order;
int a, b, c;
string k;
string p;
int d = 0;
int cur = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int testcase;
	cin >> testcase;
	
	while(testcase--)
	{
		cin >> order;
		
		if(order == 1)
		{
			cin >> a >> k;
			a-=d;
			r[cur].insert(a,k.c_str());
			cur++;
			r[cur] = r[cur-1];
		}
		else if(order == 2)
		{
			cin >> a >> b;
			a-=d;
			b-=d;
			r[cur].erase(a-1,b);
			cur++;
			r[cur] = r[cur-1];
		}
		else if(order == 3)
		{
			cin >> a >> b >> c;
			a-=d;
			b-=d;
			c-=d;
			
			crope p = r[a-1].substr(b-1,c);
			d += count(p.begin(),p.end(), 'c');
			cout<<p<<"\n";
		}
		
		/*
		cout << " d : ";
		cout <<d << "\n";
		for(int i = 0;i< v.size();i++)
		{
			cout << i << " : " << v[i] << "\n";
		}
		*/
	}
	

	return 0;
}