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

int cache[100002][3];
int arr[100002];
int n;
double c;
int ans = -1;
int maxans = -1;
int tmp;
int cur = 0;


int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout.tie(0);

    cin >> c;
    cin >> n;

    memset(cache, -1, sizeof(cache));

    int coin = (int)(c / 0.99);

    coin = min(coin, 2);

    rep(i, n)
    {
        cin >> arr[i];
        ans = max(ans, arr[i]);
    }

    rep(i, n)
    {
        if (arr[i] == 0)
        {
            rep(j, coin + 1)
            {
                if (j > 0)
                {
                    cache[i][j - 1] = cache[i - 1][j] + 1;
                    cache[i][j] = 0;
                }
                else
                {
                    cache[i][j] = 0;
                }
            }
        }
        else
        {
            rep(j, coin + 1)
            {
                if (i == 0)
                    cache[i][j] = 1;
                else
                    cache[i][j] = cache[i - 1][j] + 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        rep(j, coin + 1)
        {
            maxans = max(maxans, cache[i][j]);
        }
    }

    cout << maxans << "\n";
    cout << ans;

    return 0;
}