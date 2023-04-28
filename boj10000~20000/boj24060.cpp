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
#include <deque>
#include <stack>
#include <cstring>
#include <list>
#include <set>
#include <string.h>
#include <map>
#include <limits.h>
#include <stdlib.h>
#include <typeinfo>
#include <bitset>

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

int sorted[555555];
int tmp[555555];
int sum = 0;
int N, K;

void merge(int list[], int left, int mid, int right) {
    int i, j, k, l;
    i = left;
    j = mid + 1;
    k = left;

    while (i <= mid && j <= right) {
        if (list[i] <= list[j])
        {
            tmp[k++] = list[i++];
        }
        else
        {
            tmp[k++] = list[j++];
        }
    }

    if (i > mid) {
        for (l = j; l <= right; l++)
        {
            tmp[k++] = list[l];
        }
    }
    else {
        for (l = i; l <= mid; l++)
        {
            tmp[k++] = list[l];
        }
    }

    for (l = left; l <= right; l++) {
        list[l] = tmp[l];
        sum++;
        if (sum == K)
            cout << list[l];
    }

}

void merge_sort(int list[], int left, int right) {
    int mid;

    if (left < right) {
        mid = (left + right) / 2;
        merge_sort(list, left, mid);
        merge_sort(list, mid + 1, right);
        merge(list, left, mid, right);
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int testcase;

    cin >> N >> K;

    for (int i = 0; i < N; i++)
    {
        cin >> sorted[i];
    }

    merge_sort(sorted, 0, N - 1);

    if (sum < K)
        cout << -1;

    return 0;
}