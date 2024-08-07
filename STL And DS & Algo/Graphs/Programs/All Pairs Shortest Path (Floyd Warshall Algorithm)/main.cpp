// Floyd-Warshall Algorithm
// https://www.youtube.com/watch?v=oNI0rf2P9gE&t=677s

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

int main()
{
  int n = 5;
  vector<vector<int>> edges = {{0, 1, 2}, {0, 4, 8}, {1, 2, 3}, {1, 4, 2}, {2, 3, 1}, {3, 4, 1}};

  FloydWarshallAlgo fwa(n);
  fwa.setAdjMatrix(edges);

  vector<vector<int>> shortedPathMatrix = fwa.generateShortestPathMatrix();

  return 0;
}