// Leetcode: Sort the People
// https://leetcode.com/problems/sort-the-people

#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  vector<string> sortPeople(vector<string> &names, vector<int> &heights)
  {
    // Create a map to store height as the key and name as the value
    unordered_map<int, string> heightMap;

    // Populate the map with heights and corresponding names
    for (int i = 0; i < names.size(); i++)
    {
      heightMap[heights[i]] = names[i];
    }

    // Sort the heights array in descending order
    sort(heights.rbegin(), heights.rend());

    // Rearrange the names array according to the sorted heights
    for (int i = 0; i < heights.size(); i++)
    {
      names[i] = heightMap[heights[i]];
    }

    return names;
  }
};

int main()
{
  vector<string> names = {"Alice", "Bob", "Bob"};
  vector<int> heights = {155, 185, 150};

  Solution s;
  vector<string> ans = s.sortPeople(names, heights);

  return 0;
}
