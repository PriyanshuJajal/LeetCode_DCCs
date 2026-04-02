// LEETCODE 3418. Maximum Amount of Money Robot Can Earn

// You are given an m x n grid. A robot starts at the top-left corner of the grid (0, 0) and wants to reach the bottom-right corner (m - 1, n - 1). The robot can move either right or down at any point in time.

// The grid contains a value coins[i][j] in each cell:

// If coins[i][j] >= 0, the robot gains that many coins.
// If coins[i][j] < 0, the robot encounters a robber, and the robber steals the absolute value of coins[i][j] coins.
// The robot has a special ability to neutralize robbers in at most 2 cells on its path, preventing them from stealing coins in those cells.

// Note: The robot's total coins can be negative.

// Return the maximum profit the robot can gain on the route.

 

// Example 1:

// Input: coins = [[0,1,-1],[1,-2,3],[2,-3,4]]

// Output: 8

// Explanation:

// An optimal path for maximum coins is:

// Start at (0, 0) with 0 coins (total coins = 0).
// Move to (0, 1), gaining 1 coin (total coins = 0 + 1 = 1).
// Move to (1, 1), where there's a robber stealing 2 coins. The robot uses one neutralization here, avoiding the robbery (total coins = 1).
// Move to (1, 2), gaining 3 coins (total coins = 1 + 3 = 4).
// Move to (2, 2), gaining 4 coins (total coins = 4 + 4 = 8).
// Example 2:

// Input: coins = [[10,10,10],[10,10,10]]

// Output: 40

// Explanation:

// An optimal path for maximum coins is:

// Start at (0, 0) with 10 coins (total coins = 10).
// Move to (0, 1), gaining 10 coins (total coins = 10 + 10 = 20).
// Move to (0, 2), gaining another 10 coins (total coins = 20 + 10 = 30).
// Move to (1, 2), gaining the final 10 coins (total coins = 30 + 10 = 40).
 

// Constraints:

// m == coins.length
// n == coins[i].length
// 1 <= m, n <= 500
// -1000 <= coins[i][j] <= 1000


// 🚀 Approach
// Use dynamic programming (DP) with a 3D state:
//     dp[i][j][k] = maximum coins collected at cell (i, j) having skipped at most k negatives (k ∈ {0,1,2}).
// Initialization:
//     At (0,0), if the starting coin is positive, take it. If negative, we can either take it or skip it (if skips are available).
// Transition:
//     From the left (i, j - 1) or from above (i - 1, j).
//     Case 1: Take the coin → add coins[i][j].
//     Case 2: Skip the coin (if negative and skips left) → add max(coins[i][j], 0) but consume one skip.
// Iterate row by row and column by column, updating all three states (k = 0 , 1 , 2).
// dp[m - 1][n - 1][2] stores the correct output (maximum coins at the destination with up to 2 skips used).

// 🕛 Complexity
// Time complexity: O(m * n)
// Space complexity: O(m * n)





class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size();
        int n = coins[0].size();

        vector<vector<vector<int>>> dp(m , vector<vector<int>>(n , vector<int>(3 , INT_MIN)));

        dp[0][0][0] = coins[0][0];
        for (int k = 1; k <= 2; k++) {
            dp[0][0][k] = max(coins[0][0] , 0);
        }

        for (int j = 1; j < n; j++) {
            dp[0][j][0] = dp[0][j - 1][0] + coins[0][j];

            for (int k = 1; k <= 2; k++) {
                dp[0][j][k] = max(dp[0][j - 1][k] + coins[0][j] , dp[0][j - 1][k - 1] + max(coins[0][j] , 0));
            }
        }

        for (int i = 1; i < m; i++) {
            dp[i][0][0] = dp[i - 1][0][0] + coins[i][0];

            for (int k = 1; k <= 2; k++) {
                dp[i][0][k] = max(dp[i - 1][0][k] + coins[i][0] , dp[i - 1][0][k - 1] + max(coins[i][0] , 0));
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j][0] = max(dp[i - 1][j][0] , dp[i][j - 1][0]) + coins[i][j];

                for (int k = 1; k <= 2; k++) {
                    dp[i][j][k] = max(max(dp[i - 1][j][k] , dp[i][j - 1][k]) + coins[i][j] , 
                                        max(dp[i - 1][j][k - 1] , dp[i][j - 1][k - 1])
                                    );
                }
            }
        }

        return dp[m - 1][n - 1][2];
    }
};