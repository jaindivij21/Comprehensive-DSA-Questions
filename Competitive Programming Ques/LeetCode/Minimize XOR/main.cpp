// Leetcode: Minimize XOR
// https://leetcode.com/problems/minimize-xor

#include <iostream>

using namespace std;

class Solution
{
public:
  int minimizeXor(int num1, int num2)
  {
    // Calculate the number of set bits (1s) in num1 and num2
    int num1SetBits = countSetBits(num1);
    int num2SetBits = countSetBits(num2);

    if (num1SetBits == num2SetBits)
    {
      // If the number of set bits is already equal, return num1 as it is
      return num1;
    }
    else if (num1SetBits > num2SetBits)
    {
      // Reduce the number of set bits in num1 to match num2
      int bitsToRemove = num1SetBits - num2SetBits;
      for (int i = 0; i < 32 && bitsToRemove > 0; i++)
      {
        // Check if the ith bit is set
        if ((num1 & (1 << i)) != 0)
        {
          // Unset the ith bit
          num1 &= ~(1 << i);
          bitsToRemove--;
        }
      }
      return num1;
    }
    else
    {
      // Increase the number of set bits in num1 to match num2
      int bitsToAdd = num2SetBits - num1SetBits;
      for (int i = 0; i < 32 && bitsToAdd > 0; i++)
      {
        // Check if the ith bit is unset
        if ((num1 & (1 << i)) == 0)
        {
          // Set the ith bit
          num1 |= (1 << i);
          bitsToAdd--;
        }
      }
      return num1;
    }
  }

private:
  // Helper function to count the number of set bits (1s) in a number
  int countSetBits(int num)
  {
    int count = 0;
    while (num > 0)
    {
      count += (num & 1);
      num >>= 1;
    }
    return count;
  }
};

int main()
{
  Solution s;

  cout << s.minimizeXor(1, 12) << endl;

  return 0;
}