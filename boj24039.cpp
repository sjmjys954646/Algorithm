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

const int INF = 9876543210;

int number = 120000; // 구하고자 하는 소수의 범위
int primeNum[120001];

vi v;
int bef = -1;
int N;

void primeNumberSieve()
{
    for (int i = 2; i <= number; i++)
    {
        primeNum[i] = i;
    }

    for (int i = 2; i <= sqrt(number); i++)
    {
        if (primeNum[i] == 0)
            continue;

        for (int j = i * i; j <= number; j += i)
            primeNum[j] = 0;
    }


    for (int i = 2; i <= 10000; i++)
    {
        if (primeNum[i] != 0)
        {
            if (bef == -1)
            {
                bef = primeNum[i];
            }
            else
            {
                v.push_back(bef * primeNum[i]);
                bef = primeNum[i];
            }
        }
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout.tie(0);

    cin >> N;

    primeNumberSieve();

    cout << *upper_bound(v.begin(), v.end(), N);
    

    return 0;
}