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

int N;
vector<pii> v;
multiset<int> ms;


bool cmp(pii a, pii b)
{
    if (a.second != b.second)
        return a.second < b.second;
    else
        return a.first < b.first;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout.tie(0);

    cin >> N;

    int a, b;

    rep(i, N)
    {
        cin >> a >> b;
        v.push_back({ a,b });
    }

    sort(v.begin(), v.end(), cmp);

    rep(i, N)
    {
        pii cur = v[i];

        if (i == 0)
        {
            ms.insert(cur.second);
            continue;
        }

        auto it = ms.upper_bound(cur.first);

        if (it == ms.begin())
        {
            ms.insert(cur.second);
            continue;
        }
        else
        {
            it--;
            ms.erase(it);
            ms.insert(v[i].second);
        }
    }
    cout << ms.size();

    return 0;
}