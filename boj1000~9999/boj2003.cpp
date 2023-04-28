//5648kb 0ms
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

vector<ll> vec;
int N;
ll M;

int main()
{

    scanf("%d %lld", &N, &M);

    vec.resize(10003);

    ll sum = 0;
    for (int i = 1; i <= N; i++)
    {
        ll tmp;
        scanf("%lld", &tmp);
        sum += tmp;
        vec[i] = sum;
    }
    vec[0] = 0;

    int ans = 0;

    for (int i = 1; i <= N; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (M == (vec[i] - vec[j]))
                ans++;
        }
    }

    printf("%d", ans);

    return 0;
}
