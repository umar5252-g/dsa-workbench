#include <iostream>
using namespace std;
#include <vector>

class Node
{

public:
  int data;
  Node *right;
  Node *left;

  Node(int data)
  {
    this->data = data;
    right = left = NULL;
  }
};
static int idx = -1;

Node *binaryTree(vector<int> preOrder)
{
  idx++;
  if (preOrder[idx] == -1)
  {
    return NULL;
  }
  Node *root = new Node(preOrder[idx]);
  root->left = binaryTree(preOrder);
  root->right = binaryTree(preOrder);
  return root;
}
int main()
{
  vector<int> preOrder{1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
  Node *root = binaryTree(preOrder);
  cout << root->data << endl;
  cout << root->left->data << endl;
  cout << root->right->data << endl;
  return 0;
}