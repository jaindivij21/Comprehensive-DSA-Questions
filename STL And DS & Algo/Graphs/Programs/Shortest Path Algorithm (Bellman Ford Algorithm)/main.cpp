// Bellman Ford Algorithm :: SSSP Algorithm
// Works on directed/undirected graphs even with the -ve weights which was a limitation of Dijkstra Algorithm
/*
 *  Bellman too has a limitation i.e. it fails to work if the graph has negative cycle.
 *  TC: Worst Case: O(VE) --> Simple Implementation
 *
 *  Bellman Ford vs Dijkstra
 *  While Dijkstra looks only to the immediate neighbors of a vertex, Bellman goes through each edge in every iteration and takes almost V-1 iterations.
 */


#include<iostream>
#include<map>
#include<unordered_map>
#include<queue>
#include<set>
#include<climits>
#include<list>

using namespace std;

template<typename T>
class graph {
    int ver;
    int maxWeight;
    // graph made using adjacency List => key:T, Value:List of Pairs of T and Weights (int) associated.
    unordered_map<T, list<pair<T, int>>> adjList; // can use map also if you dont care about the order (at expense of time complexity)
public:
    graph() {
        // empty constructor
    }

    // add edges function
    void addEdges(T u, T v, int w, bool bidir = true) {
        adjList[u].push_back(make_pair(v, w));
        if (bidir) {
            adjList[v].push_back(make_pair(u, w));
        }
        if (w > maxWeight)
            maxWeight = w;
    }

    // print the list function
    void printList() {
        cout << "NodeFrom->NodeTo1:Weight1 NodeTo2:Weight2...." << endl;
        for (auto node: adjList) {
            cout << node.first << "->";
            for (auto neighbor: node.second) {
                cout << neighbor.first << ":" << neighbor.second << " ";
            }
            cout << endl;
        }
    }

    // counts vertices in the graph
    void vertices() {
        // efficient method would be to do a dfs or a bfs instead of this brute force solution
        unordered_map<T, bool> visited{false}; // stores if a node is visited or not
        int count = 0;
        for (auto node : adjList) {
            if (!visited[node.first]) {
                count++;
                visited[node.first] = true;
            }
            for (auto neighbor:node.second) {
                if (!visited[neighbor.first]) {
                    count++;
                    visited[neighbor.first] = true;
                }
            }
        }
        ver = count;
    }

    void bellman(T src, T des) {
        // count the number of vertices first
        vertices();

        // make a distance map that keeps track of the distances from the source
        unordered_map<T, int> distance;

        // make source as 0 and all others as Inf
        for (auto node: adjList) {
            if (node.first == src) {
                distance[node.first] = 0;
            } else {
                distance[node.first] = INT_MAX - maxWeight - 1;
            }
        }

        // parents map to keep track of the parent of each node
        unordered_map<T, T> parent;

        // relax all the edges V-1 times
        for (int i = 0; i < ver - 1; i++) {
            for (auto node:adjList) {
                for (auto neighbor:node.second) {
                    // relaxation
                    int nodeDis = distance[node.first];
                    int edgeWeight = neighbor.second;
                    int x = distance[neighbor.first];
                    if (x > (nodeDis + edgeWeight)) {
                        distance[neighbor.first] = nodeDis + edgeWeight;
                        parent[neighbor.first] = node.first;
                    }
                }
            }
        }

        // detect negative cycle :: this can be done by running the loop once more i.e. Vth time and if the value if still updated means the -ve cycle exists.
        for (auto node:adjList) {
            for (auto neighbor:node.second) {
                // relaxation
                if (distance[neighbor.first] > distance[node.first] + neighbor.second) {
                    cout << "A negative cycle exists in the graph" << endl;
                    return;
                }
            }
        }

        // Print distance to all other node from src
        for (auto d:distance) {
            cout << d.first << " is located at distance of  " << d.second << endl;
        }

        // print the path from the src to dest node
        cout << "The path from source to destination is:" << endl;
        T temp = des;
        cout << des << " <- ";
        temp = parent[temp];
        while (temp != src) {
            cout << temp << " <- ";
            temp = parent[temp];
        }
        cout << src << endl;
    }
};

// main function
int main() {
    graph<int> g;
    g.addEdges(0, 1, 5, false);
    g.addEdges(0, 2, 4, false);
    g.addEdges(1, 3, 3, false);
    g.addEdges(2, 1, 6, false);
    g.addEdges(3, 2, 2, false);

    g.printList();

    g.bellman(0, 3);

    return 0;
}