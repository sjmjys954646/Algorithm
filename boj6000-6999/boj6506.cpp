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

ll arr[102];
ll cache[102][102];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout.tie(0);

    while (true)
    {
        memset(arr, 0, sizeof(arr));
        memset(cache, 0, sizeof(cache));

        ll n, k;
        ll ans = 0;
        cin >> n >> k;

        if (n == 0 && k == 0)
            break;

        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }

        for (int i = 1; i <= n; i++)
        {
            cache[1][i] = 1;
            if (k == 1)
                ans += cache[1][i];
        }
        for (int i = 2; i <= n; i++)
        {
            for (int j = i; j <= n; j++)
            {
                for (int t = 1; t <= j; t++)
                {
                    if (arr[j] > arr[t])
                        cache[i][j] += cache[i-1][t];
                }

                if(i == k)
                    ans += cache[i][j];
            }
        }

        cout << ans << "\n";
    }
    

    return 0;
}