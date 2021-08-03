// Find Center of Star Graph
// Leetocode : https://leetcode.com/problems/find-center-of-star-graph/

// Graph Question -> here uses adjacency list

#include<bits/stdc++.h>

using namespace std;

// Concept: In all graph ques it isn't necessary to make a graph to solve the ques, you can solve it just by using
// the given information also or just the edge list without turning it into an adj matrix or adj list.

// EASY CONCEPT
int findCenter2(vector<vector<int>> &edges) {
    int x = edges[0][0];
    int y = edges[0][1];

    if (edges[1][0] == x || edges[1][1] == x)
        return x;
    else
        return y;
}

// In this ques, we can solve this by just calculating the in-degree of each node :: DIFFICULT CONCEPT
int findCenter(vector<vector<int>> &edges) {
    map<int, int> inDegree;
    for (auto i: edges) {
        if (inDegree.find(i[0]) == inDegree.end()) {
            // vertex not found
            inDegree[i[0]] = 1;
        } else {
            inDegree[i[0]]++;
        }
        if (inDegree.find(i[1]) == inDegree.end())
            inDegree[i[1]] = 1;
        else
            inDegree[i[1]]++;
    }
    int ans;
    for (auto i: inDegree) {
        if (i.second == inDegree.size() - 1) {
            ans = i.first;
            break;
        }
    }
    for (auto i : inDegree) {
        cout << i.first << " " << i.second << endl;
    }
    return ans;
}


int main() {

    // Edge List
    vector<vector<int>> edges;
    edges.push_back({1, 2});
    edges.push_back({2, 3});
    edges.push_back({4, 2});
    findCenter(edges);

    return 0;
}