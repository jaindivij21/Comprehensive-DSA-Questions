// Leetcode : Find if Path Exists in Graph
// https://leetcode.com/problems/find-if-path-exists-in-graph/

#include<bits/stdc++.h>

using namespace std;

// main dfs function : // graph traversal in depth fashion
void dfs(vector<int> graph[], bool visited[], int src, int end, bool &ans) {
    // base case
    if (src == end)
        ans = true;

    // recursive cases
    visited[src] = true;
    for (auto i: graph[src]) {
        if (!visited[i]) {
            dfs(graph, visited, i, end, ans);
        }
    }
}

// Simple function that applies DFS or BFS to find path (path finding algorithms)
// Using DFS here : recursive algorithm
bool validPath(int n, vector<vector<int>> &edges, int start, int end) {
    // adj matrix : make a array of vectors to store all the edges
    vector<int> graph[n];
    for (auto i: edges) {
        graph[i[0]].push_back(i[1]);
        graph[i[1]].push_back(i[0]);
    }
    // visited array for the dfs
    bool visited[n];
    fill(visited, visited + n, false);
    // call the dfs function
    bool ans = false;
    dfs(graph, visited, start, end, ans);
    return ans;
}

int main() {
    vector<vector<int>> edges = {{0, 1},
                                 {1, 2},
                                 {2, 0}};
    cout << validPath(3, edges, 0, 2);

    return 0;
}


