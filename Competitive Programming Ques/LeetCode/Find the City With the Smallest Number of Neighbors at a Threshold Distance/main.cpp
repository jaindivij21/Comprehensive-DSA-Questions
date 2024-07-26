// Leetcode: Find the City With the Smallest Number of Neighbors at a Threshold Distance
// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance

#include <iostream>
#include <vector>

using namespace std;
#define INF 10001

class FloydWarshallAlgo
{
public:
  int noOfVertices;
  vector<vector<int>> adjMatrix;

  // Constructor
  explicit FloydWarshallAlgo(const int &vertices)
  {
    noOfVertices = vertices;
  }

  FloydWarshallAlgo(
      int noOfVertices,
      vector<vector<int>> &adjMatrix) : noOfVertices(noOfVertices), adjMatrix(adjMatrix) {}

  // Methods
  void setAdjMatrix(const vector<vector<int>> &edgeList)
  {
    // Resize the matrix and set all the distances to INF
    adjMatrix.resize(noOfVertices, vector<int>(noOfVertices, INF));

    // Set distance from self loops as 0
    for (int vertex = 0; vertex < noOfVertices; vertex++)
      adjMatrix[vertex][vertex] = 0;

    for (auto const &edge : edgeList)
    {
      adjMatrix[edge[0]][edge[1]] = edge[2];
      adjMatrix[edge[1]][edge[0]] = edge[2];
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
          // Modify the distance as the minimum of direct distance or indirect distance with vertex as intermediate vertex
          adjMatrix[row][col] = min(adjMatrix[row][col], adjMatrix[row][vertex] + adjMatrix[vertex][col]);
        }
      }
    }

    return adjMatrix;
  }
};

class Solution
{
public:
  int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
  {
    FloydWarshallAlgo fwa(n);
    fwa.setAdjMatrix(edges);

    vector<vector<int>> shortedPathMatrix = fwa.generateShortestPathMatrix();

    int ansVertex = 0;
    int minimumVisitedCitiesWithinThreshold = INT_MAX;
    for (int startVertex = 0; startVertex < shortedPathMatrix.size(); startVertex++)
    {
      int visitedCitiesWithinThreshold = 0;
      for (int endVertex = 0; endVertex < shortedPathMatrix[0].size(); endVertex++)
      {
        if (shortedPathMatrix[startVertex][endVertex] <= distanceThreshold)
          visitedCitiesWithinThreshold++;
      }

      if (visitedCitiesWithinThreshold <= minimumVisitedCitiesWithinThreshold)
      {
        minimumVisitedCitiesWithinThreshold = visitedCitiesWithinThreshold;
        ansVertex = startVertex;
      }
    }

    return ansVertex;
  }
};

int main()
{
  int n = 5;
  int distanceThreshold = 2;
  vector<vector<int>> edges = {{0, 1, 2}, {0, 4, 8}, {1, 2, 3}, {1, 4, 2}, {2, 3, 1}, {3, 4, 1}};

  Solution s = Solution();
  cout << s.findTheCity(n, edges, distanceThreshold) << endl;

  return 0;
}
