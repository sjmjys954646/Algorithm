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

int arrA[32];
int arrB[32];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int D, K;
    int ansA, ansB;

    cin >> D >> K;

    arrA[3] = 1;
    arrA[4] = 1;
    arrB[3] = 1;
    arrB[4] = 2;

    for (int i = 5; i <= 30; i++)
    {
        arrA[i] = arrA[i - 1] + arrA[i - 2];
        arrB[i] = arrB[i - 1] + arrB[i - 2];
    }

    for (int i = 1; i <= 50000; i++)
    {
        if (K - arrA[D] * i <= 0)
            continue;

        if ((K - arrA[D] * i) % arrB[D] != 0)
            continue;

        ansA = i;
        ansB = (K - arrA[D] * i) / arrB[D];
        break;
    }
    cout << ansA << "\n" << ansB;
    

    return 0;

}