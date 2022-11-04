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
int tmp;
int arr[1000001];

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    int maxi = -1;
    int posL = -1;
    int posR = -1;
    int sumL = 0;
    int sumR = 0;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        arr[i] = tmp;
        maxi = max(maxi, tmp);
    }

    for (int i = 0; i < N; i++)
    {
        if (arr[i] == maxi)
        {
            if (posL == -1)
                posL = posR = i;
            else
                posR = i;
        }
    }

    sumL = posL;
    sumR = N - posR - 1;

    if (sumL == sumR)
        cout << 'X';
    else if (sumL > sumR)
        cout << 'B';
    else
        cout << "R";


    return 0;
}