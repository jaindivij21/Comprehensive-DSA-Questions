// Leetcode: Fruit Into Baskets
// https://leetcode.com/problems/fruit-into-baskets

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  // Sliding Window: Find the length of max subarray with 2 unique numbers
  int totalFruit(vector<int> &fruits) {
    int ans = 0;
    unordered_map<int, int> uniques;

    int left = 0, right = 0;
    while (right < fruits.size()) {
      uniques[fruits[right]]++;
      while (uniques.size() > 2) {
        uniques[fruits[left]]--;
        if (uniques[fruits[left]] <= 0) {
          uniques.erase(fruits[left]);
        }
        left++;
      }

      ans = max(ans, right - left + 1);
      right++;
    }

    return ans;
  }
};

int main() {
  Solution s;
  vector<int> arr = {0,1,2,2};

  cout << s.totalFruit(arr) << endl;

  return 0;
}