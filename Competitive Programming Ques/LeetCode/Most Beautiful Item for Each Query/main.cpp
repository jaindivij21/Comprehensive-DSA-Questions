// Leetcode: Most Beautiful Item for Each Query
// https://leetcode.com/problems/most-beautiful-item-for-each-query

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  vector<int> maximumBeauty(vector<vector<int>> &items, vector<int> &queries)
  {
    sort(items.begin(), items.end(), [](vector<int> a, vector<int> b)
         {
            if (a[0] == b[0]) {
                return a[1] < b[1];
            } else {
                return a[0] < b[0];
            } });

    vector<int> maxBeauties(items.size(), 0);
    maxBeauties[0] = items[0][1];
    for (int i = 1; i < items.size(); i++)
    {
      maxBeauties[i] = max(maxBeauties[i - 1], items[i][1]);
    }

    vector<int> result(queries.size(), 0);

    for (int i = 0; i < queries.size(); i++)
    {
      int idx = binarySearch(items, queries[i]);

      if (idx == -1)
      {
        continue;
      }
      else
      {
        result[i] = maxBeauties[idx];
      }
    }

    return result;
  }

private:
  int binarySearch(vector<vector<int>> &items, int queryPrice)
  {
    int l = 0;
    int r = items.size() - 1;

    int idx = -1;
    while (l <= r)
    {
      int mid = l + (r - l) / 2;

      if (items[mid][0] > queryPrice)
      {
        r = mid - 1;
      }
      else
      {
        idx = mid;
        l = mid + 1;
      }
    }

    return idx;
  }
};

int main()
{
  Solution sol;
  vector<vector<int>> items = {{1, 2},
                               {3, 2},
                               {2, 4},
                               {5, 6},
                               {3, 5}};
  vector<int> queries = {1, 2, 3, 4, 5, 6};

  vector<int> result = sol.maximumBeauty(items, queries);

  return 0;
}