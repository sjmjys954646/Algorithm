#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

typedef pair<long long, long long> p;
#define F first
#define S second

int ccw(p a, p b, p c)
{
   long long tmp1 = a.F * b.S + b.F * c.S + c.F * a.S;
   long long tmp2 = a.S * b.F + b.S * c.F + c.S * a.F;
   long long tmp = tmp1 - tmp2;

   if (tmp > 0)
      return 1; //반시계
   else if (tmp < 0)
      return -1; //시계
   else
      return 0;
}

bool crossChk(p a, p b, p c, p d)
{
   int abc = ccw(a, b, c);
   int abd = ccw(a, b, d);
   int cda = ccw(c, d, a);
   int cdb = ccw(c, d, b);

   if (abc * abd == 0 && cda * cdb == 0)
   {
      if (a > b)
         swap(a, b);
      if (c > d)
         swap(c, d);

      return a <= d && c <= b;
   }

   return abc * abd <= 0 && cda * cdb <= 0;
}

int main()
{
   vector<p> vp(4);

   for (int i = 0; i < 4; i++)
   {
      cin >> vp[i].F >> vp[i].S;
   }

   if (crossChk(vp[0], vp[1], vp[2], vp[3]))
      cout << "1\n";
   else
      cout << "0\n";

   return 0;
}