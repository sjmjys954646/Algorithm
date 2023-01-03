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

int M, N , K;
set<pii> s;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout.tie(0);

    cin >> M >> N >> K;

    int a, b;
    int ans = 0;
    int find = 0;

    rep(i, K)
    {
        cin >> a >> b;
        s.insert({ a,b });
    }

    while (true)
    {
        if (find == K)
            break;

        ans++;
        
        auto bef = *s.begin();
        auto it = s.begin();
        s.erase(it);
        find++;
        it = s.begin();

        while (true)
        {
            
            if (it == s.end())
                break;

            if (bef.first <= it->first && bef.second <= it->second)
            {
                find++;
                bef = *it;
                s.erase(it++);
            }
            else
                it++;
        }

    }
    
    cout << ans;

    return 0;
}