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

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    vector<pii> v;
    vector<pii> vcar;
    int N, M;
    int a, b;
    int ans = 0;

    cin >> N >> M;

    int tot = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> a >> b;
        tot += a;
        v.push_back({ tot,b });
    }

    tot = 0;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        tot += a;
        vcar.push_back({ tot,b });
    }
    
    int cur = 0;
    int left = 0;
    int carleft = 0;

    while (true)
    {
        if (cur == 101)
            break;

        ans = max(ans, vcar[carleft].second - v[left].second);

        if (cur == v[left].first && left != N-1)
            left++;

        if (cur == vcar[carleft].first && carleft != M - 1)
            carleft++;

        cur++;
    }
    
    cout << ans;

	return 0;
}