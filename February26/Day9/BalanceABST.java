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









import java.util.*;

class Solution {
    // Perform inorder traversal to collect values in sorted order
    private void inorder(TreeNode root, List<Integer> list) {
        if (root == null) return;
        inorder(root.left, list);
        list.add(root.val);
        inorder(root.right, list);
    }

    // Construct balanced BST from sorted list
    private TreeNode constructBST(int l, int r, List<Integer> list) {
        if (l > r) return null;

        int mid = l + (r - l) / 2;
        TreeNode node = new TreeNode(list.get(mid));

        node.left = constructBST(l, mid - 1, list);
        node.right = constructBST(mid + 1, r, list);

        return node;
    }

    // Main function to balance BST
    public TreeNode balanceBST(TreeNode root) {
        List<Integer> list = new ArrayList<>();
        inorder(root, list);
        return constructBST(0, list.size() - 1, list);
    }
}