// Leetcode: Path with Maximum Probability
// https://leetcode.com/problems/path-with-maximum-probability

#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;

class DijikstraAlgo
{
public:
  // Properties
  unordered_map<int, vector<pair<int, double>>> adjList;

  // Constructor
  explicit DijikstraAlgo(unordered_map<int, vector<pair<int, double>>> adjList)
  {
    this->adjList = adjList;
  }

  // Methods

  /*
   *  Find the shortest paths from the start node to all other nodes in the graph.
   *  @param adjList: adjacency list of the graph
   *  @param startNode: the node from which the shortest paths are to be found
   *
   *  @return maximumProb: a map of nodes and their maximum probabilities from the start node
   */
  unordered_map<int, double> findMaximumProb(int startNode)
  {
    // Map to store the shortest paths from the start node
    unordered_map<int, double> maximumProbs;
    for (const auto &node : adjList)
    {
      maximumProbs[node.first] = INT_MIN;
    }

    // Heap to store the nodes and their probabilities from the start node
    priority_queue<pair<double, int>> maxHeap;

    // Init the start node
    maximumProbs[startNode] = 1;
    maxHeap.emplace(1, startNode);

    while (!maxHeap.empty())
    {
      pair<double, int> heapTop = maxHeap.top();
      maxHeap.pop();

      int currentNode = heapTop.second;
      double currentProb = heapTop.first;

      for (const auto &neighbor : adjList[currentNode])
      {
        int neighborNode = neighbor.first;
        double edgeWeight = neighbor.second;
        double newProbability = maximumProbs[currentNode] * edgeWeight;

        if (newProbability > maximumProbs[neighborNode])
        {
          maximumProbs[neighborNode] = newProbability;
          maxHeap.emplace(newProbability, neighborNode);
        }
      }
    }

    return maximumProbs;
  }
};

class Solution
{
public:
  double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start_node, int end_node)
  {
    // Build adjList from the edges
    unordered_map<int, vector<pair<int, double>>> adjList;
    for (int i = 0; i < edges.size(); i++)
    {
      adjList[edges[i][0]].emplace_back(edges[i][1], succProb[i]);
      adjList[edges[i][1]].emplace_back(edges[i][0], succProb[i]);
    }

    DijikstraAlgo da(adjList);
    unordered_map<int, double> shortedPaths = da.findMaximumProb(start_node);

    return shortedPaths[end_node] == INT_MIN ? 0.0 : shortedPaths[end_node];
  }
};

int main()
{
  int n = 3;
  vector<vector<int>> edges = {{0, 1},
                               {1, 2},
                               {0, 2}};
  vector<double> succProb = {0.5, 0.5, 0.2};
  int start_node = 0;
  int end_node = 2;

  Solution sol;
  cout << sol.maxProbability(n, edges, succProb, start_node, end_node) << endl;

  return 0;
}