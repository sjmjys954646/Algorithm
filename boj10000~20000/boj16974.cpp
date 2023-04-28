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

ll N, X;
ll ans = 0;
ll cache[52]; // °í±â
ll tot[52]; // °í±â + »§

ll dq(ll level, ll point)
{
    if (level == 0)
    {
        if (point == 1)
            return 1;
        else
            return 0;
    }

    if (point == 1)//»§
        return 0;
    else if (point <= 1 + tot[level - 1])//¹ö°Å
        return dq(level - 1, point - 1);
    else if (point ==  tot[level - 1] + 2)//°í±â
        return cache[level - 1] + 1;
    else if (point <= tot[level - 1]*2 + 2)//¹ö°Å
        return 1 + cache[level - 1] + dq(level - 1, point  - tot[level - 1] - 2);
    else//»§
        return 2 * cache[level - 1] + 1;

}

int main()
{
    cin >> N >> X;

    cache[0] = 1;
    tot[0] = 1;

    for (int i = 1; i <= 50; i++)
    {
        tot[i] = tot[i - 1] * 2 + 3;
        cache[i] = cache[i - 1] * 2 + 1;
    }

    cout << dq(N,X);
    

    return 0;
}