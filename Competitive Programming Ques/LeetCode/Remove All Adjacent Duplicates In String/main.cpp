// Leetcode: Remove All Adjacent Duplicates In String
// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string

#include <iostream>
#include <stack>

using namespace std;

class Solution
{
public:
  std::string removeDuplicates(std::string &str)
  {
    // Return the string as is if it is empty or has only one character
    if (str.size() <= 1)
    {
      return str;
    }

    // Stack to keep track of characters
    std::stack<char> charStack;
    charStack.push(str[0]);

    // Iterate through the string starting from the second character
    for (int i = 1; i < str.size(); i++)
    {
      // If the stack is not empty and the top element is the same as the current character
      if (!charStack.empty() && charStack.top() == str[i])
      {
        charStack.pop(); // Remove the top element as it is a duplicate
      }
      else
      {
        charStack.push(str[i]); // Push the current character onto the stack
      }
    }

    // Construct the result string from the stack
    std::string result = "";
    while (!charStack.empty())
    {
      result += charStack.top();
      charStack.pop();
    }

    // Reverse the result string as the characters were added in reverse order
    std::reverse(result.begin(), result.end());
    return result;
  }
};

int main()
{
  string str = "abbaca";
  Solution s;
  cout << s.removeDuplicates(str) << endl;
  return 0;
}