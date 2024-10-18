// Leetcode: 1-bit and 2-bit Characters
// https://leetcode.com/problems/1-bit-and-2-bit-characters

#include <iostream>

using namespace std;

class Solution
{
public:
  bool isOneBitCharacter(vector<int> &bits)
  {
    for (int i = 0; i < bits.size() - 1;)
    {
      if (bits[i] == 0)
        i++;
      else if (i + 1 <= bits.size() - 2 && bits[i] == 1)
        i += 2;
      else
        return false;
    }

    return true;
  }
};

int main()
{
  Solution sol;
  vector<int> bits = {1, 0, 0};
  cout << sol.isOneBitCharacter(bits) << endl;

  return 0;
}
