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

int N, K, A, B;
priority_queue<int,vector<int>,greater<int>> pq;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K >> A >> B;
	
	for (int i = 0; i < N; i++)
		pq.push(K);
	int day = 1;
	bool check = false;
	while (true)
	{
		vi v;

		rep(i, A)
		{
			int p = pq.top();
			pq.pop();
			v.push_back(p + B);
		}

		while (!pq.empty())
		{
			int p = pq.top();
			pq.pop();
			v.push_back(p);
		}


		rep(i, N)
		{
			v[i] -= 1;
			if (!v[i])
				check = true;
		}

		if (check)
			break;

		rep(i, N)
		{
			pq.push(v[i]);
		}
		day++;
	}

	cout << day;

	return 0;
}