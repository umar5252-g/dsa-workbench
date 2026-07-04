#include <iostream>
using namespace std;

class CircularQueue
{
  int crrSize;
  int *arr;
  int capacity;
  int f, r;

public:
  CircularQueue(int capacity)
  {
    this->capacity = capacity;
    crrSize = 0;
    f = 0;
    r = -1;
    arr = new int[capacity];
  }

  void push(int val)
  {
    if (crrSize == capacity)
    {
      cout << "CQ is full" << endl;
      return;
    }
    r = (r + 1) % capacity;
    arr[r] = val;
    crrSize++;
  }

  void pop()
  {
    if (empty())
    {
      cout << "cq is empty" << endl;
      return;
    }
    f = (f + 1) % capacity;
    crrSize--;
  }
  int front()
  {
    if (empty())
    {
      cout << "cq is empty" << endl;
      return -1;
    }
    return arr[f];
  }

  bool empty()
  {
    return crrSize == 0;
  }

  void print()
  {
    if (empty())
    {
      cout << "cq is empty!" << endl;
      return;
    }
    for (int i = 0; i < crrSize; i++)
    {
      cout << arr[i] << " ";
    }
    cout << endl;
  }
};
int main()
{
  CircularQueue cq(3);
  cq.push(1);
  cq.push(2);
  cq.push(3);
  cq.pop();
  cq.push(4);
  while (!cq.empty())
  {
    cout << cq.front() << " ";
    cq.pop();
  }

  return 0;
}