// freopen("input.txt", "r", stdin);
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <cstring>
#include <list>
#include <set>
#include <string.h>
#include <map>
#include <limits.h>
#include <stdlib.h>
#include <typeinfo>
#include <bitset>

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

int B, C, D;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> B >> C >> D;
    int ans1 = 0;

    vector<int> b;
    vector<int> c;
    vector<int> d;

    int tmp;
    rep(i, B)
    {
        cin >> tmp;
        b.pb(tmp);
        ans1 += tmp;
    }

    rep(i, C)
    {
        cin >> tmp;
        c.pb(tmp);
        ans1 += tmp;
    }

    rep(i, D)
    {
        cin >> tmp;
        d.pb(tmp);
        ans1 += tmp;
    }

    int num = min(min(b.size(), c.size()), d.size());

    sort(b.begin(), b.end(), greater<>());
    sort(c.begin(), c.end(), greater<>());
    sort(d.begin(), d.end(), greater<>());

    int ans2 = 0;

    for (int i = 0; i < num; i++)
    {
        ans2 += (b[i] + c[i] + d[i]) * 0.9;
    }

    for (int i = num; i < b.size(); i++)
    {
        ans2 += b[i];
    }

    for (int i = num; i < c.size(); i++)
    {
        ans2 += c[i];
    }

    for (int i = num; i < d.size(); i++)
    {
        ans2 += d[i];
    }

    cout << ans1 << "\n" << ans2;

    return 0;
}