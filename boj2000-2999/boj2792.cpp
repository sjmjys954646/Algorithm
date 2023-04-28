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

const int INF = INT_MAX;

int testcase;

vi v;
int N, M;

int check(int mid)
{
    int sum = 0;
    for (int i = 0; i < M; i++)
    {
        sum += (v[i] / mid);
        if (v[i] % mid != 0)
            sum += 1;
    }
    if (sum > N)
        return 1;
    else
        return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    int maxi = -1;
    rep(i, M)
    {
        int tmp;
        cin >> tmp;
        v.pb(tmp);
        maxi = max(tmp, maxi);
    }

    int lo = 1;
    while (lo + 1 < maxi)
    {
        int mid = (lo + maxi) / 2;
        if (check(mid))
        {
            lo = mid;
        }
        else
        {
            maxi = mid;
        }
    }

    cout  << maxi << "\n";

    return 0;
}