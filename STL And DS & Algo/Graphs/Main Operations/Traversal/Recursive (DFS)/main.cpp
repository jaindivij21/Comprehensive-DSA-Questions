// Program for graph traversal :: DEPTH FIRST SEARCH
// Recursive method : Uses Stack as the data structure as recursion stack
// maintain a map data structure to maintain visited nodes list

// TC: O(V+E) in case of adjecency list and O(V^2) in case of adj Matrix
// Space Complexity: O(V)

#include<iostream>
#include<map>
#include<list>

using namespace std;

template<typename T>
class graph {
    // adjacency list
    map<T, list<T>> adjList;
public:
    graph() {
        // empty constructor
    }

    // function to add edges to the graph
    void addEdge(T u, T v, bool bidir = true) {
        adjList[u].push_back(v);
        if (bidir) {
            adjList[v].push_back(u);
        }
    }

    // function to print the adjacency list
    void printList() {
        for (auto node:adjList) {
            cout << node.first << " -> ";
            for (auto neighbor: node.second) {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }

    // dfs traversal
    void dfs(T src) {
        // takes source node as the parameter to start the dfs call
        map<T, bool> visited;
        cout << "\nThe DFS Traversal is" << endl;
        // recursive function to print the dfs traversal
        dfsHelper(src, visited);
    }

    void dfsHelper(T src, map<T, bool> &visited) {
        // print it and recursively call one of its children
        visited[src] = true;
        cout << src << " ";
        for (T neighbor : adjList[src]) {
            if (!visited[neighbor]) {
                // if the neighbor isn't visited recursive call to the neighbor
                dfsHelper(neighbor, visited);
            }
        }
    }
};

// main function
int main() {
    // make the graph
    graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(0, 2);
    g.addEdge(1, 3);

    // print the list
    g.printList();

    // dfs (depth first traversal)
    g.dfs(0);

    return 0;
}