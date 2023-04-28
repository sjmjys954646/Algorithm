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

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout.tie(0);

    int N = 7;
    int ansmax = INF;
    int anssum = 0;
    rep(i, N)
    {
        int tmp;
        cin >> tmp;

        if (tmp % 2 == 1)
        {
            ansmax = min(ansmax, tmp);
            anssum += tmp;
        }
    }
    if (anssum == 0)
        cout << -1;
    else
        cout << anssum << "\n" << ansmax;

    return 0;
}