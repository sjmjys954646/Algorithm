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

int testcase;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    string tmp;
    long long ans = 0;
    long long arr[10];
    long long impos[10];

    memset(arr, 0, sizeof(arr));
    memset(impos, 0, sizeof(impos));

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        int numl = tmp.length();
        char cur = tmp[0];
        impos[cur - 'A'] = 1;
        for (int j = 0; j < numl; j++)
        {
            arr[tmp[j] - 'A'] += pow(10, numl - j - 1);
        }
    }
    int zeroHubo = -1;
    for (int i = 0; i < 10; i++)
    {
        if (zeroHubo != -1)
            break;

        if (impos[i] != 1)
            zeroHubo = i;
    }
    for (int i = 0;i < 10; i++)
    {
        if (impos[i] != 1 && arr[i] < arr[zeroHubo])
            zeroHubo = i;
    }
    arr[zeroHubo] = 0;
    sort(arr, arr + 10);
    int index = 9;
    for (int i = 9; i >= 0; i--)
    {
        ans += arr[i] * index;
        index--;
    }

    cout << ans;
    

    return 0;
}