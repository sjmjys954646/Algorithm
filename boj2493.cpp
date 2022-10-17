#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

class Tower {
public:
	int index;//Ÿ���� �ε���
	int height;
	int targetTowerIndex;
	
	Tower(int index, int height)
	{
		this->index = index;
		this->height = height;
		this->targetTowerIndex = 0;
	}

	void setTargetTowerIndex(int targetTowerIndex)
	{
		this->targetTowerIndex = targetTowerIndex;
	}

	int getTargetTowerIndex()
	{
		return this->targetTowerIndex;
	}
};

void findTargetTowers(vector<Tower>& towers) {
	//���� �ٸ� Ÿ���� ��ȣ�� ������ ���ɼ��� �ִ� Ÿ��
	stack<Tower> touchableTowers;

	for (int i = 0; i < towers.size(); i++)
	{
		while (true)
		{
			if (touchableTowers.empty())
			{
				towers[i].setTargetTowerIndex(0);
				touchableTowers.push(towers[i]);
				break;
			}

			if (touchableTowers.top().height > towers[i].height)
			{
				towers[i].setTargetTowerIndex(touchableTowers.top().index);
				touchableTowers.push(towers[i]);
				break;
			}
			else
				touchableTowers.pop();
		}
	}
}

int main()
{
	int n;
	cin >> n;

	vector<Tower> towers;
	for (int i = 0; i < n; ++i)
	{
		int hi;
		cin >> hi;
		towers.push_back(Tower(i + 1,hi));
	}

	findTargetTowers(towers);

	for (int i = 0; i < n; ++i) {
		if (i > 0) {
			cout << " ";
		}

		Tower t = towers[i];
		int targetIndex = t.getTargetTowerIndex();
		cout << targetIndex;
	}
	return 0;
}