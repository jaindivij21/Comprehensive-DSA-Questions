// Leetcode: Make Two Arrays Equal by Reversing Subarrays
// https://leetcode.com/problems/make-two-arrays-equal-by-reversing-subarrays

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  bool canBeEqual(vector<int> &target, vector<int> &arr)
  {
    // Check if the sizes of both arrays are different
    if (target.size() != arr.size())
      return false;

    // Create a hash map to count the frequency of elements in the target array
    unordered_map<int, int> targetCounts;
    for (auto num : target)
      targetCounts[num]++;

    // Traverse the arr array and decrease the frequency in the hash map
    for (auto num : arr)
    {
      if (targetCounts.find(num) != targetCounts.end())
      {
        targetCounts[num]--;
        // If the frequency becomes zero, remove the element from the map
        if (targetCounts[num] == 0)
        {
          targetCounts.erase(num);
        }
      }
      else
      {
        // If the element is not found in the map, arrays cannot be made equal
        return false;
      }
    }

    // Check if the map is empty, meaning all elements matched
    return targetCounts.empty();
  }
};

int main()
{
  vector<int> target = {1, 2, 3, 4};
  vector<int> arr = {2, 4, 1, 3};
  Solution s;
  cout << s.canBeEqual(target, arr) << endl;
  return 0;
}