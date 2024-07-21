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
   Time Complexity:
   Space Complexity:
  */
public:
  vector<vector<int>> buildMatrix(int k, vector<vector<int>> &rowConditions, vector<vector<int>> &colConditions)
  {
    unordered_map<int, vector<int>> rowGraph = buildAdjMatrix(k, rowConditions);
    unordered_map<int, vector<int>> colGraph = buildAdjMatrix(k, colConditions);

    vector<int> rowOrder = topologicalSort(rowGraph);
    vector<int> colOrder = topologicalSort(colGraph);

    vector<vector<int>> ans;
    if (rowOrder.empty() || colOrder.empty())
    {
      return ans;
    }
    else
    {
      ans.resize(k, vector<int>(k, 0));

      vector<int> rowPos(k + 1), colPos(k + 1);
      for (int i = 0; i < k; i++)
      {
        rowPos[rowOrder[i]] = i;
        colPos[colOrder[i]] = i;
      }

      for (int num = 1; num <= k; num++)
      {
        ans[rowPos[num]][colPos[num]] = num;
      }
    }

    return ans;
  }

private:
  static unordered_map<int, vector<int>> buildAdjMatrix(int k, vector<vector<int>> &rowConditions)
  {
    unordered_map<int, vector<int>> adjMatrix;
    for (auto &rowCondition : rowConditions)
    {
      adjMatrix[rowCondition[0]].emplace_back(rowCondition[1]);
    }

    return adjMatrix;
  }

  static vector<int> topologicalSort(unordered_map<int, vector<int>> &adjMatrix)
  {
    // Construct an unordered map for inDegrees
    unordered_map<int, int> inDegrees;
    for (auto &itr : adjMatrix)
    {
      inDegrees[itr.first];
      for (auto i : itr.second)
      {
        inDegrees[i]++;
      }
    }

    // Insert initial nodes with zero inDegree into a set
    queue<int> q;
    for (auto &inDegree : inDegrees)
    {
      if (inDegree.second == 0)
      {
        q.push(inDegree.first);
      }
    }

    vector<int> ans;
    while (!q.empty())
    {
      int front = q.front();
      q.pop();
      ans.push_back(front);

      // Find all the nodes to where an edge goes from this front element and reduce their inDegree by 1
      for (auto i : adjMatrix[front])
      {
        inDegrees[i]--;

        if (inDegrees[i] == 0)
          q.push(i);
      }
    }

    if (ans.size() == adjMatrix.size())
    {
      return ans;
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
