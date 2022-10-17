// freopen("input.txt", "r", stdin);
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
#include <string.h>
#include <map>
#include <limits.h>
#include <stdlib.h>

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
int N;
vi arr;
int arrNum[9000];

int main() 
{
    cin >> N;

    double sum = 0;
    rep(i, N)
    {
        int tmp;
        cin >> tmp;
        sum += tmp;
        arr.push_back(tmp);
        arrNum[tmp + 4000]++;
    }
    double ans1 = sum / (float)N;
    if (ans1 > -0.5 && ans1 < 0) ans1 = -ans1;

    sort(arr.begin(), arr.end());
    int ans2 = arr[(N - 1) / 2];
    int ans4 = arr[arr.size() - 1] - arr[0];

    int maxi = -1;
    int maxiNum = -1;
    for (int i = 0; i < 8001; i++) {
        if (arrNum[i] > maxiNum) {
            maxiNum = arrNum[i];
            maxi = i - 4000;
        }
    }
    for (int i = maxi + 4001; i < 8001; i++) {
        if (arrNum[i] == maxiNum) {
            maxi = i - 4000;
            break;
        }
    }
    int ans3 = maxi;

    printf("%.0f\n", ans1);
    cout << ans2 << "\n" << ans3 << "\n" << ans4;
    
}