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

int arr[7][7];

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 7; i++)
    {
        string tmp;
        getline(cin, tmp);
        for (int j = 0; j < 7; j++)
        {
            if (tmp[j] == 'o')
                arr[i][j] = 1;
            else if(tmp[j] == '.')
                arr[i][j] = -1;
        }
    }
    int sum = 0;
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};

    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (arr[i][j] == 1)
            {
                for (int k = 0; k < 4; k++)
                {
                    int curX = j + dx[k];
                    int curY = i + dy[k];
                    if (curX >= 7 || curX < 0 || curY >= 7 || curY < 0)
                        continue;
                    if (arr[curY][curX] == 1)
                    {
                        curX = curX + dx[k];
                        curY = curY + dy[k];
                        if (curX >= 7 || curX < 0 || curY >= 7 || curY < 0)
                            continue;
                        if (arr[curY][curX] == -1)
                            sum++;
                    }
                }
            }            
        }
    }
    cout << sum;

    return 0;
}