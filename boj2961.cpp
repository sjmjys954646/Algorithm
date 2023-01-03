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

int N;
ll a[12];
ll b[12];
ll ans = LLONG_MAX;
vi selected;

void dfs(int index)
{
    if (index == N)
    {
        if (selected.size() == 0)
            return;

        ll aa = 1; 
        ll bb = 0;

        for (auto i : selected)
        {
            aa *= a[i];
            bb += b[i];
        }
        ans = min(ans, abs(aa - bb));

        return;
    }

    selected.push_back(index);
    dfs(index + 1);
    selected.pop_back();
    dfs(index + 1);
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout.tie(0);

    cin >> N;

    rep(i, N)
    {
        cin >> a[i];
        cin >> b[i];
    }

    dfs(0);

    cout << ans;


    return 0;
}