#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <queue>
#include <stack>
#include <cstring>
#define X first
#define Y second

using namespace std;

vector<vector<long long>> start = {{1, 1}, {1, 0}};

vector<vector<long long>> mul(vector<vector<long long>> a, vector<vector<long long>> b)
{
    vector<vector<long long>> ret(2);
    for (int i = 0; i < 2; i++)
    {
        ret[i].resize(2);
        for (int j = 0; j < 2; j++)
        {
            ret[i][j] = 0;
            for (int k = 0; k < 2; k++)
            {
                ret[i][j] += a[i][k] * b[k][j];
                ret[i][j] %= 1000000007;
            }
        }
    }
    return ret;
}

vector<vector<long long>> rec(long long num)
{
    if (num == 1)
        return start;
    vector<vector<long long>> tmp;
    if (num % 2 == 1)
    {
        tmp = rec(num - 1);
        return mul(start, tmp);
    }
    else
    {
        tmp = rec(num / 2);
        return mul(tmp, tmp);
    }
}

int main()
{

    long long int N;

    scanf("%lld", &N);

    vector<vector<long long>> ans = rec(N);

    printf("%lld", ans[1][0]);

    return 0;
}