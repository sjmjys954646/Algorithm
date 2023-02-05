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

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	int T, S;

	cin >> T >> S;

	if (S == 1 || T <= 11 || T >= 17)
		cout << 280;
	else
		cout << 320;



	return 0;
}
