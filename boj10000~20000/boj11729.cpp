#include <iostream>

using namespace std;

void Recursive(int num, int from, int to, int sub);


int main()
{
	int num;
	int k = 1;
	
	cin >> num;
	
	for (int i = 0; i < num; i++)
	{
		k *= 2;
	}
	cout << k - 1<<'\n';
	Recursive(num, 1, 3, 2);

	return 0;
}

void Recursive(int num, int from ,int to,int sub)
{
	if (num <= 1)
	{
		cout << from << ' ' << to << '\n';
	}
	else
	{
		Recursive(num - 1, from, sub, to);
		cout << from << ' ' << to <<'\n';
		Recursive(num - 1, sub, to, from);
	}

}
