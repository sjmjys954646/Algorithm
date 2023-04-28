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

int dx[8] = {0,1,1,1,0,-1,-1,-1};
int dy[8] = {-1,-1,0,1,1,1,0,-1};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true)
    {
        int arr[101][101];
        char ans[101][101];
        int R, C;
        cin >> R >> C;


        if (R == 0 && C == 0)
            break;

        for (int i = 0; i < R; i++)
        {
            string tmp;
            cin >> tmp;
            for (int j = 0; j < C; j++)
            {
                arr[i][j] = tmp[j];
            }
        }

        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                if (arr[i][j] == (int)'*')
                {
                    ans[i][j] = '*';
                    continue;
                }

                int sum = 0;
                for (int k = 0; k < 8; k++)
                {
                    int nX = j + dx[k];
                    int nY = i + dy[k];

                    if (nX < 0 || nY < 0 || nX >= C || nY >= R)
                        continue;

                    if (arr[nY][nX] == (int)'*')
                        sum++;
                }
                ans[i][j] = (char)(sum + '0');
            }
        }

        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cout << ans[i][j];
            }
            cout << "\n";
        }
    }

   

    return 0;
}