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

const int INF = 1e9;

int testcase;

int N, M, K, Q, L;
int ans[70002];


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);

    cin >> N;

    vector<int> arr;

    rep(i, N)
    {
        int a;
        cin >> a;
        arr.pb(a);
    }
    int index = N;
    rep(i,N)
    {
        if (arr[i] < 0) 
            continue;

        ans[i] = index;
        index--;
    }

    for(int i = N-1;i>=0;i--) 
    {
        if (arr[i] > 0) 
            continue;

        ans[i] = index;
        index--;
    }

    if (arr[N - 1] < 0)
    {
        cout << -1;
    }
    else
    {
        for (int i = 0; i < N; i++)
            cout << ans[i] << " ";
    }


    return 0;
}
