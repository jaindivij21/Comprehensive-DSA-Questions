// HOLI - Holiday Accomodation Problem

#include<bits/stdc++.h>

using namespace std;

// graph
class Graph {
    int V;
    list<pair<int, long long int>> *l;
public:
    // constructor
    Graph(int n) {
        V = n;
        l = new list<pair<int, long long int>>[V + 1];
    }

    // add edges
    void add_edge(int u, int v, long long int weight) {
        l[u].push_back(make_pair(v, weight));
        l[v].push_back(make_pair(u, weight));
    }

    // main recursive function
    int dfs_helper(int source, bool *visited, int *nodeCount, long long int &ans) {
        visited[source] = true;
        nodeCount[source] = 1;  // make visited true for the node and mark its nodeCount val as 1, will increment is as we recursively cal the nodes below it

        // for the source node, explore its nbrs
        for (auto itr:l[source]) {
            if (!visited[itr.first]) {
                // if not visited, update the value of node count depending upon what is returned by next recursive fx
                nodeCount[source] += dfs_helper(itr.first, visited, nodeCount, ans);
                // update ans value upon max value possible across this edge
                ans += 2 * min(nodeCount[itr.first], V - nodeCount[itr.first]) * itr.second;
            }
        }
        // return node count of the source node
        return nodeCount[source];
    }

    // dfs function
    void dfs() {
        bool *visited = new bool[V + 1]{false};
        int *nodeCount = new int[V + 1]{0};
        long long int ans = 0;
        dfs_helper(1, visited, nodeCount, ans);
        cout << ans << endl;
    }
};

// main function
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Graph g(n);
        while (n > 1) {
            n--;
            int i, j;
            long long int k;
            cin >> i >> j >> k;
            g.add_edge(i, j, k);
        }
        g.dfs();
    }
}