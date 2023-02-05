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

int arr[18][18];
int N;
ll dp[1 << 15][18][18];

ll TSP(int visit, int start, int cost)
{
    ll& ret = dp[visit][start][cost];

    if (ret != -1)
        return ret;

    ret = 1;

    for (int i = 1; i <= N; i++)
    {
        if (visit & (1 << (i - 1)))
            continue;

        if (arr[start][i] < cost)
            continue;

        ret = max(ret, TSP(visit + (1 << (i - 1)), i, arr[start][i]) + 1);
    }

    return ret;
}


int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);

    memset(dp, -1, sizeof(dp));

    cin >> N;

    string tmp;

    for (int i = 1; i <= N; i++)
    {
        cin >> tmp;
        for (int j = 1; j <= N; j++)
        {
            arr[i][j] = tmp[j - 1] - '0';
        }
    }

    cout <<  TSP(1,1,0);


	return 0;
}