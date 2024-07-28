// Dijikstra's Algorithm
// https://www.youtube.com/watch?v=XB4MIexjvY0

#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class DijikstraAlgo
{
public:
  // Properties
  unordered_map<int, vector<pair<int, int>>> adjList;

  // Constructor
  explicit DijikstraAlgo(unordered_map<int, vector<pair<int, int>>> adjList)
  {
    this->adjList = adjList;
  }

  // Methods

  /*
   *  Find the shortest paths from the start node to all other nodes in the graph.
   *  @param adjList: adjacency list of the graph
   *  @param startNode: the node from which the shortest paths are to be found
   *
   *  @return shortestPaths: a map of nodes and their shortest paths from the start node
   */
  unordered_map<int, int> findShortestPaths(int startNode)
  {
    // Map to store the shortest paths from the start node
    unordered_map<int, int> shortestPaths;
    for (const auto &node : adjList)
    {
      shortestPaths[node.first] = INT_MAX;
    }

    // Min Heap to store the nodes and their distances from the start node
    // (By def the greater<> functor sorts a pair in ascending order of the first element)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> minHeap;

    // Init the start node
    shortestPaths[startNode] = 0;
    minHeap.emplace(0, startNode);

    while (!minHeap.empty())
    {
      pair<int, int> heapTop = minHeap.top();
      minHeap.pop();

      int currentNode = heapTop.second;
      int currentDistance = heapTop.first;

      // If the current distance is greater than the shortest path to this node, then skip this node
      // because we have already found a shorter path to this node, so no need to explore it again
      if (currentDistance > shortestPaths[currentNode])
        continue;

      // Loop over all the neighbors of this node and relax them, i.e. perform the following operation
      // shortestPaths[neighbor] = min(shortestPaths[neighbor], shortestPaths[currentNode] + edgeWeight)
      for (const auto &neighbor : adjList[currentNode])
      {
        int neighborNode = neighbor.first;
        int edgeWeight = neighbor.second;
        int newDistance = shortestPaths[currentNode] + edgeWeight;

        if (newDistance < shortestPaths[neighborNode])
        {
          shortestPaths[neighborNode] = newDistance;
          minHeap.emplace(newDistance, neighborNode);
        }
      }
    }

    return shortestPaths;
  }
};

int main()
{
  // Graph using adjacency list
  unordered_map<int, vector<pair<int, int>>> adjList = {
      {0, {{1, 4}, {7, 8}}},
      {1, {{0, 4}, {2, 8}, {7, 11}}},
      {2, {{1, 8}, {3, 7}, {5, 4}, {8, 2}}},
      {3, {{2, 7}, {4, 9}, {5, 14}}},
      {4, {{3, 9}, {5, 10}}},
      {5, {{2, 4}, {3, 14}, {4, 10}, {6, 2}}},
      {6, {{5, 2}, {7, 1}, {8, 6}}},
      {7, {{0, 8}, {1, 11}, {6, 1}, {8, 7}}},
      {8, {{2, 2}, {6, 6}, {7, 7}}}};

  DijikstraAlgo dijikstraAlgo(adjList);
  unordered_map<int, int> shortestPaths = dijikstraAlgo.findShortestPaths(0);

  return 0;
}