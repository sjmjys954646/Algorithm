#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

bool isPrime[1000001];
vector<int> prime;


void eratos()
{
	memset(isPrime,1,sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;
	int N = int(sqrt(1000001));
	
	for(int i = 2;i<=N ;i++)
	{
		if(isPrime[i])
		{
			for(int j = i*i;j < 1000001;j+=i)
			{
				isPrime[j] = false;
			}
		}
	}
}

int main() 
{
	int num;
	
	eratos();

	for(int i = 0;i<1000001;i++)
	{
		if(isPrime[i] == true)
		{
			prime.push_back(i);
		}
	}
	
	while(true)
	{
		scanf("%d",&num);
		
		if(!num)
			break;
			
		int a,b;
		
		for(int i = 0;;i++)
		{
			a = prime[i];
			b = num - prime[i];
			if(a > b)
			{
				break;
			}
			
			if(binary_search(prime.begin(),prime.end(),num-prime[i]))
			{
				cout<<num<<" = "<<a<<" + "<<b<<"\n";
				break;
			}
		}
		
	}
	

	
	return 0;
}