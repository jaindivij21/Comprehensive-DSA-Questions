// Leetcode : Lexicographically Smallest String After Applying Operations
// https://leetcode.com/problems/lexicographically-smallest-string-after-applying-operations/

// Basic Concept would be to apply BFS on the starting string and traverse over all the possible strings. And at the end returning the lexicographically smallest/minimum string.
// DFS could have also been applied.

#include<bits/stdc++.h>

using namespace std;

// breadth first search :: iterative function
void bfs(string s, int a, int b, unordered_set<string> &visited, string &ans) {
    queue<string> q;    // queue for bfs traversal
    q.push(s);
    while (!q.empty()) {
        string curr = q.front();
        q.pop();    // retrieve the current element

        // if already visited
        if (visited.find(curr) != visited.end()) {
            continue;
        } else {
            // mark it visited
            visited.insert(curr);
            
            // store the minimum ans 
            if(curr < ans){
                ans = curr;
            }

            // add to queue its neighbors :: that is modified strings with 2 operations
            string m = curr, n;
            for (int i = 1; i < curr.size(); i += 2) {
                int x = curr[i] - '0';
                x = (x + a) % 10;
                m[i] = '0' + x;
            }
            n = curr.substr(curr.size() - b, b) + curr.substr(0, curr.size() - b);
            q.push(m);
            q.push(n);
        }
    }
}

// main function
string findLexSmallestString(string s, int a, int b) {
    // maintain a visited set that keeps track of visited string
    unordered_set<string> visited;
    string smallest = s; // minimum
    bfs(s, a, b, visited, smallest); // start a bfs call on the starting string
    return smallest;
}

int main() {
    string str;
    cin >> str;
    int a, b;
    cin >> a >> b;
    findLexSmallestString(str, a, b);
    return 0;
}