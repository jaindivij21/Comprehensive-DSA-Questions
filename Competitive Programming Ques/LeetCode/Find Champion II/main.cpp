// Leetcode: Find Champion II
// https://leetcode.com/problems/find-champion-ii

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  int findChampion(int n, vector<vector<int>> &edges)
  {
    // Array to track in-degrees for each node (number of incoming edges)
    vector<int> inDegrees(n, 0);

    // Calculate the in-degrees for all nodes
    for (const auto &edge : edges)
    {
      inDegrees[edge[1]]++;
    }

    // Variables to track the node with the minimum in-degree
    int minInDegree = INT_MAX;
    int minDegreeCount = 0;
    int candidateNode = -1;

    // Iterate through all nodes to find the node with the minimum in-degree
    for (int node = 0; node < n; ++node)
    {
      if (inDegrees[node] < minInDegree)
      {
        // Update minimum in-degree and reset related variables
        minInDegree = inDegrees[node];
        candidateNode = node;
        minDegreeCount = 1; // Reset count as we found a new minimum
      }
      else if (inDegrees[node] == minInDegree)
      {
        // If multiple nodes have the same minimum in-degree, increment the count
        minDegreeCount++;
      }
    }

    // If there is more than one node with the minimum in-degree, return -1
    return minDegreeCount > 1 ? -1 : candidateNode;
  }
};

int main()
{
  Solution sol;

  int n = 3;
  vector<vector<int>> edges = {{0, 1},
                               {1, 2}};

  cout << sol.findChampion(n, edges) << endl;

  return 0;
}