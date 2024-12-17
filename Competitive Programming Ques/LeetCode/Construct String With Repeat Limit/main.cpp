// Leetcode: Construct String With Repeat Limit
// https://leetcode.com/problems/construct-string-with-repeat-limit/

#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  string repeatLimitedString(string &s, int repeatLimit)
  {
    unordered_map<char, int> charCount;
    priority_queue<pair<char, int>> maxHeap;
    for (auto i : s)
    {
      charCount[i]++;
    }

    for (auto i : charCount)
    {
      maxHeap.push({i.first, i.second});
    }

    string result;
    char lastChar = '\0';
    int lastCharCount = 0;

    while (!maxHeap.empty())
    {
      auto [c1, count1] = maxHeap.top();
      maxHeap.pop();

      if (c1 == lastChar && lastCharCount == repeatLimit)
      {
        if (maxHeap.empty())
        {
          break;
        }

        auto [c2, count2] = maxHeap.top();
        maxHeap.pop();

        result += c2;
        count2--;

        if (count2 > 0)
        {
          maxHeap.push({c2, count2});
        }

        maxHeap.push({c1, count1});

        lastChar = c2;
        lastCharCount = 1;
      }
      else
      {
        result += c1;
        count1--;

        if (c1 == lastChar)
        {
          lastCharCount++;
        }
        else
        {
          lastChar = c1;
          lastCharCount = 1;
        }

        if (count1 > 0)
        {
          maxHeap.push({c1, count1});
        }
      }
    }

    return result;
  }
};

int main()
{
  Solution sol;
  string s = "aababab";
  int repeatLimit = 2;

  cout << sol.repeatLimitedString(s, repeatLimit) << endl;

  return 0;
}