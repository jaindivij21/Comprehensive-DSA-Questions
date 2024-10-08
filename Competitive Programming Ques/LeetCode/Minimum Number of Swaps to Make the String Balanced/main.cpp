// Leetcode: Minimum Number of Swaps to Make the String Balanced
// https://leetcode.com/problems/minimum-number-of-swaps-to-make-the-string-balanced

#include <iostream>

using namespace std;

class Solution
{
public:
  int minSwaps(string &s)
  {
    // Tracking opening and closing brackets
    int closingBrackets = 0, openingBrackets = 0;

    // Tracking the number of swaps
    int swaps = 0;

    // Iterate through the string
    for (char i : s)
    {
      // Increment openingBrackets for '[' and closingBrackets for ']'
      i == '[' ? openingBrackets++ : closingBrackets++;

      // If closingBrackets exceeds openingBrackets, it indicates an imbalance and we swap
      if (closingBrackets > openingBrackets)
      {
        swaps++;
        openingBrackets++;
        closingBrackets--;
      }
    }

    // Return the number of swaps required to balance the string
    return swaps;
  }
};

int main()
{
  Solution sol;
  string s = "][][";
  cout << sol.minSwaps(s) << endl;

  return 0;
}