// Leetcode: Number of Ways to Arrive at Destination
// https://leetcode.com/problems/number-of-ways-to-arrive-at-destination

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MOD 1000000007
#define pii pair<long long, int>

class Solution
{
   public:
    int countPaths(int n, vector<vector<int> > &roads)
    {
        // Build adjacency list representation of the graph
        vector<vector<pii> > adj = buildAdjList(n, roads);

        // Min-heap (priority queue) for Dijkstra's algorithm
        priority_queue<pii, vector<pii>, greater<> > minHeap;
        minHeap.emplace(0, 0);  // {distance, node}

        // Distance array: stores the shortest distance from node 0 to each node
        vector<long long> shortestDist(n, LLONG_MAX);
        shortestDist[0] = 0;

        // Path count array: stores the number of shortest paths to each node
        vector<int> shortestPathCount(n, 0);
        shortestPathCount[0] = 1;

        while (!minHeap.empty())
        {
            auto [currDist, currNode] = minHeap.top();
            minHeap.pop();

            // If we have already found a shorter distance to currNode, skip
            // processing
            if (currDist > shortestDist[currNode]) continue;

            for (auto &[neighbor, edgeWeight] : adj[currNode])
            {
                long long newDist = currDist + edgeWeight;

                // Found a shorter path to neighbor
                if (newDist < shortestDist[neighbor])
                {
                    shortestDist[neighbor] = newDist;
                    shortestPathCount[neighbor] =
                        shortestPathCount[currNode];  // Reset count
                    minHeap.emplace(newDist, neighbor);
                }
                // If the new path has the same shortest distance, add the path
                // count
                else if (newDist == shortestDist[neighbor])
                {
                    shortestPathCount[neighbor] =
                        (shortestPathCount[neighbor] +
                         shortestPathCount[currNode]) %
                        MOD;
                }
            }
        }

        return shortestPathCount[n - 1];  // Return number of shortest paths to
                                          // the last node
    }

   private:
    // Helper function to build adjacency list
    static vector<vector<pii> > buildAdjList(int n, vector<vector<int> > &roads)
    {
        vector<vector<pii> > adj(n);
        for (auto &road : roads)
        {
            int u = road[0], v = road[1], time = road[2];
            adj[u].emplace_back(v, time);
            adj[v].emplace_back(u, time);
        }
        return adj;
    }
};

int main()
{
    Solution solution;
    int n = 7;
    vector<vector<int> > roads = {{0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3},
                                  {6, 3, 3}, {3, 5, 1}, {6, 5, 1}, {2, 5, 1},
                                  {0, 4, 5}, {4, 6, 2}};

    cout << solution.countPaths(n, roads) << endl;  // Output: 4

    return 0;
}
