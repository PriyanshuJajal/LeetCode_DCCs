// LEETCODE 1594. Maximum Non Negative Product in a Matrix

// You are given a m x n matrix grid. Initially, you are located at the top-left corner (0, 0), and in each step, you can only move right or down in the matrix.

// Among all possible paths starting from the top-left corner (0, 0) and ending in the bottom-right corner (m - 1, n - 1), find the path with the maximum non-negative product. The product of a path is the product of all integers in the grid cells visited along the path.

// Return the maximum non-negative product modulo 109 + 7. If the maximum product is negative, return -1.

// Notice that the modulo is performed after getting the maximum product.

 

// Example 1:


// Input: grid = [[-1,-2,-3],[-2,-3,-3],[-3,-3,-2]]
// Output: -1
// Explanation: It is not possible to get non-negative product in the path from (0, 0) to (2, 2), so return -1.
// Example 2:


// Input: grid = [[1,-2,1],[1,-2,1],[3,-4,1]]
// Output: 8
// Explanation: Maximum non-negative product is shown (1 * 1 * -2 * -4 * 1 = 8).
// Example 3:


// Input: grid = [[1,3],[0,-4]]
// Output: 0
// Explanation: Maximum non-negative product is shown (1 * 0 * -4 = 0).
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 15
// -4 <= grid[i][j] <= 4


// 🚀 Approach
// DP Tables:
//     Use two 2D arrays:
//     maxDP[i][j] → maximum product to reach cell (i, j)
//     minDP[i][j] → minimum product to reach cell (i, j)
// Initialization:
//     Start at (0,0) with maxDP[0][0] = minDP[0][0] = grid[0][0].
//     Fill the first row and first column directly since they have only one path.
// Transition:
//     For each cell (i, j):
//         Take the maximum and minimum from the top (i - 1 , j) and left (i , j - 1).
//         Multiply both with the current cell value.
//         Update maxDP[i][j] as the maximum of those products, and minDP[i][j] as the minimum.
//             maxDP[i][j] = max({val * maxDP[i - 1][j] , val * maxDP[i][j - 1], val * minDP[i - 1][j] , val * minDP[i][j - 1]});
//             minDP[i][j] = min({val * maxDP[i - 1][j] , val * maxDP[i][j-1], val * minDP[i - 1][j] , val * minDP[i][j - 1]});

// 🕛 Complexity
// Time complexity: O(m * n)
// Space complexity: O(m * n)









class Solution {
public:
    long long MOD = 1e9 + 7;
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<long long>> maxDP(m , vector<long long>(n , 0));
        vector<vector<long long>> minDP(m , vector<long long>(n , 0));

        maxDP[0][0] = minDP[0][0] = grid[0][0];

        for (int j = 1; j < n; j++) {
            maxDP[0][j] = minDP[0][j] = maxDP[0][j - 1] * grid[0][j];
        }

        for (int i = 1; i < m; i++) {
            maxDP[i][0] = minDP[i][0] = maxDP[i - 1][0] * grid[i][0];
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                long long val = grid[i][j];
                long long maxPrev = max(maxDP[i - 1][j] , maxDP[i][j - 1]);
                long long minPrev = min(minDP[i - 1][j] , minDP[i][j - 1]);

                maxDP[i][j] = max({val * maxPrev , val * minPrev});
                minDP[i][j] = min({val * maxPrev , val * minPrev});
            }
        }

        long long maxProd = maxDP[m - 1][n - 1];
        return maxProd < 0 ? -1 : maxProd % MOD;
    }
};