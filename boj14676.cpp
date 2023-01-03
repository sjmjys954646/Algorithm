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

int N, M, K;
vector<int> arr[100002];
int indegree[100002];
int a, b;
int mapBuild[100002];
bool check = true;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout.tie(0);

    cin >> N >> M >> K;

    for (int i = 0; i < M; i++)
    {
        cin >> a >> b;
        arr[a].push_back(b);
        indegree[b]++;
    }

    for (int i = 0; i < K; i++)
    {
        cin >> a >> b;

        if (a == 1)
        {
            if (indegree[b] == 0)
            {
                mapBuild[b]++;

                if (mapBuild[b] == 1)
                {

                    for (int j = 0; j < arr[b].size(); j++)
                    {
                        int next = arr[b][j];
                        indegree[next]--;
                    }
                }
            }
            else
            {
                check = false;
                break;
            }
        }
        else if(a == 2)
        {
            if (mapBuild[b] > 0)
            {
                mapBuild[b]--;

                if (mapBuild[b] == 0)
                {
                    for (int j = 0; j < arr[b].size(); j++)
                    {
                        int next = arr[b][j];
                        indegree[next]++;
                    }
                }
            }
            else
            {
                check = false;
                break;
            }
        }
    }
    
    if (check)
        cout << "King-God-Emperor";
    else
        cout << "Lier!";

    return 0;
}