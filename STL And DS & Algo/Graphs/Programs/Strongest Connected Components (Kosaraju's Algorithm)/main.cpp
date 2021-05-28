// Program to find if the graph is strongest connected component graph or not
/*
 *  Brute Force method would be to apply dfs on every node. For a graph to be SCC, from each node dfs should read each other node.
 *  So, you can count the number of nodes reached by each vertex, if any vertex fails to do so, it isn't SCC.
 *  TC: O(V+E)*V
 *
 *  Better approach is Kosaraju's Algo:
 *  TC = O(V+E)
 *  1) Apply dfs visit all edges
 *  2) Reverse all edges
 *  3) Apply dfs again trying to visit all edges
 *
 */

#include<bits/stdc++.h>

using namespace std;

// graph
class graph {
    int v;
    list<int> *l;
public:
    // constructor
    graph() {}

    graph(int ver) {
        v = ver;
        l = new list<int>[v + 1];
    }

    // add edge
    void addEdge(int src, int des, bool bidir = true) {
        l[src].push_back(des);
        if (bidir)
            l[des].push_back(src);
    }

    // print list
    void printList() {
        for (int i = 0; i < v; i++) {
            cout << i << "->";
            for (auto nbr:l[i]) {
                cout << nbr << " ";
            }
            cout << endl;
        }
    }

    // function to transpose adjacency list i.e. reverse all the edges
    graph transpose() {
        graph tempGraph(v); // makes a new graph
        // adds edges to it from the old graph
        for (int i = 0; i < v; i++) {
            for (auto nbr:l[i]) {
                tempGraph.addEdge(nbr, i, false);
            }
        }
        return tempGraph;
    }

    // dfs function that checks for Strongest connected components
    bool dfsForSCC() {
        bool *visited = new bool[v + 1]{false};
        int count1 = 0, count2 = 0;

        // DFS - 1 :: count 1 stores the number of nodes we are able to visit :: should be equal to v
        helper(0, visited, count1);
        if (count1 != v) {
            return false;
        }

        // funciton to reverse all the edges of the graph and make a new graph
        graph updatedGraph = transpose();

        // DFS - 2 :: count 2 stores the number of nodes we are able to visit :: should be equal to v and count 1
        visited = new bool[v + 1]{false};
        updatedGraph.helper(0, visited, count2);
        if (count2 != v) {
            return false;
        }

        // comparing count 1 and 2
        if (count1 == count2 == v) {
            return true;
        }
    }

    // main recursive dfs function
    void helper(int node, bool *visited, int &count) {
        visited[node] = true;
        count++;
        // explore nbs
        for (auto nbr:l[node]) {
            if (!visited[nbr]) {
                helper(nbr, visited, count);
            }
        }
    }
};

int main() {
    // Yes Example
    graph g1(5);
    g1.addEdge(0, 1, false);
    g1.addEdge(1, 2, false);
    g1.addEdge(2, 3, false);
    g1.addEdge(3, 0, false);
    g1.addEdge(2, 4, false);
    g1.addEdge(4, 2, false);

    // No example
//    graph g2(4);
//    g2.addEdge(0, 1, false);
//    g2.addEdge(1, 2, false);
//    g2.addEdge(2, 3, false);

    bool ans = g1.dfsForSCC();

    if (ans)
        cout << "Yes, its SCC" << endl;
    else
        cout << "No, its not SCC" << endl;

    return 0;
}