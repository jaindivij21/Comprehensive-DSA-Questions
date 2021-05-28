// Graph problem to check is the undirected graph has cycles or not
// using bfs (breath first search)

#include<iostream>
#include<map>
#include<list>
#include<queue>

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

    // function to check if a undirected graph is cyclic or not
    // basically check if the node has already been visited using the visited array. If true means the node is entering queue for the second time
    // thus there is a cycle. But, remember to exclude the parents while checking the visited array
    bool ifCyclic(T src) {
        // we'll store the parents of each node in the map to make sure the above condition isn't violated
        map<T, bool> visited;
        map<T, T> parents;

        queue<T> q; // queue for the bfs traversal

        // add the initial conditions
        visited[src] = true;    // mark it visited
        parents[src] = src; // make source's parents itself
        q.push(src);    // add the source into the queue

        while (!q.empty()) {
            // extract the front node
            T node = q.front();
            q.pop();

            // explore the neighbors of the node
            for (auto neighbors: adjList[node]) {
                // if the neighbors have already been visited and arent parents to node return false
                if (visited[neighbors] == true && parents[node] != neighbors) {
                    return true;
                }
                // else push them in the queue
                else {
                    q.push(neighbors);
                    parents[neighbors] = node;
                    visited[neighbors] = true;
                }
            }
        }
        return false;
    }
};

// main function
int main() {
    // make the graph
    graph<int> g;

    g.addEdge(1, 0);
    g.addEdge(1, 2);
    g.addEdge(0, 4);
    g.addEdge(2, 4);
    g.addEdge(2, 3);
    g.addEdge(4, 3);
    g.addEdge(5, 3);

    // print the list
    g.printList();

    // function to tell if the graph has cycles using BFS
    bool ans = g.ifCyclic(0);

    if (ans) {
        cout << "Cyclic!";
    } else {
        cout << "Not Cyclic!";
    }

    return 0;
}