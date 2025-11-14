// LEETOCODE 2536. Increment Submatrices by One

// You are given a positive integer n, indicating that we initially have an n x n 0-indexed integer matrix mat filled with zeroes.

// You are also given a 2D integer array query. For each query[i] = [row1i, col1i, row2i, col2i], you should do the following operation:

// Add 1 to every element in the submatrix with the top left corner (row1i, col1i) and the bottom right corner (row2i, col2i). That is, add 1 to mat[x][y] for all row1i <= x <= row2i and col1i <= y <= col2i.
// Return the matrix mat after performing every query.

 

// Example 1:


// Input: n = 3, queries = [[1,1,2,2],[0,0,1,1]]
// Output: [[1,1,0],[1,2,1],[0,1,1]]
// Explanation: The diagram above shows the initial matrix, the matrix after the first query, and the matrix after the second query.
// - In the first query, we add 1 to every element in the submatrix with the top left corner (1, 1) and bottom right corner (2, 2).
// - In the second query, we add 1 to every element in the submatrix with the top left corner (0, 0) and bottom right corner (1, 1).
// Example 2:


// Input: n = 2, queries = [[0,0,1,1]]
// Output: [[1,1],[1,1]]
// Explanation: The diagram above shows the initial matrix and the matrix after the first query.
// - In the first query we add 1 to every element in the matrix.
 

// Constraints:

// 1 <= n <= 500
// 1 <= queries.length <= 104
// 0 <= row1i <= row2i < n
// 0 <= col1i <= col2i < n




// 🚀 Approach
// Initialize a 2D difference array diff of size (n + 1) * (n + 1) to handle boundary overflow.
// Apply each query using 2D prefix sum logic:
// For each rectangle (r1, c1) to (r2, c2), update the four corners to reflect the change.
// Compute row-wise prefix sums to propagate horizontal changes.
// Compute column-wise prefix sums to propagate vertical changes.
// Trim the extra row and column to return a final n * n grid.


// 🕛 Complexity
// Time complexity: O(q + n²)
// Space complexity: O(n²)












class Solution {
    public int[][] rangeAddQueries(int n, int[][] queries) {
        int[][] diff = new int[n + 1][n + 1];
        for (int[] q : queries) {
            int r1 = q[0];
            int c1 = q[1];
            int r2 = q[2];
            int c2 = q[3];

            diff[r1][c1] += 1;
            diff[r1][c2 + 1] -= 1;
            diff[r2 + 1][c1] -= 1;
            diff[r2 + 1][c2 + 1] += 1;
        }

        for (int i = 0; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                diff[i][j] += diff[i][j - 1];
            }
        }

        for (int j = 0; j <= n; j++) {
            for (int i = 1; i <= n; i++) {
                diff[i][j] += diff[i - 1][j];
            }
        }

        int[][] res = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res[i][j] = diff[i][j];
            }
        }
        return res;
    }
}
