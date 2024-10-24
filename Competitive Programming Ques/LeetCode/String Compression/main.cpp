// Leetcode: String Compression
// https://leetcode.com/problems/string-compression

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int compress(vector<char> &chars)
  {
    int writeIndex = 0;
    int readIndex = 0;

    while (readIndex < chars.size())
    {
      char currentChar = chars[readIndex];
      int count = 0;

      // Count the occurrences of the current character
      while (readIndex < chars.size() && chars[readIndex] == currentChar)
      {
        count++;
        readIndex++;
      }

      // Write the character to the result
      chars[writeIndex++] = currentChar;

      // If count is more than 1, write its digits
      if (count > 1)
      {
        string countStr = to_string(count);
        for (char c : countStr)
        {
          chars[writeIndex++] = c;
        }
      }
    }

    // Return the new length after compression
    return writeIndex;
  }
};

int main()
{
  Solution sol;
  vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
  cout << sol.compress(chars) << endl;

  return 0;
}