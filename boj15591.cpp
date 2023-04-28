#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <queue>
#include <stack>
#include <cstring>
#define X first
#define Y second
using namespace std;

int N, Q;
vector<pair<int,long long> > arr[5002];
bool visited[5002];
int K, U;
queue<int> q;
int ans = 0;

void BFS()
{

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        visited[cur] = true;


        for (auto index : arr[cur])
        {
            int des = index.X;
            int W = index.Y;

            if (visited[des])
                continue;

            if (W >= K)
            {
                q.push(des);
                ans++;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> Q;
    
    for (int i = 1; i < N; i++)
    {
        int a, b;
        long long r;

        cin >> a >> b >> r;

        arr[a].push_back({ b,r });
        arr[b].push_back({ a,r });
    }

    for (int i = 0; i < Q; i++)
    {
        ans = 0;
        memset(visited, 0, sizeof(visited));

        cin >> K >> U;
        q.push(U);
        BFS();

        cout << ans<<"\n";
    }

    return 0;
}