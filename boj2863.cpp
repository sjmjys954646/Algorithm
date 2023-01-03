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

    double a, b, c, d;
    cin >> a >> b >> c >> d;
    int ans = 0;
    double maxans = a/c + b/d;
    for (int i = 1; i < 4; i++)
    {
        //swap
        int newa = c;
        int newb = a;
        int newc = d;
        int newd = b;
        a = newa;
        b = newb;
        c = newc;
        d = newd;
        if (maxans < a / c + b / d)
        {
            ans = i;
            maxans = a / c + b / d;
        }
    }
    cout << ans;

    return 0;
}