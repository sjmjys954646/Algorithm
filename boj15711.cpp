#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

bool isPrime[2000001];
vector<int> prime;


void eratos()
{
	memset(isPrime,1,sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;
	int N = int(sqrt(2000001));
	
	for(int i = 2;i<=N ;i++)
	{
		if(isPrime[i])
		{
			for(int j = i*i;j < 2000001;j+=i)
			{
				isPrime[j] = false;
			}
		}
	}
}

bool check(long long a)
{
	for(int i = 0; i < (int)prime.size() && (long long)prime[i] * prime[i] <= a; i++)
	{
		if(a % prime[i] == 0) 
		{
			return false;
		}
	}
	return true;
}

int main() 
{
	eratos();

	for(int i = 0;i<2000001;i++)
	{
		if(isPrime[i] == true)
		{
			prime.push_back(i);
		}
	}
	
	int testcase;
	
	scanf("%d",&testcase);
	
	while(testcase--)
	{
		long long a ,b;
		
		scanf("%lld %lld",&a, &b);
		
		long long sum = a+b;
		
		if(sum<4)
		{
			printf("NO\n");
			continue;
		}
		
		if(sum % 2 == 0)
		{
			printf("YES\n");
			continue;
		}
		
		sum-=2;
		
		if(check(sum))
			printf("YES\n");
		else
			printf("NO\n");
		
	}
	

	
	return 0;
}