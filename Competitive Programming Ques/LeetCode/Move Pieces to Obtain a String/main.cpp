// Leetcode: Move Pieces to Obtain a String
// https://leetcode.com/problems/move-pieces-to-obtain-a-string

#include <iostream>

using namespace std;

class Solution
{
public:
  bool canChange(string start, string target)
  {
    int i = 0, j = 0; // Pointers for `start` and `target` strings

    // Traverse both strings
    while (i < start.size() && j < target.size())
    {
      // Skip '_' in `start`
      while (i < start.size() && start[i] == '_')
        i++;
      // Skip '_' in `target`
      while (j < target.size() && target[j] == '_')
        j++;

      // Check if both pointers are within bounds
      if (i < start.size() && j < target.size())
      {
        // If characters don't match, return false
        if (start[i] != target[j])
          return false;

        // 'L' can only move left (i >= j is invalid)
        if (start[i] == 'L' && i < j)
          return false;

        // 'R' can only move right (i <= j is invalid)
        if (start[i] == 'R' && i > j)
          return false;

        // Move to the next character
        i++;
        j++;
      }
    }

    // Check remaining characters in `start` and `target`
    // Ensure only '_' are left in both strings
    while (i < start.size() && start[i] == '_')
      i++;
    while (j < target.size() && target[j] == '_')
      j++;

    // Both pointers should reach the end
    return i >= start.size() && j >= target.size();
  }
};

int main()
{
  Solution sol;
  string start = "_L__R__R_";
  string target = "L______RR";
  cout << sol.canChange(start, target) << endl;

  return 0;
}