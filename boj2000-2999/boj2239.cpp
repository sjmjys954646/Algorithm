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

//
//ll arr[1000002];
//ll tree[4 * 1000002];
//ll N, M, K;
//ll order;
//ll a, b, c, d;
//
//ll init(ll start, ll end, ll node)
//{
//	if (start == end)
//		return tree[node] = arr[start];
//
//	ll mid = (start + end) / 2;
//
//	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
//}
//
//ll query(ll start, ll end, ll node, ll left, ll right)
//{
//	if (left > end || right < start)
//		return 0;
//
//	if (left <= start && end <= right)
//		return tree[node];
//
//	ll mid = (start + end) / 2;
//
//	return query(start, mid, node * 2, left, right) + query(mid + 1, end, node * 2 + 1, left, right);
//}
//
//ll update(ll start, ll end, ll node, ll index, ll diff)
//{
//	if (index < start || end < index)
//		return tree[node];
//
//	if (start == end)
//		return tree[node] = diff;;
//
//	ll mid = (start + end) / 2;
//
//	return tree[node] = update(start, mid, node * 2, index, diff) + update(mid + 1, end, node * 2 + 1, index, diff);
//}
int board[9][9];
vector<pair<int, int> > blank;
bool fin;
int ansboard[9][9];
int ans = INF;

int sum()
{
	int sum = 0;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			sum += board[i][j];
		}
	}
	return sum;
}


int makeA(int a)
{
	if (0 <= a && a < 3)
		return 0;
	else if (3 <= a && a < 6)
		return 3;
	else
		return 6;
}

bool judge(pair<int, int> bl)
{
	for (int i = 0; i < 9; i++)
	{
		if (i != bl.second && board[bl.first][i] == board[bl.first][bl.second])
		{
			return false;
		}
	}

	for (int i = 0; i < 9; i++)
	{
		if (i != bl.first && board[i][bl.second] == board[bl.first][bl.second])
		{
			return false;
		}
	}

	int a, b;
	a = makeA(bl.first);
	b = makeA(bl.second);

	for (int i = a; i < a + 3; i++)
	{
		for (int j = b; j < b + 3; j++)
		{
			if (i != bl.first && j != bl.second && board[i][j] == board[bl.first][bl.second])
			{
				return false;
			}
		}
	}

	return true;

}

void sudoku(int &num)
{
	if (num == blank.size())
	{
		int aans = sum();
		if (ans > aans)
		{
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					ansboard[i][j] = board[i][j];
				}
			}
			ans = aans;
		}
		
		fin = true;
		return;

	}
	
	for (int i = 1; i < 10; i++)
	{
		board[blank[num].first][blank[num].second] = i;
		if (judge(blank[num]))
		{
			sudoku(++num);
		}
		if (fin == true)
			return;
	}

	board[blank[num].first][blank[num].second] = 0;
	num--;
	return;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	int num = 0;
	string tmp;
	for (int i = 0; i < 9; i++)
	{
		cin >> tmp;
		for (int j = 0; j < 9; j++)
		{
			 board[i][j] = tmp[j] - '0';
		}
	}

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (board[i][j] == 0)
				blank.push_back({ i,j });
		}
	}

	sudoku(num);

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << ansboard[i][j];
		}
		cout << "\n";
	}
	

	return 0;
}

