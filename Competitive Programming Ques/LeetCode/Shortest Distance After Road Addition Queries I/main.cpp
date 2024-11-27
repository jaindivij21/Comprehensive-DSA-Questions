// Leetcode: Shortest Distance After Road Addition Queries I
// https://leetcode.com/problems/shortest-distance-after-road-addition-queries-i

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
  vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>> &edgeList)
  {
    vector<vector<int>> adjList(n);
    for (int i = 0; i <= n - 2; i++)
    {
      adjList[i].push_back(i + 1);
    }

    vector<int> ans;

    for (auto i : edgeList)
    {
      adjList[i[0]].push_back(i[1]);
      ans.push_back(bfs(adjList));
    }

    return ans;
  }

private:
  int bfs(vector<vector<int>> &adjList)
  {
    int startIdx = 0;
    int endIdx = adjList.size() - 1;

    vector<int> visited(adjList.size(), 0);
    queue<pair<int, int>> q;

    // Start from the first node
    q.push({startIdx, 0});
    visited[startIdx] = 1;

    while (!q.empty())
    {
      auto [node, distance] = q.front();
      q.pop();

      if (node == endIdx)
      {
        return distance;
      }

      for (auto i : adjList[node])
      {
        if (visited[i] == 0)
        {
          q.push({i, distance + 1});
          visited[i] = 1;
        }
      }
    }

    return -1;
  }
};

int main()
{
  Solution sol;

  int n = 5;
  vector<vector<int>> queries = {{2, 4},
                                 {0, 2},
                                 {0, 4}};
  vector<int> result = sol.shortestDistanceAfterQueries(n, queries);

  return 0;
}