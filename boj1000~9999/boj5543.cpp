#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int burger[3];
	int min = 987654321;
	for(int i = 0;i<3;i++)
	{
		cin >> burger[i];
		if(min > burger[i])
			min = burger[i];
	}
	int a, b;
	cin >> a >> b;
	a = a < b ? a : b;
	cout<<min + a - 50;
	
	return 0;
}