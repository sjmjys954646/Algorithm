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
rope<char> r;
char order[15];
int a, b, c,d;
int cursor = 0;

int main()
{
	int testcase;
	
	scanf("%d", &testcase);
	
	while(testcase--)
	{
		//printf("testcase : %d\n",testcase);
		
		scanf("%s", order);
		
		//printf("order : %s\n",order);
		
		if(!strcmp(order,"Insert"))
		{
			int cursorbef = cursor;
			scanf("%d", &a);
			
			char tmp;
			for(int i = 0;i< a;i++)
			{
				scanf("%c", &tmp);
				
				if(tmp == '\n')
				{
					i--;
					continue;
				}
				
				r.insert(cursor,tmp);
				cursor++;
			}
			cursor = cursorbef;
		}
		else if(!strcmp(order,"Move"))
		{
			scanf("%d", &a);
			cursor = a;
		}
		else if(!strcmp(order,"Delete"))
		{
			scanf("%d", &a);
			r.erase(cursor, a);
		}
		else if(!strcmp(order,"Next"))
		{
			if(cursor != r.size())
				cursor++;
		}
		else if(!strcmp(order,"Prev"))
		{
			if(cursor != 0)
				cursor--;
		}
		else if(!strcmp(order,"Get"))
		{
			scanf("%d", &a);
			
			if(a + cursor > r.size())
			{
				printf("Bad editor tree\n");
				continue;
			}
			
			printf("%s\n",r.substr(cursor,a).c_str());
		}
		/*
		cout <<"cursor : " << cursor << "\n";
		
		for(auto i : r)
			cout << i;
		cout<<"\n";
		*/
	}
	
	

	return 0;
}