// Travelling Salesman Problem
// Graph + Dynamic Programming
// Given a adj matrix representing a graph, a salesman starts from one city, need to travel all the cities and come back to the starting city in min cost.

// HAMILTONIAN CYCLE : Set of edges that cover every node and come back to the starting node.
// So basically, the TSP problem gives output the **min weight hamiltonian cycle**

// We will use Top Down DP :: Memorization and lil bit of bit masking!
// TC : recursion O(n-1!) but can be reduced using DP

#include<bits/stdc++.h>

using namespace std;

// global for ease but can be passed as well

// number of nodes/cities
int n = 4;
// memorization table
int memo[16][4];    // make this fixed size due to global scope. Actual size: [2^n][n]
// adj matrix
int dist[10][10] = {
        {0,  20, 42, 25},
        {20, 0,  30, 34},
        {42, 30, 0,  10},
        {25, 34, 10, 0}
};
// to let us know if all cities have been visited
int VISITED_ALL = (1 << n) - 1;

// main function : takes 2 parameters, the mask which lets us know which cities are visited and unvisited and a position that tells which city we are on now
int tsp(int mask, int pos) {
    // base case
    if (mask == VISITED_ALL) {
        return dist[pos][0];
    }
    // lookup
    if (memo[mask][pos] != -1) {
        return memo[mask][pos];
    }

    // recursive case
    int ans = INT_MAX;
    // try to go to an unvisited city
    for (int city = 0; city < n; city++) {
        if ((mask & (1 << city)) == 0) {
            // means the city is unvisited
            int newAns = dist[pos][city] + tsp(mask | (1 << city), city);
            ans = min(ans, newAns);
        }
    }
    return memo[mask][pos] = ans;
}

int main() {
    memset(memo, -1, sizeof(memo));
    cout << "Min Weight Hamiltonian Path costs "<<tsp(1, 0);

    return 0;
}