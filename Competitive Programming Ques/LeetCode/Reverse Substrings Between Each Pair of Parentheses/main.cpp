// Leetcode: Reverse Substrings Between Each Pair of Parentheses
// https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses

#include <iostream>
#include <string>
#include <stack>

using namespace std;

string reverseParentheses(const string &s)
{
  stack<char> characters; // Stack to store characters

  for (char ch : s)
  {
    if (ch != ')')
    {
      // Push non ')' characters onto the stack
      characters.push(ch);
    }
    else
    {
      // If encounter ')', start reversing characters until '('
      string temp;
      while (!characters.empty() && characters.top() != '(')
      {
        temp += characters.top();
        characters.pop();
      }
      characters.pop(); // Pop the '(' from the stack

      // Push the reversed substring back onto the stack
      for (char reversedCh : temp)
      {
        characters.push(reversedCh);
      }
    }
  }

  // Construct the final string from the stack
  string ans;
  while (!characters.empty())
  {
    ans += characters.top();
    characters.pop();
  }

  reverse(ans.begin(), ans.end()); // Reverse the final string
  return ans;
}

int main()
{
  string s;
  cin >> s;
  cout << reverseParentheses(s) << endl;

  return 0;
}
