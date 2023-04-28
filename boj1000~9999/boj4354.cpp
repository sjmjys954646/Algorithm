//freopen("input.txt", "r", stdin);
//6132kb 84ms
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

using namespace std;

string T, P;
vector<int> ans;
vector<int> pi;

void getPi()
{
    int j = 0;
    for (int i = 1; i <= P.size(); i++)
    {
        while (j > 0 && P[i] != P[j])
            j = pi[j - 1];
        if (P[i] == P[j])
            pi[i] = ++j;
    }
}

// void kmp()
// {
//     int j = 0;
//     for (int i = 0; i < lenT; i++)
//     {
//         while (j > 0 && T[i] != P[j])
//             j = pi[j - 1];
//         if (T[i] == P[j])
//         {
//             if (j == lenP - 1)
//             {
//                 ans.push_back(i - j + 1);
//                 j = pi[j];
//             }
//             else
//                 j++;
//         }
//     }
// }

int main()
{
    //https://octorbirth.tistory.com/276

    while (true)
    {
        cin >> P;
        if (P == ".")
            break;

        pi.clear();
        pi.resize(P.size(), 0);

        getPi();

        if (pi[P.length() - 1] == 0 || pi[P.length() - 1] % (P.length() - pi[P.length() - 1]))
            cout << 1 << "\n";
        else
            cout << P.length() / (P.length() - pi[P.length() - 1]) << "\n";
    }

    return 0;
}
