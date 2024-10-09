// Leetcode: Minimum Add to Make Parentheses Valid
// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid

#include <iostream>
#include <stack>

using namespace std;

class Solution
{
public:
  int minAddToMakeValid(string &s)
  {
    // Stack to track unmatched opening parentheses '('
    stack<char> openParenStack;

    // Counter for unmatched closing parentheses ')'
    int unbalancedCloseCount = 0;

    // Iterate through each character in the string
    for (char c : s)
    {
      if (c == '(')
      {
        // Push an opening parenthesis '(' onto the stack
        openParenStack.push(c);
      }
      else if (!openParenStack.empty())
      {
        // Pop from stack if there's a matching '(' for the current ')'
        openParenStack.pop();
      }
      else
      {
        // If stack is empty, it's an unbalanced ')'
        unbalancedCloseCount++;
      }
    }

    // The total number of moves to balance the string:
    // - unbalancedCloseCount counts unmatched ')'
    // - openParenStack.size() counts unmatched '('
    return unbalancedCloseCount + openParenStack.size();
  }
};

int main()
{
  Solution sol;
  string s = "())";
  cout << sol.minAddToMakeValid(s) << endl;

  return 0;
}