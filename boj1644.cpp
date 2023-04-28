#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

bool isPrime[4000001];
vector<int> prime;
int num;

void eratos()
{
   memset(isPrime, 1, sizeof(isPrime));
   isPrime[0] = isPrime[1] = false;
   int N = int(sqrt(4000001));

   for (int i = 2; i <= N; i++)
   {
      if (isPrime[i])
      {
         for (int j = i * i; j < 4000001; j += i)
         {
            isPrime[j] = false;
         }
      }
   }
}

int main()
{
   scanf("%d", &num);

   eratos();

   for (int i = 0; i < 4000001; i++)
   {
      if (isPrime[i] == true)
      {
         prime.push_back(i);
      }
   }
   int t = prime.size();
   int sum = 0;
   int left = 0;
   int right = 0;
   int ans = 0;
   while (true)
   {
      if (sum >= num)
      {
         sum -= prime[left];
         left++;
      }
      else
      {
         if (right == t)
            break;
         sum += prime[right];
         right++;
      }

      if (sum == num)
         ans++;
   }

   cout << ans;

   return 0;
}