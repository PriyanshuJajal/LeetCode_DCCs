// LEETCODE 1582. Special Positions in a Binary Matrix

// Given an m x n binary matrix mat, return the number of special positions in mat.

// A position (i, j) is called special if mat[i][j] == 1 and all other elements in row i and column j are 0 (rows and columns are 0-indexed).

 

// Example 1:


// Input: mat = [[1,0,0],[0,0,1],[1,0,0]]
// Output: 1
// Explanation: (1, 2) is a special position because mat[1][2] == 1 and all other elements in row 1 and column 2 are 0.
// Example 2:


// Input: mat = [[1,0,0],[0,1,0],[0,0,1]]
// Output: 3
// Explanation: (0, 0), (1, 1) and (2, 2) are special positions.
 

// Constraints:

// m == mat.length
// n == mat[i].length
// 1 <= m, n <= 100
// mat[i][j] is either 0 or 1.


// 🚀 Approach
// Count 1s in each row and column
//     Use two arrays: rowCnt and colCnt to store the number of 1s in each row and column.
//     Traverse the matrix once, updating these counts.
// Check for special positions
//     Traverse the matrix again.
//     For each cell (r, c) where mat[r][c] == 1, check:
//         If rowCnt[r] == 1 and colCnt[c] == 1, then this position is special.
//     Increment the counter cnt for each special position found.
// Return the cnt having total number of special positions.

// 🕛 Complexity
// Time complexity: O(m * n)
// Space complexity: O(m + n)









class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int cnt = 0;

        vector<int> rowCnt(m , 0);
        vector<int> colCnt(n , 0);

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (mat[r][c] == 1) {
                    rowCnt[r]++;
                    colCnt[c]++;
                }
            }
        }

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (mat[r][c] == 0) continue;
                if (rowCnt[r] == 1 && colCnt[c] == 1) cnt++;
            }
        }
        return cnt;
    }
};