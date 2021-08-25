// Leetcode : Minimum Number of Vertices to Reach All Nodes
// https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/

// Intuition: Use Traversal - Apply DFS or any other kind of traversal and add all those nodes from which the the entire graph can be traversed.
// Other solution can be all those nodes that have an In-degree as 0

// Time complexity (sol 2) :  O(E) i.e. number of edges
// Space Complexity : O(V) i.e. number of vertices

// USE SOL 2

#include<bits/stdc++.h>

using namespace std;

// main dfs function : // graph traversal in depth fashion
void dfs(vector<int> graph[], bool visited[], int src) {
    // recursive cases
    for (auto i: graph[src]) {
        if (!visited[i]) {
            visited[src] = true;
            dfs(graph, visited, i);
        }
    }
}

// sol 1 :: try to traverse the entire graph and add to ans the vertices which act as starting points ( let them be unvisited) :: this is almost same as sol2 
vector<int> findSmallestSetOfVertices1(int n, vector<vector<int>> &edges) {
    // adj matrix : make a array of vectors to store all the edges
    vector<int> graph[n];
    for (auto i: edges) {
        graph[i[0]].push_back(i[1]);
    }
    // visited array for the dfs
    bool visited[n];
    fill(visited, visited + n, false);
    // make ans vector and call the dfs function
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        // for all vertices
        if (!visited[i]) {
            dfs(graph, visited, i);

            for (int i = 0; i < n; ++i) {
                cout << visited[i] << " ";
            }
            cout << endl;

        }
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i])
            ans.push_back(i);
    }
    return ans;
}

// sol 2 :: cal the number of nodes with inDegree as 0, This works because nodes with indegree as 0 are the only ones that cant be reached from any other nodes but, all other nodes
// can be reached from these nodes. Hence they form the answer.
vector<int> findSmallestSetOfVertices2(int n, vector<vector<int>> &edges) {
    // make an indegree vector
    int inDegree[n];
    fill(inDegree, inDegree + n, 0);
    for (auto i: edges) {
        inDegree[i[1]]++;
    }
    // take the nodes with indegree as 0
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            ans.push_back(i);
        }
    }
    return ans;
}

int main() {
    // edge list
    int n = 6;
    vector<vector<int>> edges = {{0, 1},
                                 {0, 2},
                                 {2, 5},
                                 {3, 4},
                                 {4, 2}};
    vector<int> ans = findSmallestSetOfVertices1(n, edges);
//    vector<int> ans = findSmallestSetOfVertices2(n, edges);
    return 0;
}