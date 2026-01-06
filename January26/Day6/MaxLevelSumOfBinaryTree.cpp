// LEETCODE 1161. Maximum Level Sum of a Binary Tree

// Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.

// Return the smallest level x such that the sum of all the values of nodes at level x is maximal.

 

// Example 1:


// Input: root = [1,7,0,7,-8,null,null]
// Output: 2
// Explanation: 
// Level 1 sum = 1.
// Level 2 sum = 7 + 0 = 7.
// Level 3 sum = 7 + -8 = -1.
// So we return the level with the maximum sum which is level 2.
// Example 2:

// Input: root = [989,null,10250,98693,-89388,null,null,null,-32127]
// Output: 2
 

// Constraints:

// The number of nodes in the tree is in the range [1, 104].
// -105 <= Node.val <= 105




// 🚀 Approach
// Use a queue to perform BFS starting from the root.
// For each level:
//     Determine the number of nodes (n) at the current level.
//     Process all n nodes, summing their values.
//     Push their children into the queue for the next level.
// After computing the sum for a level, compare it with the maximum sum found so far.
//     If it’s greater, update maxSum and record the current level as resLevel.
// Continue until all levels are processed.
// Return the level with the maximum sum.

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
    int maxLevelSum(TreeNode* root) {
        int maxSum = INT_MIN;
        int resLevel = 0;
        int currLevel = 1;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            int n = q.size();
            int sum = 0;

            while(n--) {
                TreeNode* node = q.front();
                q.pop();

                sum += node -> val;

                if (node -> left) q.push(node -> left);
                if (node -> right) q.push(node -> right);
            }
            if (sum > maxSum) {
                maxSum = sum;
                resLevel = currLevel;
            }
            currLevel++;
        }
        return resLevel;
    }
};