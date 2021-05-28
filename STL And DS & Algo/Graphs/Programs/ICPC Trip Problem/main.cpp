// ICPC Trip Problem

#include<bits/stdc++.h>

using namespace std;

class graph {
    // stores src, list of (destination, train and flight price)
    map<string, list<pair<string, pair<int, int>>>> adjList;
    int ver;
    int edges;
public:
    // constructor
    graph() {

    }

    graph(int v, int e) {
        ver = v;
        edges = e;
    }

    // add edges
    void addEdges(string u, string v, int train, int flight, bool bidir = true) {
        adjList[u].push_back(make_pair(v, make_pair(train, flight)));
        if (bidir) {
            adjList[v].push_back(make_pair(u, make_pair(train, flight)));
        }
    }

    // print the list function
    void printList() {
        for (auto node: adjList) {
            cout << node.first << "->";
            for (auto neighbor: node.second) {
                cout << neighbor.first << ":" << neighbor.second.first << "," << neighbor.second.second << " ";
            }
            cout << endl;
        }
    }

    // algo that returns the single source shortest path from a src vertex to a destination vertex wrt to train costs
    map<string, int> dijkstra(string src) {
        // map that stores the distance from the source
        map<string, int> distances;

        // make all the distances as infinity except the src vertex
        for (auto node:adjList) {
            if (node.first == src)
                distances[node.first] = 0;
            else {
                distances[node.first] = INT_MAX;
            }
        }

        // now make a set that helps us extract the minimum edge and work on it
        set<pair<int, string>> s; // stores the train cost and the vertex :: it also keep them in ascending order

        // push initial src vertex into the set
        s.insert(make_pair(0, src));

        while (!s.empty()) {
            // extract the minimum weighted vertex and then explore its neighbors
            auto p = *(s.begin());
            string vertex = p.second;
            int cost = p.first;

            // mark it visited by popping it out of the set and then visit its neighbors
            s.erase(s.begin());

            // visit the neighbors
            for (auto nbr:adjList[vertex]) {
                // relaxation if possible
                if (distances[nbr.first] > cost + nbr.second.first) {
                    // means relaxation is possible and the neighbor node can be pushed into the set
                    // find if the set already has this node
                    auto f = s.find(make_pair(distances[nbr.first], nbr.first));
                    if (f != s.end()) {
                        // if yes then remove to update
                        s.erase(f);
                    }
                    // update the distance of nbr and add to the set
                    distances[nbr.first] = cost + nbr.second.first;
                    s.insert(make_pair(distances[nbr.first], nbr.first));
                }
            }
        }
        return distances;
    }

    void minCost(string src, string des) {
        map<string, int> disToX = dijkstra(src);
        map<string, int> disToY = dijkstra(des);

        int ans = INT_MAX;

        for (auto node: adjList) {
            for (auto nbr:node.second) {
                ans = min(ans, disToX[node.first] + disToY[nbr.first] + nbr.second.second);
            }
        }
        cout << "Minimum Cost to Travel is:" << min(ans, disToX[des]) << endl;

    }

};

graph takeInput() {
    int vertices, edges;
    cout << "Enter the number of vertices and edges" << endl;
    cin >> vertices >> edges;

    graph g(vertices, edges);

    cout << "Enter the src vertex, des vertex, train cost and flight cost";
    for (int i = 0; i < edges; i++) {
        string src, dest;
        int train, flight;
        cin >> src >> dest >> train >> flight;

        g.addEdges(src, dest, train, flight);
    }
    return g;
}

void printGraph(graph g) {
    g.printList();
}

void findAns(graph g) {
    g.minCost("Delhi", "Ambala");
}

int main() {
    graph g = takeInput();

    // printGraph(g);

    cout << endl;
    findAns(g);

    return 0;
}