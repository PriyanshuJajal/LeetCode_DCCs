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
    long long totalSum = 0;
    long long maxProd = 0;
    static const int MOD = 1e9 + 7;

    long long getMaxSum(TreeNode* root) {
        if (!root) return 0;
        return root -> val + getMaxSum(root -> left) + getMaxSum(root -> right);
    }

    long long dfs(TreeNode* root) {
        if (!root) return 0;
        long long lSum = dfs(root -> left);
        long long rSum = dfs(root -> right);

        long long subTreeSum = root -> val + lSum + rSum;

        long long prod = subTreeSum * (totalSum - subTreeSum);
        maxProd = max(maxProd , prod);

        return subTreeSum;
    }

    int maxProduct(TreeNode* root) {
        totalSum = getMaxSum(root);
        dfs(root);
        return maxProd % MOD;
    }
};