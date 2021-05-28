// Dijkstra (SSSP) Algorithm for Graphs
// TC: O(ElogV)

/*
 *  Single Source Shortest Path :: We already have discussed BFS for the same but Dijkstra is efficient and works on weighted graphs as well.
 *  Dijkstra basically is the algo to find shortest path between nodes in a graph. For a given source, the algo find the shortest path bw that
 *  node and all other nodes thus SSSP (Single Source Shortest Path) algorithm. It can also be used to find the shortest path from a single source node to
 *  single destination node by stopping the algorithm once that distance has been found.
 *      It works on the concept of relaxation, and makes use of priority queue/set to compute the result. It works on both directed and undirected graphs.
 *
 *  It DOESN'T WORK on -ve weights in the graph.
 */

// Easier implementationw ould be to make a for loop insert all nodes into pritority queue and pop one by one and explore and update theri neighbors 

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

    void dijsktraSSSP(T src, T des) {
        // make a map to store the current value of distances from the source node. Values are updated here after each relaxation.
        // This map will only store our final answer
        unordered_map<T, int> distances;

        // set all to infinity except to source
        for (auto node: adjList) {
            if (node.first == src)
                distances[node.first] = 0;
            else
                distances[node.first] = INT_MAX;
        }

        // make a set or priority queue (min heap) to find the node with minimum distance everytime
        // set that stores weights from source and nodesTo and the nodesTo
        set<pair<int, T>> s;

        // the map to store parents in order to print the path from src to the destination
        unordered_map<T, T> parent;

        // insert the first source node into the set
        s.insert(make_pair(0, src));

        // basically till the time all the nodes have been pushed and popped i.e. been visited
        while (!s.empty()) {
            // extract the node with minimum distance from the src node. Since set stores in ascending order, it'll be the first element
            auto p = *(s.begin());
            int dis = p.first;
            T node = p.second;

            // once we have the node extracted, we can pop it from the set
            s.erase(s.begin());

            // now find all the outgoing edges from the node and relax them and push them into the set
            for (auto neighbor : adjList[node]) {
                int oldDistance;
                if (distances[neighbor.first] > (dis + neighbor.second)) {

                    // IMPORTANT: we store this so as we need to use this to find the neighbor in the set; cuz in line below
                    // we update the distance for this neighbor, but the value isn't yet updated in the set
                    oldDistance = distances[neighbor.first];

                    // RELAXATION if possible, update the distance
                    distances[neighbor.first] = dis + neighbor.second;
                    parent[neighbor.first] = node;  // update the parent map too

                    // now push this neighbor into the set so that it's neighbors can be relaxed next
                    // we use the oldDistance to search this neighbor
                    auto f = s.find(make_pair(oldDistance, neighbor.first));
                    if (f != s.end()) {
                        // means the node already exists in the set thus needs its values to be updated (removed and added again)
                        // therefore remove it
                        s.erase(f);
                    }
                    // now add the neighbor node to the set
                    s.insert(make_pair(distances[neighbor.first], neighbor.first));
                }
            }
        }
        // Print distance to all other node from src
        for (auto d:distances) {
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
    g.addEdges(1, 2, 1);
    g.addEdges(1, 3, 4);
    g.addEdges(2, 3, 1);
    g.addEdges(3, 4, 2);
    g.addEdges(1, 4, 7);

    g.printList();

    g.dijsktraSSSP(1, 4);

    return 0;
}