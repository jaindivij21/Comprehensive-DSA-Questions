// https://leetcode.com/problems/path-in-zigzag-labelled-binary-tree/
// https://leetcode.com/problems/path-in-zigzag-labelled-binary-tree/discuss/860872/C%2B%2B-O(logN)-Solution-Bottom-Up

#include<bits/stdc++.h>

using namespace std;

// class of node
class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    explicit TreeNode(int data) : val(data), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> pathInZigZagTree(int label) {

        vector<int>result;
        
        // depth of the given label
        int depth = log10(label)/log10(2);
        
        // Insert labels in the front of the vector from bottom to top
        while(depth>=0)
        {
            // insert current label in the front of vector 
            result.insert(result.begin(),label);
            
            // next label (parent label of current label) in non zizag tree: label/2
            // in zigzag tree we get label as: 
            // previous depth first element + (previous depth last element - next label in non zigzag tree)
            // previous depth first element : 2^ (depth-1)
            // previous depth last element : 2^ (depth) -1
            // next label in non zigzag tree : label/2
            label = (int)pow(2,depth-1) + (int)pow(2,depth) - 1 - label/2;
            depth--;
        }
        
        return result;
    }
};

// OR

vector<int> pathInZigZagTree(int label, int level = 0) {
  while (1 << level <= label) ++level;  // COUNT number of levels
  vector<int> res(level); // make a vector of size eql to the levels
  for(; label >= 1; label /= 2, --level) {  // loop: decrease level by one and 
    res[level - 1] = label;
    label = (1 << level) - 1 - label + (1 << (level - 1));
  }
  return res;
}
