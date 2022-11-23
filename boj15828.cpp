// freopen("input.txt", "r", stdin);
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

queue<int> q;
int N;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	while(true)
	{
		int tmp;
		cin >> tmp;

		if (tmp == -1)
			break;

		if (tmp == 0)
		{
			q.pop();
			continue;
		}

		if (q.size() == N)
			continue;

		q.push(tmp);
	}

	if (q.empty())
		cout << "empty";
	else
	{
		while (!q.empty())
		{
			int top = q.front();
			cout << top << " ";
			q.pop();
		}
	}

    return 0;
}