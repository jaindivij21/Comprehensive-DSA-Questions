// Leetcode: Evaluate Division
// https://leetcode.com/problems/evaluate-division

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
   public:
    /*
     * Approach: Graph-based solution using DFS
     * - Build an undirected graph where each variable is a node.
     * - Each equation represents an edge with a given weight (value of
     * division).
     * - For queries "X / Y":
     *   - Use DFS to find a path from X to Y.
     *   - Multiply edge weights along the path to compute the result.
     *   - If no path exists, return -1.0.
     */
    vector<double> calcEquation(vector<vector<string>> &equations,
                                vector<double> &values,
                                vector<vector<string>> &queries)
    {
        unordered_map<string, vector<pair<string, double>>> graph =
            buildGraph(equations, values);

        vector<double> results;
        for (const auto &query : queries)
        {
            string numerator = query[0];
            string denominator = query[1];

            unordered_map<string, bool> visited;
            for (const auto &node : graph)
            {
                visited[node.first] = false;
            }

            results.push_back(dfs(numerator, denominator, graph, visited));
        }

        return results;
    }

   private:
    // Depth-First Search (DFS) to find a path from 'current' to 'target'.
    double dfs(string current, const string &target,
               unordered_map<string, vector<pair<string, double>>> &graph,
               unordered_map<string, bool> &visited)
    {
        // If the node is not in the graph, return -1.0
        if (!graph.contains(current))
        {
            return -1.0;
        }

        // If the current node is the target, return 1.0 (X/X = 1)
        if (current == target)
        {
            return 1.0;
        }

        // If already visited, avoid cycles
        if (visited[current])
        {
            return -1.0;
        }

        visited[current] = true;  // Mark as visited

        // Explore neighbors recursively
        for (const auto &[neighbor, weight] : graph[current])
        {
            double product = weight * dfs(neighbor, target, graph, visited);
            if (product > 0)
            {  // Valid path found
                return product;
            }
        }

        return -1.0;  // No valid path found
    }

    // Build an adjacency list representation of the graph from the given
    // equations and values.
    unordered_map<string, vector<pair<string, double>>> buildGraph(
        const vector<vector<string>> &equations, const vector<double> &values)
    {
        unordered_map<string, vector<pair<string, double>>> graph;

        for (auto i = 0; i < equations.size(); ++i)
        {
            string numerator = equations[i][0];
            string denominator = equations[i][1];
            double value = values[i];

            // Add both forward and inverse relationships
            graph[numerator].emplace_back(denominator, value);
            graph[denominator].emplace_back(numerator, 1.0 / value);
        }

        return graph;
    }
};

int main()
{
    Solution sol;

    vector<vector<string>> equations = {{"a", "b"}};
    vector<double> values = {0.5};
    vector<vector<string>> queries = {
        {"a", "b"}, {"b", "a"}, {"a", "c"}, {"x", "y"}};

    vector<double> result = sol.calcEquation(equations, values, queries);

    return 0;
}