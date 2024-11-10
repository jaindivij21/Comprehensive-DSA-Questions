// Leetcode: Removing Stars From a String
// https://leetcode.com/problems/removing-stars-from-a-string

#include <iostream>
#include <stack>

using namespace std;

class Solution
{
public:
  string removeStars(string &str)
  {
    stack<char> s;

    for (auto i : str)
    {
      if (i == '*')
      {
        s.pop();
      }
      else
      {
        s.push(i);
      }
    }

    string ans;
    while (!s.empty())
    {
      ans += s.top();
      s.pop();
    }

    reverse(ans.begin(), ans.end());

    return ans;
  }
};

int main()
{
  Solution s;
  string str = "ab**cd**ef**gh";
  cout << s.removeStars(str) << endl;

  return 0;
}