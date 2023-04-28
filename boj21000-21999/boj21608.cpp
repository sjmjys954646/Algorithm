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

struct kann
{
	int emptyKann;
	int r;
	int c;
};

vector<kann> loveStudentNum[5];
vector<pair<int,vector<int>>> student;
vector<int> studentIndex[444];
int arr[22][22];
int N;
int num, tmp;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0, 1,0,-1 };
int pp[5] = { 0,1,10,100,1000 };

bool cmp(kann a, kann b)
{
	if (a.emptyKann != b.emptyKann)
		return a.emptyKann > b.emptyKann;
	else
	{
		if (a.r != b.r)
			return a.r < b.r;
		else
			return a.c < b.c;
	}
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	cin >> N;

	for (int i = 0; i < N * N; i++)
	{
		vi v;
		cin >> num;
		rep(i, 4)
		{
			cin >> tmp;
			v.push_back(tmp);
		}
		student.push_back({ num, v });
		studentIndex[num] = v;
	}

	for (int k = 0; k < N * N; k++)
	{
		int cur = student[k].first;
		vi like = student[k].second;
		for(int i = 0;i < 5;i++)
			loveStudentNum[i].clear();

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (arr[i][j] != 0)
					continue;

				int lover = 0;
				int emptyKann = 0;

				for (int t = 0; t < 4; t++)
				{
					int nY = i + dy[t];
					int nX = j + dx[t];

					if (nX < 0 || nY < 0 || nX >= N || nY >= N)
						continue;


					if (arr[nY][nX] == 0)
					{
						emptyKann++;
						continue;
					}

					if (find(like.begin(), like.end(), arr[nY][nX]) == like.end())
						continue;

					lover++;
				}
				kann p = { emptyKann, i , j };
				loveStudentNum[lover].push_back(p);
			}
		}

		kann selected;
		for (int index = 4; index >= 0; index--)
		{
			if (loveStudentNum[index].size() == 0)
			{
				continue;
			}

			sort(loveStudentNum[index].begin(), loveStudentNum[index].end(), cmp);

			selected = loveStudentNum[index][0];

			break;
		}

		arr[selected.r][selected.c] = cur;
	}

	int ans = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int cur = arr[i][j];
			vi like = studentIndex[cur];
			int lover = 0;

			for (int t = 0; t < 4; t++)
			{
				int nY = i + dy[t];
				int nX = j + dx[t];

				if (nX < 0 || nY < 0 || nX >= N || nY >= N)
					continue;

				if (arr[nY][nX] == 0)
					continue;

				if (find(like.begin(), like.end(), arr[nY][nX]) == like.end())
					continue;

				lover++;
			}

			ans += pp[lover];
		}
	}

	cout << ans;
	

	return 0;
}

