// LEETCODE 2196. Create Binary Tree From Descriptions

// You are given a 2D integer array descriptions where descriptions[i] = [parenti, childi, isLefti] indicates that parenti is the parent of childi in a binary tree of unique values. Furthermore,

// If isLefti == 1, then childi is the left child of parenti.
// If isLefti == 0, then childi is the right child of parenti.
// Construct the binary tree described by descriptions and return its root.

// The test cases will be generated such that the binary tree is valid.

 

// Example 1:


// Input: descriptions = [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]
// Output: [50,20,80,15,17,19]
// Explanation: The root node is the node with value 50 since it has no parent.
// The resulting binary tree is shown in the diagram.
// Example 2:


// Input: descriptions = [[1,2,1],[2,3,0],[3,4,1]]
// Output: [1,2,null,null,3,4]
// Explanation: The root node is the node with value 1 since it has no parent.
// The resulting binary tree is shown in the diagram.
 

// Constraints:

// 1 <= descriptions.length <= 104
// descriptions[i].length == 3
// 1 <= parenti, childi <= 105
// 0 <= isLefti <= 1
// The binary tree described by descriptions is valid.


// 🚀 Approach
// Use a hash map (unordered_map<int, TreeNode*>) to store nodes by value. If a node doesn't exist yet, create it.
// For each description [parent, child, isLeft]:
//     Ensure both parent and child nodes exist in the map.
//     Attach the child to the parent's left or right pointer depending on isLeft.
// Maintain a set of all child nodes. This helps us later identify the root.
// Iterate through all descriptions again. The root is the parent that never appears in the child set.

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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int , TreeNode*> mp;
        unordered_set<int> childSet;

        for (vector<int>& desc : descriptions) {
            int parent = desc[0];
            int child = desc[1];
            int isLeft = desc[2];

            if (mp.find(parent) == mp.end()) {
                mp[parent] = new TreeNode(parent);
            }

            if (mp.find(child) == mp.end()) {
                mp[child] = new TreeNode(child);
            }

            if (isLeft == 1) {
                mp[parent] -> left = mp[child];
            }
            else {
                mp[parent] -> right = mp[child];
            }

            childSet.insert(child);
        }

        for (vector<int>& desc : descriptions) {
            int parent = desc[0];
            if (!childSet.count(parent)) {
                return mp[parent];
            }
        }

        return nullptr;
    }
};