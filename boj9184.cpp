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
using namespace std;

int A, B, C;

int arr[22][22][22];

int dp(int a, int b, int c)
{
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;

    if (a > 20 || b > 20 || c > 20)
        return dp(20,20,20);

    int & ret = arr[a][b][c];

    if (ret != -1)
        return ret;

    if (a < b && b < c)
        return ret = dp(a, b, c - 1) + dp(a, b - 1, c - 1) - dp(a , b - 1, c );

    return ret = dp(a-1, b, c ) + dp(a-1, b - 1, c ) +dp(a-1,b,c-1)- dp(a - 1, b - 1, c - 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(arr, -1, sizeof(arr));

    while (true)
    {
        cin >> A >> B >> C;

        if (A == -1 && B == -1 && C == -1)
            break;

        cout<<"w("<<A<<", " << B << ", " << C <<") = " << dp(A, B, C)<<"\n";
    }

    return 0;
}