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
using namespace std;

long long int road[100002];
long long int oil[100002];
int N;
long long int cost = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N - 1; i++)
    {
        cin >> road[i];
    }
    for (int i = 0; i < N ; i++)
    {
        cin >> oil[i];
    }

    long long int cur = 1000000003;
    for (int i = 0; i < N - 1; i++)
    {
        if (cur > oil[i])
            cur = oil[i];
        cost += cur * road[i];
    }

    cout << cost;

   
    return 0;
}