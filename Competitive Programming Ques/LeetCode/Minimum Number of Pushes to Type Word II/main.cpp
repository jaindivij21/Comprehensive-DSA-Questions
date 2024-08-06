// Leetcode: Minimum Number of Pushes to Type Word II
// https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii

#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

// Custom comparator for priority queue to sort by frequency in descending order
class FrequencyComparator
{
public:
  bool operator()(const pair<char, int> &a, const pair<char, int> &b)
  {
    return a.second < b.second;
  }
};

class Solution
{
public:
  int minimumPushes(const string &word)
  {
    // Step 1: Calculate frequency of each character in the given word
    unordered_map<char, int> charFrequency;
    for (auto c : word)
    {
      charFrequency[c]++;
    }

    // Step 2: Use a max-heap (priority queue) to store characters based on frequency
    priority_queue<pair<char, int>, vector<pair<char, int>>, FrequencyComparator> maxHeap;
    for (const auto &item : charFrequency)
    {
      maxHeap.emplace(item.first, item.second);
    }

    // Step 3: Calculate the minimum number of key presses needed
    int totalPresses = 0;
    int pressesPerKey = 1;
    int keysProcessed = 0;

    while (!maxHeap.empty())
    {
      int frequency = maxHeap.top().second;
      maxHeap.pop();
      keysProcessed++;

      totalPresses += pressesPerKey * frequency;

      // If 8 keys have been processed, increment the pressesPerKey for the next set
      if (keysProcessed >= 8)
      {
        keysProcessed = 0;
        pressesPerKey++;
      }
    }

    return totalPresses;
  }
};

int main()
{
  string word = "xyzxyzxyzxyz";

  Solution s;
  cout << s.minimumPushes(word) << endl;

  return 0;
}