#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <string>

#define SIZE 301

using namespace std;

int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int N;
	int ans = 0;
	int tmp;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> tmp;

		ans += (tmp - 1);
	}

	cout << ans + 1;
	
	return 0;

}
