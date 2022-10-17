//6132kb 84ms
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
#include <stack>
#include <cstring>
#include <list>
#include <set>

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

pair<ll, ll> arr[10002];

int main()
{

    int N;

    scanf("%d", &N);

    rep(i, N)
    {
        scanf("%lld %lld", &arr[i].F, &arr[i].S);
    }

    ll sum = 0;

    rep(i, N - 1)
    {
        sum += (arr[i].F * arr[i + 1].S - arr[i].S * arr[i + 1].F);
    }

    sum += (arr[N - 1].F * arr[0].S - arr[N - 1].S * arr[0].F);

    long double ans = (long double)abs(sum) / 2;

    printf("%.1Lf", ans);

    return 0;
}
