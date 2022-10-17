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


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string a, b;
    string ans = "";

    cin >> a >> b;

    int n = a.length() - 1;
    int m = b.length() - 1;

    string tmp = "";

    int t = abs(m - n);

    if (m != n)
    {
        if (n < m)
        {
            for (int i = 0; i < t; i++)
            {
                tmp += "0";
            }
            a = tmp + a; 
        }
        else
        {
            for (int i = 0; i < t; i++)
            {
                tmp += "0";
            }
            b = tmp + b;
        }
    }

    int len = a.size();
    int x, y, z;
    int up = 0;

    for (int i = len - 1; i >= 0; i--) {
        x = a[i] - '0';
        y = b[i] - '0';
        z = x + y;

        if (up == 1)
        {
            z += 1;
            up = 0;
        }


        if (z > 9)
        {
            ans += to_string(z % 10);
            up = 1;
        }
        else
        {
            ans += to_string(z);
        }
    }

    if (up == 1) 
        ans += "1";

    reverse(ans.begin(), ans.end());

    cout << ans << '\n';

    return 0;
}