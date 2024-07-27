// Leetcode: Minimum Cost to Convert String I
// https://leetcode.com/problems/minimum-cost-to-convert-string-i/description

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class FloydWarshallAlgo
{
public:
  int noOfVertices;
  vector<vector<int>> adjMatrix;

  // Methods
  void setAdjMatrix(unordered_map<char, int> &vertices, const vector<char> &original, const vector<char> &changed, const vector<int> &cost)
  {
    noOfVertices = vertices.size();
    adjMatrix.resize(noOfVertices, vector<int>(noOfVertices, INT_MAX));

    for (int vertex = 0; vertex < noOfVertices; vertex++)
      adjMatrix[vertex][vertex] = 0;

    for (int i = 0; i < original.size(); i++)
    {
      int u = vertices[original[i]];
      int v = vertices[changed[i]];
      adjMatrix[u][v] = min(adjMatrix[u][v], cost[i]);
    }
  }

  // Floyd Warshall Algorithm
  vector<vector<int>> generateShortestPathMatrix()
  {
    // For each vertex as the intermediary vertex
    for (int vertex = 0; vertex < noOfVertices; vertex++)
    {
      // Iterate over each cell of the adjMatrix
      for (int row = 0; row < adjMatrix.size(); row++)
      {
        for (int col = 0; col < adjMatrix[0].size(); col++)
        {
          if (adjMatrix[row][vertex] != INT_MAX && adjMatrix[vertex][col] != INT_MAX)
          {
            // Modify the distance as the minimum of direct distance or indirect distance with vertex as intermediate vertex
            adjMatrix[row][col] = min(adjMatrix[row][col], adjMatrix[row][vertex] + adjMatrix[vertex][col]);
          }
        }
      }
    }

    return adjMatrix;
  }
};

class Solution
{
public:
  long long minimumCost(
      string source,
      string target,
      vector<char> &original,
      vector<char> &changed,
      vector<int> &cost)
  {
    unordered_map<char, int> vertices;
    int count = 0;
    // Include all characters from source and target into vertices map
    for (char c : source)
    {
      if (vertices.find(c) == vertices.end())
      {
        vertices[c] = count++;
      }
    }
    for (char c : target)
    {
      if (vertices.find(c) == vertices.end())
      {
        vertices[c] = count++;
      }
    }
    for (char c : original)
    {
      if (vertices.find(c) == vertices.end())
      {
        vertices[c] = count++;
      }
    }
    for (char c : changed)
    {
      if (vertices.find(c) == vertices.end())
      {
        vertices[c] = count++;
      }
    }

    // Use the original, changed and cost array to build an adjMatrix for FloydWarshallAlgo
    FloydWarshallAlgo fwa;
    fwa.setAdjMatrix(vertices, original, changed, cost);
    vector<vector<int>> shortedPairPaths = fwa.generateShortestPathMatrix();

    long long ans = 0;
    // Loop over the strings
    for (int i = 0; i < source.size(); i++)
    {
      if (shortedPairPaths[vertices[source[i]]][vertices[target[i]]] == INT_MAX)
      {
        return -1;
      }

      ans += shortedPairPaths[vertices[source[i]]][vertices[target[i]]];
    }

    return ans;
  }
};

int main()
{
  string source = "abcd";
  string target = "acbe";
  vector<char> original = {'a', 'b', 'c', 'c', 'e', 'd'};
  vector<char> changed = {'b', 'c', 'b', 'e', 'b', 'e'};
  vector<int> cost = {2, 5, 5, 1, 2, 20};

  Solution s;
  cout << s.minimumCost(source, target, original, changed, cost) << endl;

  return 0;
}
