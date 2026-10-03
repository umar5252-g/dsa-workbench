#include <iostream>
using namespace std;
#include <vector>
#include <queue>

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

void preOrder(Node *root)
{
  if (root == NULL)
  {
    return;
  }

  cout << root->data << " ";
  preOrder(root->left);
  preOrder(root->right);
}

void inOrder(Node *root)
{
  if (root == NULL)
  {
    return;
  }

  inOrder(root->left);
  cout << root->data << " ";
  inOrder(root->right);
}

void postOrder(Node *root)
{
  if (root == NULL)
  {
    return;
  }

  postOrder(root->left);
  postOrder(root->right);
  cout << root->data << " ";
}

void levelOrder(Node *root)
{
  queue<Node *> q;
  q.push(root);

  while (q.size() > 0)
  {
    Node *curr = q.front();
    q.pop();
    cout << curr->data << " ";

    if (curr->left != NULL)
      q.push(curr->left);
    if (curr->right != NULL)
      q.push(curr->right);
  }
}

void kthLevel(Node *root, int k)
{
  if (root == NULL)
  {
    return;
  }

  if (k == 1)
  {
    cout << root->data << " ";
    return;
  }
  kthLevel(root->left, k - 1);
  kthLevel(root->right, k - 1);
}

int sumTree(Node *root)
{
  if (root == NULL)
    return 0;

  int leftSum = sumTree(root->left);
  int rightSum = sumTree(root->right);

  root->data += leftSum + rightSum;

  return root->data;
}
int main()
{
  vector<int> preOrderSeq{1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
  Node *root = binaryTree(preOrderSeq);

  cout << "Before conversion: ";
  preOrder(root);

  sumTree(root);

  cout << endl;
  cout << "after conversion: ";
  preOrder(root);

  // inOrder(root);
  // postOrder(root);
  // kthLevel(root, 3);
  cout << endl;
  return 0;
}