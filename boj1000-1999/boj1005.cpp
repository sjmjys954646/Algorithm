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
using namespace std;

int T;
int N, K, X, Y, W, D;
int time[100002];
vector<int> arr[100002];
int indegree[100002];
int total[100002];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> T;

    while (T--)
    {
        /*initialization*/
        for (int i = 0; i < 100002; i++)
        {
            arr[i].clear();
            time[i] = 0;
            indegree[i] = 0;
            total[i] = 0;
        }
        /*initialization*/

        /* Input */
        cin >> N >> K;
        for (int i = 1; i <= N; i++)
        {
            cin >> D;
            time[i] = D;
        }
        for (int i = 0; i < K; i++)
        {
            cin >> X >> Y;
            arr[X].push_back(Y);
            indegree[Y]++;
        }
        cin >> W;
        /* Input */

        queue<int> q;
        for (int i = 1; i <= N; i++)
        {
            if (indegree[i] == 0)
                q.push(i);
            total[i] += time[i];
        }
        
        for (int i = 1; i <= N ; i++)
        {
            int tmp = q.front();
            q.pop();

            for (int j = 0; j < arr[tmp].size(); j++)
            {
                int next = arr[tmp][j];
                if (total[next] < total[tmp] + time[next])
                {
                    total[next] = total[tmp] + time[next];
                }
                --indegree[next];
                if (indegree[next] == 0)
                    q.push(next);
            }        
        }

        cout << total[W]<<"\n";

    }
    

    return 0;
}