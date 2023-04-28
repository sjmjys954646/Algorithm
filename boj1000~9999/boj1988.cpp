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
                
int idle[3002][3002];
int sleep[3002][3002];
int arr[3002];
int N, B;
int ans;

int dp(int n, int b, int cur)
{
    if (n == N)
        return 0;

    int& ret = cur == 1 ? sleep[n][b] : idle[n][b];

    if (ret != -1)
        return ret;
    
    ret = 0;

    if (b == 0)
    {
        ret = dp(n + 1, b, 0);
    }
    else
    {
        if (cur)
        {
            ret = max(dp(n + 1, b, 0), dp(n + 1, b - 1, 1) + arr[n]);
        }
        else
        {
            ret = max(dp(n + 1, b, 0), dp(n + 1, b - 1, 1));
        }
    }

    return ret;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout.tie(0);

    memset(idle, -1, sizeof(idle));
    memset(sleep, -1, sizeof(sleep));

    cin >> N >> B;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    cout << dp(0, B, 0);


    return 0;
}