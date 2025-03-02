// Leetcode: Evaluate Division
// https://leetcode.com/problems/evaluate-division

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution
{
   public:
    /**
     * Calculates the results of division queries based on given equations and
     * values. Uses the Floyd-Warshall algorithm to compute all-pairs shortest
     * paths.
     *
     * @param equations A list of equation pairs where each equation is
     * represented as {numerator, denominator}.
     * @param values A list of values corresponding to the equations
     * (numerator/denominator).
     * @param queries A list of queries asking for division results between two
     * variables.
     * @return A vector of results where each value corresponds to a query
     * result or -1.0 if not computable.
     */
    vector<double> calcEquation(vector<vector<string>> &equations,
                                vector<double> &values,
                                vector<vector<string>> &queries)
    {
        // Build the graph from the given equations and values
        unordered_map<string, unordered_map<string, double>> graph =
            buildGraph(equations, values);

        // Apply Floyd-Warshall algorithm to compute all-pairs shortest paths
        for (const auto &k : graph)
        {
            // Iterate through each node as an intermediate node
            for (const auto &i : graph)
            {
                // Iterate through each source node
                for (const auto &j : graph)
                {
                    // Iterate through each destination node

                    // Get the current nodes
                    const string &intermediate = k.first;
                    const string &source = i.first;
                    const string &dest = j.first;

                    // Skip if a direct path already exists bw the source and
                    // dest nodes
                    if (graph[source].contains(dest)) continue;

                    // If paths exist from source -> intermediate and
                    // intermediate -> dest, update the shortest path
                    if (graph[source].contains(intermediate) &&
                        graph[intermediate].contains(dest))
                    {
                        graph[source][dest] = graph[source][intermediate] *
                                              graph[intermediate][dest];
                    }
                }
            }
        }

        vector<double> results;

        // Answer queries based on the computed paths
        for (const auto &query : queries)
        {
            const string &source = query[0];
            const string &dest = query[1];

            // If either variable is not in the graph, return -1.0
            if (!graph.contains(source) || !graph.contains(dest))
            {
                results.push_back(-1.0);
                continue;
            }

            // If both variables are the same, return 1.0 (self-division)
            if (source == dest)
            {
                results.push_back(1.0);
                continue;
            }

            // Return the precomputed shortest path if it exists, otherwise
            // return -1.0
            results.push_back(graph[source].contains(dest) ? graph[source][dest]
                                                           : -1.0);
        }

        return results;
    }

   private:
    /**
     * Builds a graph representation of the given equations and values.
     * Each node represents a variable, and edges represent division
     * relationships.
     *
     * @param equations A list of equations as pairs of variables.
     * @param values A list of corresponding numerical values representing the
     * ratio.
     * @return An adjacency map where graph[A][B] = A / B and graph[B][A] = B /
     * A.
     */
    unordered_map<string, unordered_map<string, double>> buildGraph(
        const vector<vector<string>> &equations, const vector<double> &values)
    {
        unordered_map<string, unordered_map<string, double>> graph;

        for (size_t i = 0; i < equations.size(); ++i)
        {
            const string &numerator = equations[i][0];
            const string &denominator = equations[i][1];
            double value = values[i];

            // Every node should have a self-loop with value 1.0 (x / x = 1)
            graph[numerator][numerator] = 1.0;
            graph[denominator][denominator] = 1.0;

            // Store direct relations from the input
            graph[numerator][denominator] = value;
            graph[denominator][numerator] = 1.0 / value;
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