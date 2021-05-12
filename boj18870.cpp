//freopen("input.txt", "r", stdin);
//8940kb 112ms
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
#include <string.h>
#include <map>
#include <limits.h>
#include <stdlib.h>

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

ll arr[1000002];
vector<ll> vec;

int main()
{
    freopen("input.txt", "r", stdin);

    int N;
    ll tmp;
    int cnt = 0;

    scanf("%d", &N);

    rep(i, N)
    {
        scanf("%lld", &tmp);
        arr[i] = tmp;
        vec.push_back(tmp);
    }

    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());

    rep(i, N)
    {
        int pos = lower_bound(vec.begin(), vec.end(), arr[i]) - vec.begin();
        printf("%d ", pos);
    }

    return 0;
}
