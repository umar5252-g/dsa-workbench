#include <iostream>
using namespace std;
#include <vector>
#include <stack>

int getCelebrity(vector<vector<int>> arr)
{
  stack<int> s;
  int n = arr.size();
  for (int i = 0; i < n - 1; i++)
  {
    s.push(i);
  }
  while (s.size() > 1)
  {
    int i = s.top();
    s.pop();
    int j = s.top();
    s.pop();

    if (arr[i][j] == 0)
    {
      s.push(i);
    }
    else
    {
      s.push(j);
    }
  }
  int celeb = s.top();
  for (int i = 0; i < n; i++)
  {
    if ((celeb != i) && (arr[i][celeb] == 0 || arr[celeb][i] == 1))
    {
      return -1;
    }
  }
  return celeb;
}
int main()
{

  return 0;
}