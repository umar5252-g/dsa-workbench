#include <iostream>
using namespace std;

class Cq
{
  int crrSize;
  int *arr;
  int capacity;
  int f, r;

public:
  Cq(int capacity)
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
};
int main()
{

  return 0;
}