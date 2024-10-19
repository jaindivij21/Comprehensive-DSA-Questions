// Leetcode: Greatest Common Divisor of Strings
// https://leetcode.com/problems/greatest-common-divisor-of-strings

#include <iostream>

using namespace std;

class Solution
{
public:
  // Function to find the largest string that can divide both str1 and str2
  string gcdOfStrings(const string &str1, const string &str2)
  {
    // Ensure str1 is the longer string or of equal length
    return str1.size() < str2.size() ? findGCD(str2, str1) : findGCD(str1, str2);
  }

private:
  // Helper function to recursively find the GCD of two strings
  string findGCD(const string &longer, const string &shorter)
  {
    // Base Case: If the shorter string is empty, the GCD is the longer string
    if (shorter.empty())
      return longer;

    // Attempt to calculate the remaining part of the longer string after removing prefixes of the shorter string
    string remainingLonger = calculateRemainingString(longer, shorter);

    // If no valid remainder is found, the shorter string is not a divisor of the longer string
    if (remainingLonger == longer)
      return "";

    // Recursively call the function with shorter and the remaining part
    return findGCD(shorter, remainingLonger);
  }

  // Function to calculate the remaining part of 'longer' after removing repeated occurrences of 'shorter'
  string calculateRemainingString(const string &longer, const string &shorter)
  {
    int index = 0;

    // Remove 'shorter' from the beginning of 'longer' as long as it matches
    while (longer.substr(index, shorter.size()) == shorter)
    {
      index += shorter.size();
    }

    // If we consumed the entire 'longer', return an empty string, otherwise return the remaining part
    return index == longer.size() ? "" : longer.substr(index);
  }
};

int main()
{
  Solution s;
  string str1 = "ABABABABA";
  string str2 = "ABAB";
  cout << s.gcdOfStrings(str1, str2) << endl;

  return 0;
}