// Leetcode: Find Kth Bit in Nth Binary String
// https://leetcode.com/problems/find-kth-bit-in-nth-binary-string

#include <iostream>

using namespace std;

class Solution
{
public:
  // Method to find the k-th bit in the n-th generated binary string
  char findKthBit(int n, int k)
  {
    // Construct the n-th binary string
    string generatedString = generateNthBinaryString(n);

    // Return the k-th character (adjusting for 0-based index)
    return generatedString[k - 1];
  }

private:
  // Recursively generates the n-th binary string according to the problem's rules
  string generateNthBinaryString(int n)
  {
    // Base case: the first binary string is "0"
    if (n == 1)
    {
      return "0";
    }

    // Recursively generate the (n-1)th binary string
    string previousString = generateNthBinaryString(n - 1);

    // Invert and reverse the (n-1)th string to create the complement part
    string invertedReversedString = previousString;
    transform(
        invertedReversedString.begin(),
        invertedReversedString.end(),
        invertedReversedString.begin(),
        [](char bit)
        {
          // Invert the bit: '0' becomes '1' and '1' becomes '0'
          return (bit == '0') ? '1' : '0';
        });
    // Reverse the inverted string
    reverse(invertedReversedString.begin(), invertedReversedString.end());

    // Construct the nth string as: (n-1)th string + "1" + inverted and reversed (n-1)th string
    return previousString + "1" + invertedReversedString;
  }
};

int main()
{
  Solution s;
  cout << s.findKthBit(4, 11) << endl;

  return 0;
}
