#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

int arr[9] = { 100, 100, 200, 200, 300, 300, 400, 400 ,500 };
int garr[9];

int main() 
{
	int sum = 0;
	bool ishack = false;
	int input;
	for (int i = 0; i < 9; i++)
	{
		scanf("%d", &input);
		if (input > arr[i])
		{
			ishack = true;
		}
		sum += input;
	}
	if (ishack)
		printf("hacker");
	else if (sum < 100)
		printf("none");
	else
		printf("draw");


}