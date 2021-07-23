// Leetcode :: Pseudo-Palindromic Paths in a Binary Tree
// https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/

// More efficient method would be to use bitmasking or other method of using sets, add and delete the elements, if at the end the set contains more than one element then it means not a palindrome.
// TC: of Set Method: O(N) for tree traversal and O(logN) to add/delete elements to the set, therefore avg total TC: O(nlogn). Space Complexity : O(log N)  

// This following method has a time complexity : O(N)*no of leaf elements* O(LOGn) => O(nlogn)
// Space Complexity : O(logN)   // array

#include<bits/stdc++.h>

using namespace std;

// definition of a node
class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    // constructor
    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// building the tree : using BFS
TreeNode *buildTree(TreeNode *&root) {
    queue<TreeNode *> q;
    int element;
    cin >> element;
    root = new TreeNode(element);
    q.push(root);
    while (!q.empty()) {
        TreeNode *front = q.front();
        q.pop();
        int left, right;
        cin >> left >> right;
        if (left != -1) {
            front->left = new TreeNode(left);
            q.push(front->left);
        }
        if (right != -1) {
            front->right = new TreeNode(right);
            q.push(front->right);
        }
    }
    return root;
}

// print the tree : using BFS
void printTree(TreeNode *root) {
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            TreeNode *front = q.front();
            q.pop();
            cout << front->val << " ";
            if (front->left) {
                q.push(front->left);
            }
            if (front->right) {
                q.push(front->right);
            }
        }
        cout << endl;
    }
}

// For help

// void print(int arr[]) {
//     for (int i = 0; i < 10; i++)
//         cout << arr[i] << " ";
//     cout << endl;
// }

// check if the array is a palindrome
// funda is all the counts of numbers must either be even or we have one element that appeared once.
bool ifPalindrome(const int arr[]) {
    bool flag = false;
    // iterate through the array and check
    for (int i = 1; i < 10; i++) {
        if (arr[i] % 2 == 0)
            continue;
        if (flag && arr[i] % 2 != 0) {
            return false;
        }
        if (arr[i] % 2 != 0)
            flag = true;
    }
    return true;
}

// helper function : depth first traversal
void helper(TreeNode *root, int arr[], int &ans) {
    // base case
    if (root == nullptr)
        return;

    // recursive cases
    arr[root->val]++;   // increase the count 
    // recursive cases
    helper(root->left, arr, ans);
    helper(root->right, arr, ans);
    // check for palindrome at the leaf node
    if (root->left == nullptr && root->right == nullptr) {
        // leaf node
        // print(arr);
        if (ifPalindrome(arr))
            ans++;
    }
    // backtrack :: since arrays can't be passed by value (copy of an array) -> so we need to backtrack
    arr[root->val]--;
}

// the most easy task is to use counting sort since the ques says the digits range from 1-9;
int pseudoPalindromicPaths(TreeNode *root) {
    int ans = 0;
    // make an array and fill it with 0
    int arr[10];    // 0-9
    fill(arr, arr + 10, 0);
    arr[0] = -1;
    // dfs call recursive function
    helper(root, arr, ans);

    // return ans
    return ans;
}

int main() {
    TreeNode *root = nullptr;
    root = buildTree(root);
    printTree(root);

    cout << pseudoPalindromicPaths(root);

    return 0;
}