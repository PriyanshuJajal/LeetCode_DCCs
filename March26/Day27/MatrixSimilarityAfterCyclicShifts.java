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









import java.util.*;

class Solution {
    private void rotateLeft(List<Integer> row, int k) {
        int n = row.size();
        k %= n;
        Collections.reverse(row.subList(0, k));
        Collections.reverse(row.subList(k, n));
        Collections.reverse(row);
    }

    private void rotateRight(List<Integer> row, int k) {
        int n = row.size();
        k %= n;
        Collections.reverse(row);
        Collections.reverse(row.subList(0, k));
        Collections.reverse(row.subList(k, n));
    }

    public boolean areSimilar(int[][] mat, int k) {
        int m = mat.length;
        int n = mat[0].length;

        int[][] org = new int[m][n];
        for (int i = 0; i < m; i++) {
            org[i] = Arrays.copyOf(mat[i], n);
        }

        // Convert each row to List<Integer> for easy reversal
        for (int i = 0; i < m; i++) {
            List<Integer> row = new ArrayList<>();
            for (int val : mat[i]) row.add(val);

            if (i % 2 == 0) {
                rotateLeft(row, k);
            } else {
                rotateRight(row, k);
            }

            // Copy back rotated row into matrix
            for (int j = 0; j < n; j++) {
                mat[i][j] = row.get(j);
            }
        }

        // Compare with original
        for (int i = 0; i < m; i++) {
            if (!Arrays.equals(mat[i], org[i])) return false;
        }
        return true;
    }
}