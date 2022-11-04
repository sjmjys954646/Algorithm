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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int maxi = -1;
    int ansY;
    int ansX;

    rep(i, 9)
    {
        rep(j, 9)
        {
            cin >> N;
            if (N > maxi)
            {
                maxi = N;
                ansX = j + 1;
                ansY = i + 1;
            }
        }
    }
    cout << maxi << "\n";
    cout << ansY << " " << ansX;
        


    return 0;
}