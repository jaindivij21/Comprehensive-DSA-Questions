// Leetcode: Sum of Digits of String After Convert
// https://leetcode.com/problems/sum-of-digits-of-string-after-convert

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution
{
public:
  int getLucky(string &s, int k)
  {
    string converted = convertAlphaStringToIntString(s);

    int sum;
    while (k--)
    {
      sum = 0;
      sum = accumulate(converted.begin(), converted.end(), 0, [](int acc, char c)
                       { return acc + (c - '0'); });

      converted = to_string(sum);
    }

    return sum;
  }

private:
  string convertAlphaStringToIntString(string &s)
  {
    string result;
    for (auto c : s)
    {
      result += to_string(c - 'a' + 1);
    }

    return result;
  }
};

int main()
{
  Solution solution;
  string s = "zbax";
  int k = 2;
  cout << solution.getLucky(s, k) << endl;
  return 0;
}