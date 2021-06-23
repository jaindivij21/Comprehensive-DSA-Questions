// Convert Sorted Array to Binary Search Tree :: Leetcode
// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

#include<bits/stdc++.h>

using namespace std;

// tree structure
class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    // constructors
    explicit TreeNode() : val(0), left(nullptr), right(nullptr) {}

    explicit TreeNode(int d) : val(d), left(nullptr), right(nullptr) {}

    TreeNode(int d, TreeNode *l, TreeNode *r) : val(d), left(l), right(r) {}
};

// main function :: resembles binary search
void addElements(vector<int> &nums, int l, int r, TreeNode *&root) {
    // if the left pointer exceeds right pointer, insert null in tree
    if (r >= l) {
        // cal the mid index
        int mid = l + (r - l) / 2;
        
        // insert the middle element into root
        root = new TreeNode(nums[mid]);

        // recusively call the left subtree and right subtree
        addElements(nums, l, mid - 1, root->left);
        addElements(nums, mid + 1, r, root->right);
    } else {
        root = nullptr;
    }
}

// simple question to build a binary search tree from a sorted array
TreeNode *sortedArrayToBST(vector<int> &nums) {
    // make the root node
    TreeNode *root = nullptr;
    
    // recursive function to add elements to the tree using the concept of binary search
    addElements(nums, 0, nums.size() - 1, root);
    
    // return ans
    return root;
}


int main() {
    TreeNode *root = nullptr;
    vector<int> v = {1, 2, 3};

    // build tree
    root = sortedArrayToBST(v);

    return 0;
}
