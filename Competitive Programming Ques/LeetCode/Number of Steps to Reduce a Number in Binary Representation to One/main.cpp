// Number of Steps to Reduce a Number in Binary Representation to One
// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one

#include <iostream>

using namespace std;

void addOneToString(string &s)
{
  char carry = '1';

  for (int i = s.size() - 1; i >= 0; i--)
  {
    if (s[i] == '0')
    {
      s[i] = carry;
      carry = '0';
    }
    else
    {
      s[i] = carry == '0' ? s[i] : '0';
      carry = carry == '0' ? '0' : '1';
    }
  }

  s = carry == '1' ? '1' + s : s;
}

int numSteps(string s)
{
  int count = 0;

  while (s.size() > 1)
  {
    count++;

    int lastIdx = s.size() - 1;
    if (s[lastIdx] == '1')
    {
      // Odd Number
      addOneToString(s);
    }
    else
    {
      // Even Number
      s.pop_back();
    }
  }

  return count;
}

int main()
{
  string s;
  cin >> s;

  cout << numSteps(s) << endl;
}
