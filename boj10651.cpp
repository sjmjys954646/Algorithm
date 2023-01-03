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

ll N, T;
vector<pair<ll,ll>> v;
multiset<ll> ms;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout.tie(0);

    cin >> N >> T;

    int a, b;

    rep(i, N)
    {
        cin >> a >> b;
        v.push_back({ a,b });
    }

    for(int i = N-1;i>=0;i--)
    {
        pair<ll, ll> cur = v[i];
        ll pos = v[i].first + v[i].second * T;

        if (i == N-1)
        {
            ms.insert(pos);
            continue;
        }

        auto it = ms.upper_bound(pos);

        if (it == ms.end())
        {
            ms.insert(pos);
        }
        else
        {
            ms.erase(it);
            ms.insert(pos);
        }
    }
    cout << ms.size();

    return 0;
}