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

class edge
{
public:
	int start, end, cost;

	edge(int a, int  b, int  c) : start(a), end(b), cost(c) {}
	bool operator<(const edge& e) const
	{
		return this->cost > e.cost;
	}

};

int N, M;
int arr[1002][1002];
vector<pii> cache;
long long ans; 
int par[1002];
priority_queue<edge> pq;

int find(int x)
{
	if (par[x] == x)
		return x;
	else
		return par[x] = find(par[x]);
}

void merge(int x, int y)
{
	x = find(x);
	y = find(y);
	par[y] = x;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		par[i] = i;

	int p = 0;
	rep(i, M)
	{
		int a, b;
		cin >> a >> b;
		if (find(a) != find(b))
		{
			merge(a, b);
			p++;
		}
	}

	rep1(i, N)
	{
		rep1(j, N)
		{
			cin >> arr[i][j];
			if (i != 1 && i < j) {
				edge e{ i,j,arr[i][j] };
				pq.push(e);
			}
		}
	}
	while (!pq.empty())
	{
		if (p == N - 2)
			break;

		int a = pq.top().start;
		int b = pq.top().end;
		int c = pq.top().cost;
		pq.pop();

		if (find(a) == find(b))
			continue;

		p += 1;
		merge(a, b);

		ans += c;
		cache.push_back({ a,b });
	}

	cout << ans << " " << cache.size() << '\n';
	for (int i = 0; i < cache.size(); i++)
	{
		cout << cache[i].first << " " << cache[i].second << '\n';
	}


	return 0;
}