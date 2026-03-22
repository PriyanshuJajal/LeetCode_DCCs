// LEETCODE 1886. Determine Whether Matrix Can Be Obtained By Rotation

// Given two n x n binary matrices mat and target, return true if it is possible to make mat equal to target by rotating mat in 90-degree increments, or false otherwise.

 

// Example 1:


// Input: mat = [[0,1],[1,0]], target = [[1,0],[0,1]]
// Output: true
// Explanation: We can rotate mat 90 degrees clockwise to make mat equal target.
// Example 2:


// Input: mat = [[0,1],[1,1]], target = [[1,0],[0,1]]
// Output: false
// Explanation: It is impossible to make mat equal to target by rotating mat.
// Example 3:


// Input: mat = [[0,0,0],[0,1,0],[1,1,1]], target = [[1,1,1],[0,1,0],[0,0,0]]
// Output: true
// Explanation: We can rotate mat 90 degrees clockwise two times to make mat equal target.
 

// Constraints:

// n == mat.length == target.length
// n == mat[i].length == target[i].length
// 1 <= n <= 10
// mat[i][j] and target[i][j] are either 0 or 1.


// 🚀 Approach
// Rotation logic:
//     First, transpose the matrix (swap mat[i][j] with mat[j][i]).
//     Then, reverse each row to achieve a 90° clockwise rotation.
// Comparison:
//     After each rotation, compare the current matrix with the target.
//     If they match, return true.
//     If none of the 4 rotations match, return false.
// Loop:
//     Perform up to 4 rotations (including the original matrix as rotation 0).
//     Break early if equality is found.

// 🕛 Complexity
// Time complexity: O(n²)
// Space complexity: O(1)









class Solution {
    int n;

    void rotate(int[][] mat) {
        // Transpose
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int temp = mat[i][j];
                mat[i][j] = mat[j][i];
                mat[j][i] = temp;
            }
        }

        // Reverse each row
        for (int i = 0; i < n; i++) {
            int left = 0, right = n - 1;
            while (left < right) {
                int temp = mat[i][left];
                mat[i][left] = mat[i][right];
                mat[i][right] = temp;
                left++;
                right--;
            }
        }
    }

    // Check if mat can be rotated to match target
    public boolean findRotation(int[][] mat, int[][] target) {
        n = mat.length;

        for (int r = 1; r <= 4; r++) {
            boolean isEqual = true;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (mat[i][j] != target[i][j]) {
                        isEqual = false;
                        break;
                    }
                }
                if (!isEqual) break;
            }
            if (isEqual) return true;

            rotate(mat);
        }
        return false;
    }
}