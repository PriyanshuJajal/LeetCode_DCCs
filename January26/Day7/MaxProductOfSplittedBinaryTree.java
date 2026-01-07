// LEETCODE 1339. Maximum Product of Splitted Binary Tree

// Given the root of a binary tree, split the binary tree into two subtrees by removing one edge such that the product of the sums of the subtrees is maximized.

// Return the maximum product of the sums of the two subtrees. Since the answer may be too large, return it modulo 109 + 7.

// Note that you need to maximize the answer before taking the mod and not after taking it.

 

// Example 1:


// Input: root = [1,2,3,4,5,6]
// Output: 110
// Explanation: Remove the red edge and get 2 binary trees with sum 11 and 10. Their product is 110 (11*10)
// Example 2:


// Input: root = [1,null,2,3,4,null,null,5,6]
// Output: 90
// Explanation: Remove the red edge and get 2 binary trees with sum 15 and 6.Their product is 90 (15*6)
 

// Constraints:

// The number of nodes in the tree is in the range [2, 5 * 104].
// 1 <= Node.val <= 104



// 🚀 Approach
// Compute total sum of the tree:
//     Perform a DFS traversal (getMaxSum) to calculate the sum of all nodes. This gives us totalSum.
// DFS to calculate subtree sums:
//     Traverse the tree again (dfs) to compute the sum of each subtree.
//     At each node, calculate subTreeSum = node -> val + leftSum + rightSum.
//     The product formed by splitting at this node is subTreeSum * (totalSum - subTreeSum).
//     Keep track of the maximum product encountered.
// Since the product can be very large, return the result modulo 10⁹ + 7.

// 🕛 Complexity
// Time complexity: O(n)

// Space complexity: O(h)
// h = height of tree (due to recursion stack)









/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private long totalSum = 0;
    private long maxProd = 0;
    private static final int MOD = 1_000_000_007;

    private long getMaxSum(TreeNode root) {
        if (root == null) return 0;
        return root.val + getMaxSum(root.left) + getMaxSum(root.right);
    }

    private long dfs(TreeNode root) {
        if (root == null) return 0;
        long lSum = dfs(root.left);
        long rSum = dfs(root.right);

        long subTreeSum = root.val + lSum + rSum;
        long prod = subTreeSum * (totalSum - subTreeSum);
        maxProd = Math.max(maxProd, prod);

        return subTreeSum;
    }

    public int maxProduct(TreeNode root) {
        totalSum = getMaxSum(root);
        dfs(root);
        return (int)(maxProd % MOD);
    }
}