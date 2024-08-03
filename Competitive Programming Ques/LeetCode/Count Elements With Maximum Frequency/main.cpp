// Leetcode: Count Elements With Maximum Frequency
// https://leetcode.com/problems/count-elements-with-maximum-frequency

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int maxFrequencyElements(vector<int> &nums)
  {
    // Tracks the maximum frequency of any element
    int maxFrequency = 0;
    vector<int> elementFrequency(101, 0); // Frequency of each element
    vector<int> frequencyCount(101, 0);   // Sum of elements for each frequency

    // Iterate through each number in the array
    for (auto const &num : nums)
    {
      // Decrease the total frequency sum for the current frequency of the number
      frequencyCount[elementFrequency[num]] -= elementFrequency[num];

      // Increment the frequency of the current number
      elementFrequency[num]++;

      // Update the maximum frequency seen so far
      maxFrequency = max(maxFrequency, elementFrequency[num]);

      // Increase the total frequency sum for the new frequency of the number
      frequencyCount[elementFrequency[num]] += elementFrequency[num];
    }

    // Return the sum of elements that have the maximum frequency
    return frequencyCount[maxFrequency];
  }
};

int main()
{
  vector<int> nums = {1, 2, 2, 3, 1, 4};
  Solution s;
  cout << s.maxFrequencyElements(nums) << endl;
  return 0;
}