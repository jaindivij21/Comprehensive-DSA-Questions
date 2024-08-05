// Leetcode: Kth Distinct String in an Array
// https://leetcode.com/problems/kth-distinct-string-in-an-array

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
public:
  string kthDistinct(vector<string> &arr, int k)
  {
    unordered_map<string, bool> isDuplicate;

    // First pass: identify duplicates
    for (const auto &str : arr)
    {
      if (isDuplicate.find(str) == isDuplicate.end())
      {
        isDuplicate[str] = false; // Mark as seen first time
      }
      else
      {
        isDuplicate[str] = true; // Mark as duplicate
      }
    }

    // Second pass: find the k-th distinct string
    for (const auto &str : arr)
    {
      if (!isDuplicate[str])
      { // If the string is not a duplicate
        if (k == 1)
        {
          return str; // Return the k-th distinct string
        }
        k--;
      }
    }

    return ""; // If k-th distinct string does not exist
  }
};

int main()
{
  vector<string> arr = {"d", "b", "c", "b", "c", "a"};
  int k = 2;

  Solution s;
  cout << s.kthDistinct(arr, k) << endl;

  return 0;
}