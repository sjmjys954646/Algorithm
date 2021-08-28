//freopen("input.txt", "r", stdin);
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

int barr[10000];
int arr[4];
int tarr[4];
int ans = 1;

void makeArr(int dep)
{
    if (dep == 4)
    {
        rep(i, 4)
        {
            int idx = i;
            int cnt = 0;
            int sum = 0;
            while (cnt < 4)
            {
                sum += arr[idx] * pow(10, 3 - cnt);
                idx++;
                cnt++;
                if (idx == 4)
                    idx = 0;
            }
            tarr[i] = sum;
        }
        sort(tarr, tarr + 4);

        barr[arr[0] * 1000 + arr[1] * 100 + arr[2] * 10 + arr[3]] = tarr[0];

        return;
    }

    for (int i = 1; i < 10; i++)
    {
        arr[dep] = i;
        makeArr(dep + 1);
    }
}

int main()
{
    freopen("input.txt", "r", stdin);

    for (int i = 0; i < 10000; i++)
    {
        barr[i] = INF;
    }

    makeArr(0);
    int tmp = 0;
    int ans = 0;

    rep(i, 4)
    {
        scanf("%d", &arr[i]);
        tmp += arr[i] * pow(10, 3 - i);
    }

    tmp = barr[tmp];

    sort(barr, barr + 10000);

    for (int i = 0; i < 10000; i++)
    {
        if (i != 0 && barr[i] == barr[i - 1])
            continue;
        ans++;
        if (barr[i] == tmp)
        {
            break;
        }
    }

    printf("%d", ans);

    return 0;
}