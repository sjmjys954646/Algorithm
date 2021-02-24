//6132kb 84ms
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
#include <list>
#include <set>

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

int arr[100002];
int N, SS;

int main()
{
    freopen("input.txt", "r", stdin);

    scanf("%d %d", &N, &SS);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }

    int left = 0;
    int right = 0;
    int sum = arr[0];
    int ans = 987654321;

    while (right < N)
    {
        if (sum > SS)
        {
            ans = min(ans, right - left + 1);

            sum -= arr[left];
            left++;
        }
        else if (sum < SS)
        {
            right++;
            sum += arr[right];
        }
        else
        {
            ans = min(ans, right - left + 1);
            right++;
            sum += arr[right];
        }
    }

    if (ans == 987654321)
        printf("0");
    else
        printf("%d", ans);
    return 0;
}
