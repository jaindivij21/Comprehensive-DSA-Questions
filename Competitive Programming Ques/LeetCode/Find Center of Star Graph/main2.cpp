// Find Center of Star Graph
// Leetocode : https://leetcode.com/problems/find-center-of-star-graph/

#include <bits/stdc++.h>

using namespace std;

int findCenter(vector<vector<int>> &edges)
{
  unordered_set<int> vertices;

  for (auto edge : edges)
  {
    for (auto vertex : edge)
    {
      if (vertices.find(vertex) != vertices.end())
        return vertex;
      vertices.insert(vertex);
    }
  }

  return -1;
}

int main()
{

  // Edge List
  vector<vector<int>> edges;
  edges.push_back({1, 2});
  edges.push_back({2, 3});
  edges.push_back({4, 2});
  findCenter(edges);

  return 0;
}