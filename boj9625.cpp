#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <string>
#include <cmath>
#include <map>
#include <stack>
#include <sstream>
#include <string.h>
#include <queue>
using namespace std;

const int INF = 987654321;

int fibo[55];

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	fibo[0] = 0;
	fibo[1] = 1;

	for (int i = 2; i <= 50; i++)
		fibo[i] = fibo[i - 1] + fibo[i - 2];

	int N;

	cin >> N;
	cout << fibo[N - 1] << " " << fibo[N];
	

	return 0;
}
