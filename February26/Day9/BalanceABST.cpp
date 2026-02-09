// LEETCODE 1382. Balance a Binary Search Tree

// Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.

// A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.

 

// Example 1:


// Input: root = [1,null,2,null,3,null,4,null,null]
// Output: [2,1,3,null,null,null,4]
// Explanation: This is not the only correct answer, [3,1,4,null,2] is also correct.
// Example 2:


// Input: root = [2,1,3]
// Output: [2,1,3]
 

// Constraints:

// The number of nodes in the tree is in the range [1, 104].
// 1 <= Node.val <= 105


// 🚀 Approach
// Inorder Traversal
//     Perform an inorder traversal of the BST.
//     This gives us a sorted array of all node values.
// Construct Balanced BST
//     Use the sorted array to construct a balanced BST.
//     Pick the middle element as the root (to minimize height).
//     Recursively build the left subtree from the left half of the array and the right subtree from the right half.
// Return the New Root
//     The newly constructed tree will be height-balanced.

// 🕛 Complexity
// Time complexity: O(n)
// Space complexity: O(n)









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
    void inorder(TreeNode* root , vector<int>& v) {
        if (root == nullptr) return;

        inorder(root -> left , v);
        v.push_back(root -> val);
        inorder(root -> right , v);
    }

    TreeNode* constructBST(int l , int r , vector<int>& v) {
        if (l > r) return nullptr;

        int mid = l + (r - l) / 2;
        TreeNode* node = new TreeNode(v[mid]);

        node -> left = constructBST(l , mid - 1 , v);
        node -> right = constructBST(mid + 1 , r , v);

        return node;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> v;
        inorder(root , v);

        int l = 0;
        int r = v.size() - 1;

        return constructBST(l , r , v);
    }
};