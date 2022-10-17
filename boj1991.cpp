#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

class TreeNode
{
public:
  char data;
  TreeNode *left;
  TreeNode *right;
  TreeNode(){data = NULL;left = nullptr;right = nullptr;}
  TreeNode(char data)
  {
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
  }
  void setL(TreeNode * node)
  {
    left = node;
  }
  void setR(TreeNode * node)
  {
    right = node;
  }
};

void traverse1(TreeNode * node)
{
  if(node!=nullptr)
  {
    cout<<node->data;
    traverse1(node->left);
    traverse1(node->right);
  }
}

void traverse2(TreeNode * node)
{
   if(node!=nullptr)
  {
    traverse2(node->left);
    cout<<node->data;
    traverse2(node->right);
  }
}

void traverse3(TreeNode * node)
{
   if(node!=nullptr)
  {
    traverse3(node->left);
    traverse3(node->right);  
    cout<<node->data;
  }
}

int main() 
{
  int N;

  cin>>N;

  TreeNode* Tree = new TreeNode[N];

  for(int i = 0;i<N;i++)
  {
    char data, left, right;
    cin>>data>>left>>right;
    int idx = data - 'A';
    int Lidx = left - 'A';
    int Ridx = right - 'A';

    Tree[idx] = TreeNode(data);
    if(left != '.')
    {
      Tree[idx].setL(&Tree[Lidx]);
    }
    else
    {
      Tree[idx].setL(nullptr);
    }
    if(right != '.')
    {
      Tree[idx].setR(&Tree[Ridx]);
    }
    else
    {
      Tree[idx].setR(nullptr);
    }
  }

  traverse1(&Tree[0]);
  cout<<"\n";
  traverse2(&Tree[0]);
  cout<<"\n";
  traverse3(&Tree[0]);

	return 0;
}