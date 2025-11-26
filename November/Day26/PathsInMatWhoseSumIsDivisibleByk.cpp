// LEETCODE 2435. Paths in Matrix Whose Sum Is Divisible by K

// You are given a 0-indexed m x n integer matrix grid and an integer k. You are currently at position (0, 0) and you want to reach position (m - 1, n - 1) moving only down or right.

// Return the number of paths where the sum of the elements on the path is divisible by k. Since the answer may be very large, return it modulo 109 + 7.

 

// Example 1:


// Input: grid = [[5,2,4],[3,0,5],[0,7,2]], k = 3
// Output: 2
// Explanation: There are two paths where the sum of the elements on the path is divisible by k.
// The first path highlighted in red has a sum of 5 + 2 + 4 + 5 + 2 = 18 which is divisible by 3.
// The second path highlighted in blue has a sum of 5 + 3 + 0 + 5 + 2 = 15 which is divisible by 3.
// Example 2:


// Input: grid = [[0,0]], k = 5
// Output: 1
// Explanation: The path highlighted in red has a sum of 0 + 0 = 0 which is divisible by 5.
// Example 3:


// Input: grid = [[7,3,4,9],[2,3,6,2],[2,3,7,0]], k = 1
// Output: 10
// Explanation: Every integer is divisible by 1 so the sum of the elements on every possible path is divisible by k.
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 5 * 104
// 1 <= m * n <= 5 * 104
// 0 <= grid[i][j] <= 100
// 1 <= k <= 50



// 🚀 Approach
// Define a DP state: dp[i][j][r] = number of ways to reach cell (i, j) with path sum remainder r modulo k.
// Initialize: At (0,0), the remainder is grid[0][0] % k, so set dp[0][0][grid[0][0] % k] = 1.
// Transition:
//     From (i,j) with remainder r, moving down to (i + 1 , j) adds grid[i + 1][j]. The new remainder is (r + grid[i + 1][j]) % k.
//     Similarly, moving right to (i , j + 1) adds grid[i][j + 1]. The new remainder is (r + grid[i][j + 1]) % k.
//     Update the counts accordingly, always taking modulo 1e9+7.
// Iterate over the grid, updating states.
// The answer is dp[m - 1][n - 1][0], i.e., number of ways to reach the bottom-right with remainder 0 (sum divisible by k).


// 🕛 Complexity
// Time complexity: O(m * n * k)
// Space complexity: O(m * n * k)













class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int mod = 1e9 + 7;

        vector<vector<vector<int>>> dp(m , vector<vector<int>>(n , vector<int>(k , 0)));
        dp[0][0][grid[0][0] % k] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int r = 0; r < k; r++) {
                    if (dp[i][j][r] == 0) continue;

                    if (i + 1 < m) {
                        int nxtVal = grid[i + 1][j];
                        int nxtRem = (r + nxtVal) % k;
                        dp[i + 1][j][nxtRem] = (dp[i + 1][j][nxtRem] + dp[i][j][r]) % mod;
                    }

                    if (j + 1 < n) {
                        int nxtVal = grid[i][j + 1];
                        int nxtRem = (r + nxtVal) % k;
                        dp[i][j + 1][nxtRem] = (dp[i][j + 1][nxtRem] + dp[i][j][r]) % mod;
                    }
                }
            }
        }
        return dp[m - 1][n - 1][0];
    }
};

