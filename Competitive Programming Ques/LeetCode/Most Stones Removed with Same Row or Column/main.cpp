// Leetcode: Most Stones Removed with Same Row or Column
// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class UnionFind
{
private:
  unordered_map<int, int> parent;
  int count; // Number of connected components

public:
  // Constructor
  explicit UnionFind(int n) : count(n)
  {
    for (int i = 0; i < n; ++i)
    {
      parent[i] = -1; // Each node is its own root with size 1 (-1)
    }
  }

  // Find the root of a node with path compression
  int find(int x)
  {
    if (parent[x] < 0)
    {
      return x; // x is the root
    }
    // Path compression
    parent[x] = find(parent[x]);
    return parent[x];
  }

  // Union two sets by size
  void merge(int x, int y)
  {
    int root1 = find(x);
    int root2 = find(y);

    if (root1 != root2)
    {
      // Union by size: attach the smaller tree to the larger tree
      if (parent[root1] <= parent[root2])
      {
        // root1 has larger or equal size (more negative), so root2 joins root1
        parent[root1] += parent[root2]; // Increase size of root1's tree
        parent[root2] = root1;          // Make root2 point to root1
      }
      else
      {
        // root2 has larger size, so root1 joins root2
        parent[root2] += parent[root1]; // Increase size of root2's tree
        parent[root1] = root2;          // Make root1 point to root2
      }
      count--; // One less connected component after merging
    }
  }

  // Get the current number of connected components
  int getCount() const
  {
    return count;
  }
};

class Solution
{
public:
  int removeStones(vector<vector<int>> &stones)
  {
    int n = stones.size();
    UnionFind uf(n);

    // We use a nested loop to find pairs of stones that share the same row or column
    for (int i = 0; i < n; ++i)
    {
      for (int j = i + 1; j < n; ++j)
      {
        if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
        {
          // Merge stones in the same row or column
          uf.merge(i, j);
        }
      }
    }

    // The maximum number of stones that can be removed is:
    // Total number of stones - number of connected components
    return n - uf.getCount();
  }
};

int main()
{
  vector<vector<int>> stones = {{0, 0},
                                {0, 1},
                                {1, 0},
                                {1, 2},
                                {2, 1},
                                {2, 2}};
  Solution solution;
  cout << solution.removeStones(stones) << endl;
  return 0;
}
