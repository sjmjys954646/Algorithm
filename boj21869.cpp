#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;


int main() 
{
	int N;
	
	scanf("%d", &N);

	if (N <= 2)
		printf("%d\n", N);
	else
		printf("%d\n", N*2 - 2);

	for (int i = 0; i < N; i++)
	{
		printf("%d %d\n", 1, i + 1);
	}

	if (N > 2)
	{
		for (int i = 2; i < N; i++)
		{
			printf("%d %d\n", N, i);
		}
	}
}