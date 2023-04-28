//2096kb 0ms
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

int chewArr[31];
int chewN;
int goosulN;
int cache[31][15003];

void dp(int cur, int sum)
{
    if (cur > chewN)
        return;

    int &ret = cache[cur][sum];
    if (ret != -1)
        return;

    ret = 1;

    dp(cur + 1, abs(sum - chewArr[cur]));
    dp(cur + 1, sum);
    dp(cur + 1, sum + chewArr[cur]);

    return;
}

int main()
{
    memset(cache, -1, sizeof(cache));

    scanf("%d", &chewN);

    for (int i = 0; i < chewN; i++)
    {
        scanf("%d", &chewArr[i]);
    }

    scanf("%d", &goosulN);

    dp(0, 0);

    while (goosulN--)
    {
        int query;
        scanf("%d", &query);
        if (query > 15000)
        {
            cout << "N ";
        }
        else if (cache[chewN][query] == 1)
            printf("Y ");
        else
            printf("N ");
    }

    return 0;
}