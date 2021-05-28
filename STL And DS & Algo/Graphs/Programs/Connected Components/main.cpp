// Program to count the number of connected components in a graph and print them using DFS
// bfs can also find if a graph has connected components but dfs is much quicker.

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

        int component = 1;  // counts the number of components in a graph
        // recursive function to print the dfs traversal
        dfsHelper(src, visited);

        // if still some nodes from the graph are left to be printed after we have done the dfs
        // traversal means that the graph has multiple components

        // so print the next components
        for (auto node: adjList) {
            if (!visited[node.first]) {
                // means this city hasn't been yet visited even after the end of the dfs traversal
                cout << endl;
                component++;
                dfsHelper(node.first, visited);
            }
        }

        // print the number of components
        cout << "\nThe number of connected components in the graph are:" << component;
    }

    // recursive dfs helper function
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
    graph<string> g;
    g.addEdge("Amritsar", "Jaipur");
    g.addEdge("Amritsar", "Delhi");
    g.addEdge("Delhi", "Jaipur");
    g.addEdge("Mumbai", "Jaipur");
    g.addEdge("Mumbai", "Bhopal");
    g.addEdge("Mumbai", "Bangalore");
    g.addEdge("Agra", "Delhi");
    g.addEdge("Andaman", "Nicobar");

    // print the list
    g.printList();

    // dfs (depth first traversal)
    g.dfs("Amritsar");

    return 0;
}