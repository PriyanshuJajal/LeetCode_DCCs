// LEETCODE 1504. Count Submatrices With All Ones

// Given an m x n binary matrix mat, return the number of submatrices that have all ones.

// Example 1:


// Input: mat = [[1,0,1],[1,1,0],[1,1,0]]
// Output: 13
// Explanation: 
// There are 6 rectangles of side 1x1.
// There are 2 rectangles of side 1x2.
// There are 3 rectangles of side 2x1.
// There is 1 rectangle of side 2x2. 
// There is 1 rectangle of side 3x1.
// Total number of rectangles = 6 + 2 + 3 + 1 + 1 = 13.
// Example 2:


// Input: mat = [[0,1,1,0],[0,1,1,1],[1,1,1,0]]
// Output: 24
// Explanation: 
// There are 8 rectangles of side 1x1.
// There are 5 rectangles of side 1x2.
// There are 2 rectangles of side 1x3. 
// There are 4 rectangles of side 2x1.
// There are 2 rectangles of side 2x2. 
// There are 2 rectangles of side 3x1. 
// There is 1 rectangle of side 3x2. 
// Total number of rectangles = 8 + 5 + 2 + 4 + 2 + 2 + 1 = 24.
 

// Constraints:

// 1 <= m, n <= 150
// mat[i][j] is either 0 or 1.


// 🚀 Approach
// Preprocess Widths:
//     For each cell (i, j), compute width[i][j]: the number of consecutive ones ending at column j in row i.
//         If mat[i][j] == 1, then width[i][j] = width[i][j - 1] + 1 (or 1 if j == 0).
//         This gives the maximum possible width of a rectangle ending at (i, j).
// Count Submatrices Ending at Each Cell:
//     For each cell (i, j), look upward from row i to 0:
//         Track the minimum width encountered so far (minWidth).
//         Each time you move up a row, update minWidth = min(minWidth, width[k][j]).
//         Add minWidth to the result — this counts all submatrices ending at (i, j) with height (i - k + 1) and width minWidth.
// Accumulate Results: 
//     Repeat the above for every cell in the matrix and sum all contributions.


class Solution {
    public int numSubmat(int[][] mat) {
        int n = mat.length , m = mat[0].length;
        int[][] width = new int[n][m];
        int res = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1) width[i][j] = (j == 0 ? 0 : width[i][j - 1]) + 1;
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int minWidth = width[i][j];
                for (int k = i; k >= 0 && minWidth > 0; k--) {
                    minWidth = Math.min(minWidth , width[k][j]);
                    res += minWidth;
                }
            }
        }
        return res;
    }
}