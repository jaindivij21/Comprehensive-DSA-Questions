// Leetcode: Neighboring Bitwise XOR
// https://leetcode.com/problems/neighboring-bitwise-xor

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  // Simulation approach to validate the array
  bool doesValidArrayExist(vector<int> &derived)
  {
    int currBit = 1; // Initial first bit is always 1

    for (int i = 0; i < derived.size() - 1; ++i)
    {
      // Flip the current bit if the derived value is 1
      if (derived[i] == 1)
      {
        currBit = 1 - currBit;
      }
    }

    // Check the validity of the last number based on the current bit
    return (derived.back() != currBit);
  }
};

int main()
{
  Solution s;
  vector<int> derived = {1, 1, 0};

  cout << s.doesValidArrayExist(derived) << endl;

  return 0;
}