// Leetcode: Number of Senior Citizens
// https://leetcode.com/problems/number-of-senior-citizens

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int countSeniors(vector<string> &details)
  {
    int count = 0;
    for (const auto &detail : details)
    {
      int age = stoi(detail.substr(11, 2));

      if (age > 60)
        count++;
    }

    return count;
  }
};

int main()
{
  vector<string> details = {"7868190130M7522", "5303914400F9211", "9273338290F4010"};

  Solution s;
  cout << s.countSeniors(details) << endl;
  return 0;
}