// Leetcode: Find Smallest Letter Greater Than Target
// https://leetcode.com/problems/find-smallest-letter-greater-than-target

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
  char nextGreatestLetter(vector<char> &letters, char target)
  {
    auto itr = upper_bound(letters.begin(), letters.end(), target);
    return itr == letters.end() ? letters[0] : *itr;
  }
};

int main()
{
  Solution s;
  vector<char> chars = {'c', 'f', 'j'};

  cout << s.nextGreatestLetter(chars, 'a') << endl;

  return 0;
}