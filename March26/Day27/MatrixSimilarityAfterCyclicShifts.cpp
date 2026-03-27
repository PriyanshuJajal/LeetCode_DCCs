// LEETCODE 2946. Matrix Similarity After Cyclic Shifts

// You are given an m x n integer matrix mat and an integer k. The matrix rows are 0-indexed.

// The following proccess happens k times:

// Even-indexed rows (0, 2, 4, ...) are cyclically shifted to the left.


// Odd-indexed rows (1, 3, 5, ...) are cyclically shifted to the right.


// Return true if the final modified matrix after k steps is identical to the original matrix, and false otherwise.

 

// Example 1:

// Input: mat = [[1,2,3],[4,5,6],[7,8,9]], k = 4

// Output: false

// Explanation:

// In each step left shift is applied to rows 0 and 2 (even indices), and right shift to row 1 (odd index).



// Example 2:

// Input: mat = [[1,2,1,2],[5,5,5,5],[6,3,6,3]], k = 2

// Output: true

// Explanation:



// Example 3:

// Input: mat = [[2,2],[2,2]], k = 3

// Output: true

// Explanation:

// As all the values are equal in the matrix, even after performing cyclic shifts the matrix will remain the same.

 

// Constraints:

// 1 <= mat.length <= 25
// 1 <= mat[i].length <= 25
// 1 <= mat[i][j] <= 25
// 1 <= k <= 50


// 🚀 Approach
// Copy the original matrix for later comparison.
// Iterate through each row:
//     If the row index is even, perform a left rotation by k.
//     If the row index is odd, perform a right rotation by k.
// Use the reverse‑based rotation method to rotate in place without extra arrays.
// After all rotations, compare the modified matrix with the original copy.
// Return true if they match, otherwise false.

// 🕛 Complexity
// Time complexity: O(m * n)
// Space complexity: O(m * n)









class Solution {
public:
    void rotateLeft(vector<int>& row , int k) {
        int n = row.size();
        k %= n;

        reverse(begin(row) , begin(row) + k);
        reverse(begin(row) + k , end(row));
        reverse(begin(row) , end(row));
    }

    void rotateRight(vector<int>& row , int k) {
        int n = row.size();
        k %= n;
        
        reverse(begin(row) , end(row));
        reverse(begin(row) , begin(row) + k);
        reverse(begin(row) + k , end(row));
    }

    bool areSimilar(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat.size();
        vector<vector<int>> org = mat;

        for (int i = 0; i < m; i++) {
            if (i & 1) {
                rotateRight(mat[i] , k);
            }
            else rotateLeft(mat[i] , k);
        }

        return mat == org;
    }
};