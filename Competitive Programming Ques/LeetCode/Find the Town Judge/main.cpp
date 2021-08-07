// Leetcode : Find the Town Judge
// https://leetcode.com/problems/find-the-town-judge/

#include<bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *buildTree(TreeNode *root) {
    int ele;
    cin >> ele;

    if (ele == -1)
        return nullptr;
    else {
        auto *temp = new TreeNode(ele);
        temp->left = buildTree(temp->left);
        temp->right = buildTree(temp->right);
        return temp;
    }
}

// main soln
int findJudge(int n, vector<vector<int>> &trust) {
    // InDegree Array
    int in[n + 1];
    memset(in, 0, sizeof(in));  // fill the entire array with 0
    in[0] = -1;

    // OutDegree Array
    int out[n + 1];
    memset(out, 0, sizeof(out));    // fill the entire array with 0
    out[0] = -1;

    // traverse over all the edges and fill both the arrays
    for (auto i:trust) {
        in[i[1]]++;
        out[i[0]]++;
    }
    // find out the index and return it if it's outDegree is 0 and inDegree in n-1
    for (int i = 1; i <= n; i++) {
        if(out[i] == 0){
            // if out if 0, then check if it's inDegree is n-1
            if(in[i] == n-1){
                return i;
            }
        }
    }
    // else return -1
    return -1;
}

int main() {
    TreeNode *root = nullptr;
    root = buildTree(root);
    // cout<<findJudge();
    return 0;
}