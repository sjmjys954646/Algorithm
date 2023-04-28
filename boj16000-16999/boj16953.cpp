#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>
#define X first
#define Y second
using namespace std;

const int INF = 987654321;
int A, B;
class Node
{
public:
	long long data;
	int pos;
	Node* left;
	Node* right;
	Node(long long dat, int po) : data(dat), pos(po), left(0), right(0) {}
};
Node* ans = 0;

class BTree
{
public:
	Node* root;
	BTree() : root(0) {}

	void init(long long data, int pos)
	{
		Insert(root, data, pos);
	}
	void Insert(Node* current, long long data, int pos)
	{
		if (current == 0)
		{
			current = new Node(data, pos);
		}
		if (data < B)
		{
			current->left = new Node(data * 2, pos + 1);
			current->right = new Node(data * 10 + 1, pos + 1);
			Insert(current->left, data * 2, pos + 1);
			Insert(current->right, data * 10 + 1, pos + 1);
		}
		else
		{
			if (data == B)
			{
				ans = current;
			}
		}
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> A >> B;
	BTree* tree = new BTree;
	tree->init(A, 1);
	if (ans == 0)
		cout << -1;
	else
		cout << ans->pos;

	return 0;
}