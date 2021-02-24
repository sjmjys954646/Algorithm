//5648kb 0ms
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <queue>
#include <stack>
#include <cstring>

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

vector<int> vec;
int N, M;

int main()
{
    freopen("input.txt", "r", stdin);

    scanf("%d", &N);

    int left = 0;
    int right = N - 1;
    int ans = 0;

    vec.resize(N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &vec[i]);
    }

    scanf("%d", &M);

    sort(vec.begin(), vec.end());

    while (left < right)
    {
        if (vec[right] + vec[left] == M)
        {
            ans++;
            right--;
            left++;
        }
        else if (vec[right] + vec[left] > M)
        {
            right--;
        }
        else
        {
            left++;
        }
    }

    printf("%d", ans);

    return 0;
}
