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
#include <stack>
#include <cstring>
#include <list>
#include <set>
#include <string.h>
#include <map>
#include <limits.h>
#include <stdlib.h>
#include <typeinfo>

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

int testcase;
int N, M;

int arr[5] = { 0, };
vector<pii> v;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int K;
    int a, b;
    int minIndex = INF;
    int mini = INF;
    cin >> K;

    rep(i, 6)
    {
        cin >> a >> b;
        arr[a]++;
        v.pb({ a,b });
        if (mini > b)
        {
            mini = b;
            minIndex = i;
        }
    }

    int x, y;
    int minx, miny;
    vi hubo;
    vi huboIndex;

    rep(i, 6)
    {
        if (arr[i] == 1)
        {
            hubo.pb(i);
        }
    }
    rep(i, 2)
    {
        rep(j, 6)
        {
            if (v[j].first == hubo[i])
            {
                huboIndex.push_back(j);
                break;
            }
        }
    }

    int cur = huboIndex[0];
    while (1)
    {
        if (minIndex == huboIndex[0] || minIndex == huboIndex[1])
        {
            cur = minIndex;
            break;
        }

        minIndex++;
        minIndex = minIndex % 6;
    }


    minx = (cur + 3) % 6;
    miny = (cur + 4) % 6;

    cout << (v[huboIndex[0]].S * v[huboIndex[1]].S - v[minx].S * v[miny].S) * K;

    return 0;
}