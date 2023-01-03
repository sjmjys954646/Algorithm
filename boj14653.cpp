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

int N, K, Q;

pair<int, char> arr[10002];
int visited[28];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K >> Q;

	rep1(i, K)
		cin >> arr[i].F >> arr[i].S;

	if (!arr[Q].F)
		cout << -1;
	else
	{
		for (int i = 1; i <= K; i++)
		{
			if (arr[Q].F <= arr[i].F)
			{
				int idx = arr[i].S - 'A';
				visited[idx] = true;
			}
		}
			

		for (int i = 1; i < N; i++)
		{
			if (!visited[i])
				cout << char(i + 'A') << " ";
		}
			

	}

	return 0;
}