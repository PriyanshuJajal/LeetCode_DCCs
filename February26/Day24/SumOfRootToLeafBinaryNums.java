// LEETCODE 1022. Sum of Root To Leaf Binary Numbers

// You are given the root of a binary tree where each node has a value 0 or 1. Each root-to-leaf path represents a binary number starting with the most significant bit.

// For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.
// For all leaves in the tree, consider the numbers represented by the path from the root to that leaf. Return the sum of these numbers.

// The test cases are generated so that the answer fits in a 32-bits integer.

 

// Example 1:


// Input: root = [1,0,1,0,1,0,1]
// Output: 22
// Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
// Example 2:

// Input: root = [0]
// Output: 0
 

// Constraints:

// The number of nodes in the tree is in the range [1, 1000].
// Node.val is 0 or 1.
 

// 🚀 Approach
// Start DFS from the root with an initial sum of 0.
// At each node:
//     Update the running sum: s = s * 2 + root -> val.
//     If the node is a leaf (root -> left == root -> right), return the current sum.
//     Otherwise, recursively call DFS on the left and right children, and return their sum.
// The helper function dfs accumulates the values, and sumRootToLeaf initiates the process.

// 🕛 Complexity
// Time complexity: O(n)
// Space complexity: O(h) , h = height of tree









// Definition for a binary tree node.
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {
        this.val = 0;
        this.left = null;
        this.right = null;
    }

    TreeNode(int x) {
        this.val = x;
        this.left = null;
        this.right = null;
    }

    TreeNode(int x, TreeNode left, TreeNode right) {
        this.val = x;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    private int dfs(TreeNode root, int s) {
        if (root == null) return 0;

        s = s * 2 + root.val;

        if (root.left == root.right) return s;

        return dfs(root.left, s) + dfs(root.right, s);
    }

    public int sumRootToLeaf(TreeNode root) {
        return dfs(root, 0);
    }
}