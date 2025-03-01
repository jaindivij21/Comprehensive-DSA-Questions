// Leetcode: Reorder Routes to Make All Paths Lead to the City Zero
// https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
   public:
    int minReorder(int n, vector<vector<int>> &connections)
    {
        // Convert the given edge list into an adjacency list representation
        vector<vector<pair<int, bool>>> adjList = getAdjList(n, connections);

        // A vector to track visited nodes to avoid reprocessing
        vector<bool> visited(n, false);

        // Variable to count the number of roads that need to be reordered
        int minReorders = 0;

        // Perform a depth-first search (DFS) starting from city 0
        dfs(adjList, visited, minReorders, 0);

        return minReorders;
    }

   private:
    /**
     * Function to build the adjacency list representation of the graph.
     * Each node will store pairs where:
     *   - First element: The connected node
     *   - Second element: A boolean indicating if the edge is originally
     * directed away from the current node. (true means it needs to be reordered
     * when coming from city 0)
     */
    vector<vector<pair<int, bool>>> getAdjList(int n,
                                               vector<vector<int>> &connections)
    {
        vector<vector<pair<int, bool>>> adjList(n);

        for (auto &edge : connections)
        {
            int from = edge[0];
            int to = edge[1];

            // Store edge with its direction
            adjList[from].emplace_back(to, true);  // Edge in original direction
            adjList[to].emplace_back(
                from,
                false);  // Reverse direction edge (virtual undirected graph)
        }

        return adjList;
    }

    /**
     * DFS function to traverse the graph and count the number of edges that
     * need to be reversed.
     * @param adjList    Adjacency list representation of the graph.
     * @param visited    Vector to keep track of visited nodes.
     * @param minReorders Reference to the counter for required edge reorders.
     * @param node       Current node being processed.
     */
    void dfs(vector<vector<pair<int, bool>>> &adjList, vector<bool> &visited,
             int &minReorders, int node)
    {
        // If the node is already visited, return
        if (visited[node]) return;

        // Mark the node as visited
        visited[node] = true;

        // Explore all its neighbors
        for (auto &edge : adjList[node])
        {
            int neighbor = edge.first;
            bool isOriginalDirection = edge.second;

            if (!visited[neighbor])
            {
                // If the edge is originally directed away from the current node
                // (meaning it needs to be reversed)
                if (isOriginalDirection) minReorders++;

                // Recur for the next node
                dfs(adjList, visited, minReorders, neighbor);
            }
        }
    }
};

int main()
{
    Solution s;
    vector<vector<int>> connections = {{0, 1}, {1, 3}, {2, 3}, {4, 0}, {4, 5}};

    cout << s.minReorder(6, connections) << endl;

    return 0;
}