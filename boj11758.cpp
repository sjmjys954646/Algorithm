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

int main()
{

    int x1, x2, x3, y1, y2, y3;

    scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);

    int a = x1 * y2 + x2 * y3 + x3 * y1;
    int b = y1 * x2 + y2 * x3 + y3 * x1;
    int tmp = a - b;

    if (tmp > 0)
    {
        printf("1");
    }
    else if (tmp < 0)
    {
        printf("-1");
    }
    else
    {
        printf("0");
    }

    return 0;
}
