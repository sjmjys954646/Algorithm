#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <string>
#include <cmath>
#include <map>
#include <stack>
#include <string.h>
using namespace std;

int N, M;
int arr[1050][1050];
int prefix[1050][1050];
int queryN;


int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> arr[i][j];
			prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j-1] + arr[i][j];
		}
	}

	cin >> queryN;

	int a, b, c, d;

	for (int i = 0; i < queryN; i++)
	{
		cin >> a >> b >> c >> d;
		cout << prefix[c][d] - prefix[a-1][d] - prefix[c][b-1] + prefix[a-1][b-1] << "\n";
	}
	
	return 0;
}
