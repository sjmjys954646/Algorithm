//freopen("input.txt", "r", stdin);
//6636kb 48ms
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

vi clockA;
vi clockB;
vi discA;
vi discB;
string T, P;
vector<int> ans;
vector<int> pi;
int lenT, lenP;

void getPi()
{
    int j = 0;
    for (int i = 1; i <= lenP; i++)
    {
        while (j > 0 && P[i] != P[j])
            j = pi[j - 1];
        if (P[i] == P[j])
            pi[i] = ++j;
    }
}

void kmp()
{
    int j = 0;
    for (int i = 0; i < lenT; i++)
    {
        while (j > 0 && T[i] != P[j])
            j = pi[j - 1];
        if (T[i] == P[j])
        {
            if (j == lenP - 1)
            {
                ans.push_back(i - j + 1);
                j = pi[j];
            }
            else
                j++;
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);

    int N;
    int tmp;

    scanf("%d", &N);

    rep(i, N)
    {
        scanf("%d", &tmp);
        clockA.pb(tmp);
    }
    rep(i, N)
    {
        scanf("%d", &tmp);
        clockB.pb(tmp);
    }

    sort(clockA.begin(), clockA.end());
    sort(clockB.begin(), clockB.end());

    clockA.pb(clockA.front());
    clockB.pb(clockB.front());

    for (int i = 1; i <= N; i++)
    {
        discA.pb(clockA[i] - clockA[i - 1]);
        discB.pb(clockB[i] - clockB[i - 1]);
    }

    for (int i = 0; i < discA.size(); i++)
    {
        if (discA[i] < 0)
            discA[i] += 360000;
        if (discB[i] < 0)
            discB[i] += 360000;
    }

    for (int i = 0; i < discA.size(); i++)
    {
        T += to_string(discA[i]);
        P += to_string(discB[i]);
    }
    T = T + T;

    lenT = T.length();
    lenP = P.length();
    pi.resize(lenP, 0);

    getPi();
    kmp();

    if (ans.empty())
        printf("impossible");
    else
        printf("possible");

    return 0;
}