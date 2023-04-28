#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

string str;

int main() 
{
	int N;
	char c;
	scanf("%d", &N);
	getchar();
	for (int i = 0; i < N; i++)
	{
		scanf("%c", &c);
		if (c == 'J' || c == 'V' || c == 'A')
			continue;

		str += c;
	}

	if (!str.length())
		printf("nojava");
	else
		cout << str;
}