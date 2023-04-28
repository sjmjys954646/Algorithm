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

vector<string> v;

int main() 
{
    int N;
    string tmp;

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        v.push_back(tmp);
    }

    int ans = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            string a = v[i];
            string b = v[j];

            bool pos = true;
            int arr[27];
            int visit[27];
            memset(arr, -1, sizeof(arr));
            memset(visit, 0, sizeof(visit));
            for (int k = 0; k < a.size(); k++)
            {
                if (arr[a[k] - 'a'] == -1)
                {
                    if (visit[b[k] - 'a'] == 1)
                    {
                        pos = false;
                        break;
                    }
                    arr[a[k] - 'a'] = b[k] - 'a';
                    visit[b[k] - 'a'] = 1;
                }
                else
                {
                    if (arr[a[k] - 'a'] != b[k] - 'a')
                    {
                        pos = false;
                        break;
                    }
                }
            }

            if (pos)
            {
                ans++;
            }
        }
    }

    cout << ans;

    return 0;
}