// Leetcode: Decode String
// https://leetcode.com/problems/decode-string

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  string decodeString(const string &s)
  {
    stack<char> charStack; // Stack to process the encoded string

    for (char ch : s)
    {
      if (ch == ']')
      {
        // Step 1: Extract the string inside the brackets
        string decodedSegment;
        while (charStack.top() != '[')
        {
          decodedSegment += charStack.top();
          charStack.pop();
        }
        charStack.pop(); // Remove the '['

        reverse(decodedSegment.begin(), decodedSegment.end()); // Reverse to restore original order

        // Step 2: Extract the repeat count
        int repeatCount = 0;
        int multiplier = 1;
        while (!charStack.empty() && isdigit(charStack.top()))
        {
          repeatCount += (charStack.top() - '0') * multiplier;
          multiplier *= 10;
          charStack.pop();
        }

        // Step 3: Push the decoded segment back onto the stack repeatCount times
        while (repeatCount--)
        {
          for (char segmentChar : decodedSegment)
          {
            charStack.push(segmentChar);
          }
        }
      }
      else
      {
        // Push characters onto the stack until ']' is encountered
        charStack.push(ch);
      }
    }

    // Build the final decoded string from the stack
    string result;
    while (!charStack.empty())
    {
      result += charStack.top();
      charStack.pop();
    }

    reverse(result.begin(), result.end()); // Reverse to restore original order

    return result;
  }
};

int main()
{
  Solution sol;
  string str = "3[a]2[bc]";

  cout << sol.decodeString(str) << endl;

  return 0;
}