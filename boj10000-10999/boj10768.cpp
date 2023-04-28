#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

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

int tmp;

int main()
{
    int a, b;

    cin >> a >> b;

    if (a < 2)
    {
        cout << "Before";
    }
    else if (a >= 3)
    {
        cout << "After";
    }
    else if (a == 2 && b > 18)
    {
        cout << "After";
    }
    else if (a == 2 && b < 18)
    {
        cout << "Before";
    }
    else
        cout << "Special";


    return 0;
}