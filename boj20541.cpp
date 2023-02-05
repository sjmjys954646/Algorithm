#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rep1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define range(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int INF = 9876543210;

struct node
{
	node* par;
	string cur;
	map<string, node*> folder;
	set<string> file;
};

int N;
node* root;
node* curPos;

void Debugger(node* root)
{
	cout << "DEBUG-----------\n";
	cout << root->cur << "\n";
	cout << "files-----------\n";
	for (auto it = root->file.begin(); it != root->file.end(); it++)
	{
		cout << *it << "\n";
	}
	for (auto it = root->folder.begin(); it != root->folder.end(); it++)
	{
		Debugger(it->second);
	}
}

pair<int, int> remover(node* node)
{
	int album = 1;
	int photo = node->file.size();

	for (auto it = node->folder.begin(); it != node->folder.end(); it++)
	{
		auto tmp = remover(it->second);
		album += tmp.first;
		photo += tmp.second;
	}

	return { album, photo };
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	cin >> N;

	string order;

	node* newNode = new node();
	newNode->cur = "album";
	root = newNode;
	curPos = root;

	while (N--)
	{
		getline(cin, order);

		string first, second;
		cin >> first;

		if (first == "mkalb")
		{
			cin >> second;
			if (curPos->folder.find(second) != curPos->folder.end())
			{
				cout << "duplicated album name\n";
			}
			else
			{
				node* newNode = new node();
				newNode->par = curPos;
				newNode->cur = second;
				curPos->folder[second] = newNode;
			}
		}
		else if (first == "rmalb")
		{
			cin >> second;
			pair<int, int> pp;
			if (second == "-1")
			{
				if (curPos->folder.size() > 0)
				{
					auto it = curPos->folder.begin();
					pp = remover(it->second);
					cout << pp.first << " " << pp.second << "\n";
					curPos->folder.erase(it);
				}
				else
				{
					cout << 0 << " " << 0 << "\n";
				}
			}
			else if (second == "0")
			{
				if (curPos->folder.size() > 0)
				{
					int album = 0;
					int photo = 0;
					for (auto it = curPos->folder.begin(); it != curPos->folder.end(); it++)
					{
						pp = remover(it->second);
						album += pp.first;
						photo += pp.second;
					}
					cout << album << " " << photo << "\n";
					curPos->folder.clear();
				}
				else
				{
					cout << 0 << " " << 0 << "\n";
				}
			}
			else if (second == "1")
			{
				if (curPos->folder.size() > 0)
				{
					auto it = curPos->folder.end();
					it--;
					pp = remover(it->second);
					cout << pp.first << " " << pp.second << "\n";
					curPos->folder.erase(it);
				}
				else
				{
					cout << 0 << " " << 0 << "\n";
				}
			}
			else
			{
				if (curPos->folder.find(second) != curPos->folder.end())
				{
					auto it = curPos->folder.find(second);
					pp = remover(it->second);
					cout << pp.first << " " << pp.second << "\n";
					curPos->folder.erase(it);
				}
				else
				{
					cout << 0 << " " << 0 << "\n";
				}
			}
		}
		else if (first == "insert")
		{
			cin >> second;
			if (curPos->file.find(second) != curPos->file.end())
			{
				cout << "duplicated photo name\n";
			}
			else
			{
				curPos->file.insert(second);
			}
		}
		else if (first == "delete")
		{
			cin >> second;
			int del = 0;
			if (second == "-1")
			{
				if (curPos->file.size() > 0)
				{
					auto it = curPos->file.begin();
					curPos->file.erase(it);
					del++;
				}
			}
			else if (second == "0")
			{
				if (curPos->file.size() > 0)
				{
					auto it = curPos->file.begin();
					for (auto it = curPos->file.begin(); it != curPos->file.end(); it++) {
						del++;
					}
					curPos->file.clear();
				}
			}
			else if (second == "1")
			{
				if (curPos->file.size() > 0)
				{
					auto it = curPos->file.end();
					it--;
					curPos->file.erase(it);
					del++;
				}
			}
			else
			{
				if (curPos->file.find(second) != curPos->file.end())
				{
					auto it = curPos->file.find(second);
					curPos->file.erase(it);
					del++;
				}
			}
			cout << del << "\n";
		}
		else if (first == "ca")
		{
			cin >> second;
			if (second == "..")
			{
				if (curPos->cur != "album")
				{
					curPos = curPos->par;
				}
			}
			else if (second == "/")
			{
				curPos = root;
			}
			else
			{
				if (curPos->folder.find(second) != curPos->folder.end())
				{
					auto it = curPos->folder.find(second);
					curPos = it->second;
				}
			}
			cout << curPos->cur << "\n";
		}
	}

	return 0;
}