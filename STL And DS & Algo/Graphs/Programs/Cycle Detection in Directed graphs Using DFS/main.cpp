// Graph problem to check is the **Directed** graph has cycles or not
// using dfs (depth first search)::  through back edges

/*
 *  Back Edges: A back edge is an edge from u->v where u comes in path of v or u is an ancestor of v
 */

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

    // function to check if a directed graph is cyclic or not
    // makes use of DFS adn checks for back edges, If a graph has back edges; then the graph is cyclic
    /*
     *  Working: Basically we make normal recursive calls like in dfs but also check if the new node has already been visited & secondly if
     *  its in current recursion stack or not.
     *      If the new node has been already visited and at the same time also is in the recursion stack means its a cycle
    */
    bool ifCyclic() {
        map<T, bool> visited;
        map<T, bool> inStack;

        // to make sure all the nodes are covered even if there are connected componenets
        for (auto i:adjList) {
            T node = i.first;
            if (!visited[node]) {
                bool ans = helper(node, visited, inStack);
                if (ans)
                    return true;
            }
        }
        return false;
    }

    /*
     *  NOTE:
     *  It can never happen that inStack is true but visited false, however vice versa is possible 
     */
    
    // dfs helper function
    bool helper(T node, map<T, bool> &visited, map<T, bool> &inStack) {
        // change conditions for the current node
        visited[node] = true;
        inStack[node] = true;

        // search for its neighbors and explore from there
        for (auto neighbor: adjList[node]) {
            // two things can happen when we have to return true otherwise false
            if ((visited[neighbor] == false && helper(neighbor, visited, inStack) == true) || inStack[neighbor] == true) {
                // if the neighbor node isn't visited but its further branch is leading to a cycle OR neighbor node is already in STACK
                return true;    // i.e. a cycle exists
            }
        }
        // Pop the node, i.e. make inStack = false since we have explored this node and now want to return
        inStack[node] = false;
        // in all other cases
        return false;
    }
};

// main function
int main() {
    // make the graph
    graph<int> g;

    g.addEdge(0, 2, false);
    g.addEdge(0, 1, false);
    g.addEdge(2, 3, false);
    g.addEdge(2, 4, false);
    g.addEdge(3, 0, false);
    g.addEdge(4, 5, false);
    g.addEdge(1, 5, false);


    // print the list
    g.printList();

    // function to tell if the graph has cycles using BFS
    if (g.ifCyclic()) {
        cout << "Cyclic!";
    } else {
        cout << "Not Cyclic!";
    }

    return 0;
}