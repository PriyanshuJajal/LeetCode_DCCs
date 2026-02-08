// LEETCODE 110. Balanced Binary Tree

// Given a binary tree, determine if it is height-balanced.

 

// Example 1:


// Input: root = [3,9,20,null,null,15,7]
// Output: true
// Example 2:


// Input: root = [1,2,2,3,3,null,null,4,4]
// Output: false
// Example 3:

// Input: root = []
// Output: true
 

// Constraints:

// The number of nodes in the tree is in the range [0, 5000].
// -104 <= Node.val <= 104



// 🚀 Approach
// Height function:
//     Recursively compute the height of a subtree.
//     Base case: if the node is nullptr, return 0.
//     Otherwise, return 1 + max(height(left) , height(right)).
// Balance check:
//     For each node, compute the height of its left and right subtrees.
//     If the absolute difference exceeds 1, return false.
//     Otherwise, recursively check if both subtrees are balanced.
// Recursive traversal:
//     The function isBalanced traverses the entire tree, ensuring the balance condition holds at every node.

// 🕛 Complexity
// Time complexity: O(n²)
// Space complexity: O(h) , h = height of tree









/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int height(TreeNode* root) {
        if (root == nullptr) return 0;
        return 1 + max(height(root -> left) , height(root -> right));
    }
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;

        int lHt = height(root -> left);
        int rHt = height(root -> right);

        if (abs(lHt - rHt) > 1) return false;

        return isBalanced(root -> left) && isBalanced(root -> right);
    }
};