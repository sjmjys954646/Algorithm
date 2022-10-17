#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <math.h>
#include <cstdlib>
#include <utility>
#include <map>
#include <cstdio>
#include <string>
using namespace std;

string T, P;
vector<int> ans;
vector<int> pi;
int lenT, lenP;
void getPi() 
{
	int j = 0;
	for (int i = 1; i <= lenP; i++)
	{
		while (j > 0 && P[i] != P[j])
			j = pi[j - 1];
		if (P[i] == P[j])
			pi[i] = ++j;
	}
}

void kmp()
{
	int j = 0;
	for (int i = 0; i < lenT; i++)
	{
		while (j > 0 && T[i] != P[j])
			j = pi[j - 1];
		if (T[i] == P[j])
		{
			if (j == lenP - 1)
			{
				ans.push_back(i - j + 1);
				j = pi[j];
			}
			else
				j++;
		}
	}
}

int main()
{
	getline(cin, T);
	getline(cin, P);

	lenT = T.size();
	lenP = P.size();

	pi.resize(lenP, 0);

	getPi();
	kmp();

	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++)
	{
		printf("%d ", ans[i]);
	}

	return 0;
}