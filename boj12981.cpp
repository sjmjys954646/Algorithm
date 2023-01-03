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

int R, G, B;
int ans = 0;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout.tie(0);

    cin >> R >> G >> B;

    ans += (R / 3);
    R %= 3;
    ans += (G / 3);
    G %= 3;
    ans += (B / 3);
    B %= 3;
    
    if (min({ R,G,B }) >= 1)
    {     
        int q = min({ R,G,B });
        ans += q;
        R -= q;
        G -= q;
        B -= q;
    }

    if (min({ R,B }) >= 1)
    {
        int q = min({ R,B });
        ans += q;
        R -= q;
        B -= q;
    }

    if (min({ R,G }) >= 1)
    {
        int q = min({ R,G });
        ans += q;
        R -= q;
        G -= q;
    }

    if (min({ G,B }) >= 1)
    {
        int q = min({ G,B });
        ans += q;
        G -= q;
        B -= q;
    }
    
    ans += R > 0 ? 1 : 0;
    ans += G > 0 ? 1 : 0;
    ans += B > 0 ? 1 : 0;

    cout << ans;

    return 0;
}