#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <stdio.h>
#include <string>
#include <math.h>
#include <map>
#define Max(a,b) a < b ? b : a;
#define Min(a,b) a < b ? a : b;

using namespace std;

long long five(int n) 
{ 
	long long fiveC = 0;
	
	for (long long i = 5; i <= n; i *= 5) 
	{	
		fiveC += n / i; 
	} 
 
	return fiveC; 
} 

long long two(int n)
{ 
	long long twoC = 0;
	for (long long i = 2; i <= n; i *= 2) 
	{ 
		twoC += n / i; 
	} 
	return twoC; 
} 

long long result(int n, int r) 
{ 
	int fiveC = five(n) - five(r) - five(n - r); 
	int twoC = two(n) - two(r) - two(n - r);
	return (fiveC < twoC) ? fiveC : twoC; 
}

int main()
{
	int N, K;

	cin >> N >> K;

	cout << result(N, K);

	return 0;
}