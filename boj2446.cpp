#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define X first
#define Y second
using namespace std;

const int INF = 987654321;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;

	cin >> N;

	for (int i = N; i >= 1; i--)
	{
		for (int j = 0; j < N - i; j++)
		{
			cout << " ";
		}
		for (int j = 0; j < 2 * i - 1; j++)
		{
			cout<<"*";
		}
		cout << "\n";
	}
	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j < N - i; j++)
		{
			cout << " ";
		}
		for (int j = 0; j < 2 * i - 1; j++)
		{
			cout << "*";
		}
		cout << "\n";
	}
	

	return 0;
}