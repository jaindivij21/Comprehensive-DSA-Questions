// Leetcode :: All Paths From Source to Target
// https://leetcode.com/problems/all-paths-from-source-to-target/

// Time Complexity : We have a total of 2^(n-2) paths from src to des. So roughly 2^n or exponential

#include<bits/stdc++.h>

using namespace std;

// dfs funciton :: not passing visited and ans by refernce since i need to backtrack anyways to find all the path from src to destination
void dfs(vector<vector<int>> &graph, unordered_set<int> visited, vector<vector<int>> &finalAns, vector<int> ans, int node, int &des) {
    // base case : if we reach destination
    if (node == des) {
        ans.push_back(node);
        finalAns.push_back(ans);
        return;
    }
    // recursive cases
    visited.insert(node); // insert the node into the visited section
    ans.push_back(node);    // push node into the ans vector
    // call the recursive fx for all the neighbors if unvisited
    for (auto neighbor : graph[node]) {
        if (visited.find(neighbor) == visited.end()) {
            // unvisited
            dfs(graph, visited, finalAns, ans, neighbor, des);
        }
    }

}

// need to perform a basic BFS or DFS from src to target to get all the paths : in this ques we will apply DFS using recursion
vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
    unordered_set<int> visited;   // make a set to store the visited nodes (not essential in this question since there are no back edges)
    vector<vector<int>> finalAns;   // main ans
    vector<int> ans;
    int numberOfNodes = graph.size()-1;
    dfs(graph, visited, finalAns, ans, 0, numberOfNodes);   // dfs call
    return finalAns;
}

int main() {
    vector<vector<int>> adjMatrix;

    int nodes;
    cin >> nodes;

    // make the adj matrix
    for (int i = 0; i < nodes; i++) {
        // for each node, get the number of edges
        int edges;
        cin >> edges;
        for (int j = 0; j < edges; j++) {
            int node;
            cin >> node;
            adjMatrix[i].push_back(node);
        }
    }

    vector<vector<int>> ans = allPathsSourceTarget(adjMatrix);

    return 0;
}