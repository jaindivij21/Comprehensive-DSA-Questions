// Leetcode: Minimum String Length After Removing Substrings
// https://leetcode.com/problems/minimum-string-length-after-removing-substrings

#include <iostream>
#include <stack>

using namespace std;

class Solution
{
public:
  int minLength(string &s)
  {
    stack<char> chars;
    for (auto i : s)
    {
      if (!chars.empty() && ((i == 'B' && chars.top() == 'A') || (i == 'D' && chars.top() == 'C')))
      {
        chars.pop();
      }
      else
      {
        chars.push(i);
      }
    }

    return chars.size();
  }
};

int main()
{
  Solution sol;
  string s = "ABFCACDB";
  cout << sol.minLength(s) << endl;

  return 0;
}