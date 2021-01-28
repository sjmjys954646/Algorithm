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
#define X first
#define Y second

using namespace std;

int cache[10002];
string S;
string A[10002];
int Alen[10002];
int N;

int main()
{
    memset(cache, -1, sizeof(cache));

    freopen("input.txt", "r", stdin);

    cin >> S;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        Alen[i] = A[i].length();
    }

    for (int index = 1; index <= S.length(); index++) //index
    {
        bool check = false;
        for (int i = 1; i < index + 1; i++)
        {
            if (cache[index - i] == 0)
                continue;

            string tmp = S.substr(index - i, i);

            for (int k = 0; k < N; k++)
            {
                if (Alen[k] != i)
                    continue;

                if (A[k] == tmp)
                {
                    cache[index] = 1;
                    check = true;
                    break;
                }
            }
        }
        if (!check)
            cache[index] = 0;
    }

    cout << cache[S.length()];

    return 0;
}
