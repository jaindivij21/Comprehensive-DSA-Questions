// Leetcode: Clear Digits
// https://leetcode.com/problems/clear-digits

#include <iostream>
#include <stack>

using namespace std;

class Solution
{
public:
  string clearDigits(string s)
  {
    if (s.empty())
      return s;

    stack<char> st;
    for (char i : s)
    {
      if (isdigit(i) && !st.empty())
      {
        st.pop();
      }
      else
      {
        st.push(i);
      }
    }

    string res;
    while (!st.empty())
    {
      res = st.top() + res;
      st.pop();
    }

    return res;
  }
};

int main()
{
  Solution s;
  string str = "abc";

  cout << s.clearDigits(str) << endl;

  return 0;
}