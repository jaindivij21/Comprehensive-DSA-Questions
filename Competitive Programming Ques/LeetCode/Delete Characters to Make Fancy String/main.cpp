// Leetcode: Delete Characters to Make Fancy String
// https://leetcode.com/problems/delete-characters-to-make-fancy-string

#include <iostream>

using namespace std;

class Solution
{
public:
  // Function to create a "fancy" string by ensuring that no character
  // appears consecutively more than twice.
  string makeFancyString(string inputString)
  {
    // If the input string has less than 3 characters, return it as is.
    if (inputString.size() < 3)
      return inputString;

    // Initialize the result string with the first two characters.
    string resultString;
    resultString += inputString[0];
    resultString += inputString[1];

    // Iterate through the input string starting from the third character.
    for (int index = 2; index < inputString.size(); index++)
    {
      // Check if the current character is the same as the previous two characters.
      if (inputString[index] == inputString[index - 1] && inputString[index] == inputString[index - 2])
      {
        // If so, skip adding this character to the result string.
        continue;
      }

      // Otherwise, append the current character to the result string.
      resultString += inputString[index];
    }

    // Return the resulting "fancy" string.
    return resultString;
  }
};

int main()
{
  Solution sol;
  string s = "leeetcode";
  cout << sol.makeFancyString(s) << endl;

  return 0;
}