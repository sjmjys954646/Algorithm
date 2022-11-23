// freopen("input.txt", "r", stdin);
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

int main() 
{
    int tmp;
    int a;
    int index = 1;
    while (true)
    {
        cin >> a;
        if (a == 0)
            break;
        
        for (int i = 0; i < a; i++)
            cin >> tmp;

        cout << "Case " << index << ": Sorting... done!\n";

        index++;
    }

    return 0;
}