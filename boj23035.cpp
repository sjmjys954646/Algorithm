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

ll M, N, K;
vector<pair<ll, ll>> v;
vector<ll> lis;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout.tie(0);

    cin >> N >> M;
    cin >> K;

    ll a, b;
    int ans = 0;
    int find = 0;

    rep(i, K)
    {
        cin >> a >> b;
        if (a > N || b > M)
            continue;
        v.push_back({ a,b });
    }

    sort(v.begin(), v.end());

    /*for (auto i : v)
        cout << i.first << " " << i.second << "\n";*/

    lis.push_back(-INF);

    for (int i = 0; i < v.size(); i++) 
    {
        if (lis.back() <= v[i].second) 
        {
            lis.push_back(v[i].second);
            ans++;
        }
        else 
        {
            auto it = upper_bound(lis.begin(), lis.end(), v[i].second);
            *it = v[i].second;
        }
    }

    cout << ans;

    return 0;
}