// Leetcode: Build a Matrix With Conditions
// https://leetcode.com/problems/build-a-matrix-with-conditions

#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution
{
  /*
   Concept:
      This problem can be effectively approached by conceptualizing it as a graph problem involving topological
      sorting. The rowConditions and colConditions can be represented as two separate directed acyclic graphs (DAGs).
      In these graphs, each node corresponds to an integer from 1 to k, and each directed edge represents a
      dependency. A topological sort of these graphs will provide the order in which the integers should appear
      in the matrix to satisfy the given conditions. If either graph contains a cycle, it implies that no valid
      matrix can be constructed, and the function should return an empty matrix.
  */
public:
  vector<vector<int>> buildMatrix(int k, vector<vector<int>> &rowConditions, vector<vector<int>> &colConditions)
  {
    // Build adjacency matrices for row and column conditions
    unordered_map<int, vector<int>> rowAdjMatrix = buildAdjMatrix(k, rowConditions);
    unordered_map<int, vector<int>> colAdjMatrix = buildAdjMatrix(k, colConditions);

    // Perform topological sorting on the row and column graphs
    vector<int> rowOrder = topologicalSort(rowAdjMatrix, k);
    vector<int> colOrder = topologicalSort(colAdjMatrix, k);

    // If either topological sort fails (cycle detected), return an empty matrix
    if (rowOrder.empty() || colOrder.empty())
    {
      return {};
    }

    // Initialize the matrix with zeros
    vector<vector<int>> matrix(k, vector<int>(k, 0));

    // Create position mappings from the topological sort results
    vector<int> rowPosition(k + 1), colPosition(k + 1);
    for (int i = 0; i < k; i++)
    {
      rowPosition[rowOrder[i]] = i;
      colPosition[colOrder[i]] = i;
    }

    // Place the numbers in the matrix according to the row and column positions
    for (int num = 1; num <= k; num++)
    {
      matrix[rowPosition[num]][colPosition[num]] = num;
    }

    return matrix;
  }

private:
  // Build adjacency matrix from the given conditions
  static unordered_map<int, vector<int>> buildAdjMatrix(int k, vector<vector<int>> &conditions)
  {
    unordered_map<int, vector<int>> adjMatrix;
    for (auto &condition : conditions)
    {
      adjMatrix[condition[0]].emplace_back(condition[1]);
    }
    return adjMatrix;
  }

  // Perform topological sorting on the given adjacency matrix
  static vector<int> topologicalSort(unordered_map<int, vector<int>> &adjMatrix, int k)
  {
    unordered_map<int, int> inDegree;
    for (int i = 1; i <= k; i++)
    {
      inDegree[i] = 0;
    }

    // Calculate in-degrees of all nodes
    for (auto &node : adjMatrix)
    {
      for (int neighbor : node.second)
      {
        inDegree[neighbor]++;
      }
    }

    // Collect all nodes with zero in-degree
    queue<int> zeroInDegreeNodes;
    for (int i = 1; i <= k; i++)
    {
      if (inDegree[i] == 0)
      {
        zeroInDegreeNodes.push(i);
      }
    }

    vector<int> sortedOrder;
    while (!zeroInDegreeNodes.empty())
    {
      int node = zeroInDegreeNodes.front();
      zeroInDegreeNodes.pop();
      sortedOrder.push_back(node);

      // Decrease the in-degree of all neighbors
      for (int neighbor : adjMatrix[node])
      {
        inDegree[neighbor]--;
        // If in-degree becomes zero, add to queue
        if (inDegree[neighbor] == 0)
        {
          zeroInDegreeNodes.push(neighbor);
        }
      }
    }

    // If sorted order contains all nodes, return it; otherwise, return empty (cycle detected)
    if (sortedOrder.size() == k)
    {
      return sortedOrder;
    }
    else
    {
      return {};
    }
  }
};

int main()
{
  int k = 3;
  vector<vector<int>> rowConditions = {{1, 2},
                                       {3, 2}};
  vector<vector<int>> colConditions = {{2, 1},
                                       {3, 2}};

  Solution s;
  vector<vector<int>> ans = s.buildMatrix(k, rowConditions, colConditions);

  return 0;
}
