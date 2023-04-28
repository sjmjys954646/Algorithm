// freopen("input.txt", "r", stdin);
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>

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

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int finger;
	long long num;

	cin >> finger;
	cin >> num;

	int arr[5] = {0, 1, 2, 3, 4};

	if (finger == 1) {
		cout << num * 8;
	} else if (finger == 2) {
		if (num % 2 == 1)
			cout << num * 4 + 3;
		else
			cout << num * 4 + 1;
	} else if (finger == 3) {
		cout << num * 4 + 2;
	} else if (finger == 4) {
		if (num % 2 == 1)
			cout << num * 4 + 1;
		else
			cout << num * 4 + 3;
	} else if (finger == 5) {
		cout << num * 8 + 4;
	}
}