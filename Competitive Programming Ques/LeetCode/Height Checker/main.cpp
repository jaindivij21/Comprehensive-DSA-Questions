// Leetcode: Height Checker
// https://leetcode.com/problems/height-checker

#include <iostream>
#include <vector>

using namespace std;

int heightChecker(vector<int> &heights)
{
  // Initialize a vector to store the count of each height
  vector<int> heightCounts(101, 0);

  // Count the occurrences of each height
  for (int i = 0; i < heights.size(); i++)
  {
    heightCounts[heights[i]]++;
  }

  // Count the number of out-of-order elements
  int outOfOrderCount = 0; // Counter for out-of-order elements
  int heightIndex = 0;     // Pointer to iterate through heights array
  for (int height = 0; height < heightCounts.size(); height++)
  {
    if (heightCounts[height] == 0)
    {
      continue; // Skip if count is zero
    }
    else
    {
      // Iterate through occurrences of current height
      while (heightCounts[height] != 0)
      {
        // If the current height doesn't match, increment count
        if (height != heights[heightIndex])
        {
          outOfOrderCount++;
        }
        // Move to the next element in heights array
        heightIndex++;
        // Decrease the count of current height
        heightCounts[height]--;
      }
    }
  }

  // Return the count of out-of-order elements
  return outOfOrderCount;
}

int main()
{
  vector<int> heights = {1, 1, 4, 2, 3, 1};
  cout << heightChecker(heights) << endl;

  return 0;
}