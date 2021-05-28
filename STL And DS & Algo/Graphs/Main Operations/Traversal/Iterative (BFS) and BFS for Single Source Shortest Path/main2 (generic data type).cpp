// Uses hash map to store the adjaceny list and generic data type is used!

// Graph Data Structure :: Main Operations
// Implementation using adjacency list using hashmap.
// MADE USING HASH MAP : where key is of type T and value is a list of type T

#include<iostream>
#include<map>
#include<list>
#include<string>
#include<queue>

using namespace std;

// template for generic graph - any kind of data
template<typename T>
class Graph {
    // map of key value pair :: T and list of T to which the key node is pointing to
    map<T, list<T>> g;
public:
    Graph() {
        // empty constructor
    }

    // function to add edges
    void addEdge(T u, T v, bool bidir = true) {
        // edges are assumed to be bidirectional by default
        g[u].push_back(v);
        if (bidir) {
            g[v].push_back(u);
        }
    }

    // function to print the adjacency list
    void printList() {
        for (auto row:g) {
            // returns a pair into row variable : where row.first is the key and row.second is list of values
            cout << row.first << "->";
            for (auto value: row.second) {
                // returns a T data type on each iteration which are the values for the key
                cout << value << " ";
            }
            cout << endl;
        }
    }

    // function to print bfs traversal and also implements single source shortest path
    // bfs traversal :: takes source and destination as parameter
    void bfs(T src, T des) {
        // queue stores nodes to be discovered
        queue<T> q;
        // map stores if a node has already been visited. We used an array in array of lists program version,
        // but it won't be possible here as the node can be of any data type and not just int.
        map<T, bool> visited;

        // extras for the implementation of SSSP
        map<T, int> dis;    // keeps track of the distance of the T node from the src
        map<T, T> parent;   // keeps track of each node's one of the parent so that we can print shortest path from src to dest

        // for the source update the visited map and also push it into the queue to explore its children
        q.push(src);
        visited[src] = true;
        dis[src] = 0;
        parent[src] = src;  // parent of src is considered to be src itself

        while (!q.empty()) {
            // pop item from queue and push the children
            T node = q.front();
            cout << node << " ";    // bfs traversal
            q.pop();

            // for the neighbors of current node, find the unvisited nodes
            for (auto neighbor : g[node]) {
                if (!visited[neighbor]) {
                    // if neighbor not visited push in queue
                    q.push(neighbor);
                    visited[neighbor] = true;
                    // since following statements run just 1st time; they'll store the min distance from the src
                    dis[neighbor] = dis[node] + 1;
                    parent[neighbor] = node;
                }
            }
        }
        // after printing bfs traversal and storing the needed data, we can print each node's shortest distance from the source,
        // and also the shortest path from source to destination
        cout << endl;
        shortestDistancePrint(dis, parent, des, src);
    }

    // print the shortest distance of each node
    void shortestDistancePrint(map<T, int> dis, map<T, T> parents, T des, T src) {
        // each node's shortest path
        cout << "\nThe shortest distance of each vertex/node from src is:" << endl;
        for (auto node : g) {
            // for every node in graph
            cout << node.first << "->" << dis[node.first] << endl;
        }

        cout << endl;

        // now we need to find the path from source to the destination
        cout << "Shortest path is from inputted source and destination is:" << endl;
        T temp = des;
        while (temp != src) {
            cout << temp << "<-";
            temp = parents[temp];
        }
        cout << temp << endl;
    }
};

int main() {
    Graph<string> g;
    g.addEdge("Amritsar", "Delhi");
    g.addEdge("Amritsar", "Jaipur");
    g.addEdge("Delhi", "Siachen");
    g.addEdge("Delhi", "Bangalore");
    g.addEdge("Delhi", "Agra");
    g.addEdge("Amritsar", "Siachen");

    g.printList();

    cout << "\nThe bfs traversal of all the nodes in the Graph is:" << endl;
    g.bfs("Amritsar", "Bangalore");

    return 0;
}