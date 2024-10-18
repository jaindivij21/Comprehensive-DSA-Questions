// Leetcode: Longest Happy String
// https://leetcode.com/problems/longest-happy-string

#include <iostream>
#include <queue>

using namespace std;

class Solution
{
public:
  string longestDiverseString(int a, int b, int c)
  {
    // Priority queue to store characters based on their frequency in descending order.
    // Each element is a pair: (frequency, character).
    priority_queue<pair<int, char>> maxHeap;

    // Push initial frequencies of 'a', 'b', and 'c' to the max heap if they are greater than 0.
    if (a > 0)
      maxHeap.push({a, 'a'});
    if (b > 0)
      maxHeap.push({b, 'b'});
    if (c > 0)
      maxHeap.push({c, 'c'});

    string result;

    // Loop until the max heap is empty.
    while (!maxHeap.empty())
    {
      // Get the character with the highest remaining frequency.
      auto [maxFreq, maxChar] = maxHeap.top();
      maxHeap.pop();

      int len = result.size();

      // Check if the last two characters in the result are the same as `maxChar`
      // to prevent having three consecutive same characters.
      if (len >= 2 && result[len - 1] == maxChar && result[len - 2] == maxChar)
      {
        // If the max heap is empty, we cannot add any more characters.
        if (maxHeap.empty())
          break;

        // Otherwise, use the second most frequent character.
        auto [secondFreq, secondChar] = maxHeap.top();
        maxHeap.pop();

        // Add the second character to the result.
        result += secondChar;

        // Decrease its frequency and push it back to the heap if there are still more left.
        if (secondFreq - 1 > 0)
          maxHeap.push({secondFreq - 1, secondChar});

        // Push the most frequent character back to the heap as it was skipped.
        maxHeap.push({maxFreq, maxChar});
      }
      else
      {
        // If adding `maxChar` does not lead to three consecutive characters, add it.
        result += maxChar;

        // Decrease its frequency and push it back if there are still more left.
        if (maxFreq - 1 > 0)
          maxHeap.push({maxFreq - 1, maxChar});
      }
    }

    return result;
  }
};

int main()
{
  Solution s;
  cout << s.longestDiverseString(2, 2, 1) << endl;

  return 0;
}
