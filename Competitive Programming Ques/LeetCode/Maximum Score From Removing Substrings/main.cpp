// Leetcode: Maximum Score From Removing Substrings
// https://leetcode.com/problems/maximum-score-from-removing-substrings

#include <iostream>
#include <string>
#include <stack>

using namespace std;

string removeSubstrings(string s, const string &x, const int &points, int &ans)
{
  stack<char> st;
  st.push(s[0]);
  for (int i = 1; i < s.size(); i++)
  {
    if (s[i] == x[1] && !st.empty() && st.top() == x[0])
    {
      ans += points;
      st.pop();
    }
    else
    {
      st.push(s[i]);
    }
  }

  string newString;
  while (!st.empty())
  {
    newString += st.top();
    st.pop();
  }

  reverse(newString.begin(), newString.end());

  return newString;
}

int maximumGain(string s, int x, int y)
{
  int ans = 0;

  if (x > y)
  {
    s = removeSubstrings(s, "ab", x, ans);
    s = removeSubstrings(s, "ba", y, ans);
  }
  else
  {
    s = removeSubstrings(s, "ba", y, ans);
    s = removeSubstrings(s, "ab", x, ans);
  }

  return ans;
}

int main()
{
  string s;
  int x, y;

  cin >> s >> x >> y;
  cout << maximumGain(s, x, y) << endl;

  return 0;
}
