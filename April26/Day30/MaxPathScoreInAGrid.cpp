// LEETCODE 3742. Maximum Path Score in a Grid

// You are given an m x n grid where each cell contains one of the values 0, 1, or 2. You are also given an integer k.

// You start from the top-left corner (0, 0) and want to reach the bottom-right corner (m - 1, n - 1) by moving only right or down.

// Each cell contributes a specific score and incurs an associated cost, according to their cell values:

// 0: adds 0 to your score and costs 0.
// 1: adds 1 to your score and costs 1.
// 2: adds 2 to your score and costs 1. ​​​​​​​
// Return the maximum score achievable without exceeding a total cost of k, or -1 if no valid path exists.

// Note: If you reach the last cell but the total cost exceeds k, the path is invalid.

 

// Example 1:

// Input: grid = [[0, 1],[2, 0]], k = 1

// Output: 2

// Explanation:​​​​​​​

// The optimal path is:

// Cell	grid[i][j]	Score	Total
// Score	Cost	Total
// Cost
// (0, 0)	0	0	0	0	0
// (1, 0)	2	2	2	1	1
// (1, 1)	0	0	2	0	1
// Thus, the maximum possible score is 2.

// Example 2:

// Input: grid = [[0, 1],[1, 2]], k = 1

// Output: -1

// Explanation:

// There is no path that reaches cell (1, 1)​​​​​​​ without exceeding cost k. Thus, the answer is -1.

 

// Constraints:

// 1 <= m, n <= 200
// 0 <= k <= 103​​​​​​​
// ​​​​​​​grid[0][0] == 0
// 0 <= grid[i][j] <= 2



// 🚀 Approach
// Recursive DFS with state tracking
//     At each cell (i, j), we add its value to the path score.
//     We increment the count if the cell is positive.
//     If the count exceeds k, the path is invalid.
// Base cases
//     If we go out of bounds, return INT_MIN (invalid).
//     If we reach the bottom‑right cell, return its value (valid path).
// Memoization
//     State is defined by (i, j, cst) where cst is the number of positive cells used so far.
//     Store results in a 3D DP array memo[m][n][k + 1].
// Transition
//     Move down (i + 1 , j) or right (i , j + 1).
//     Take the maximum of both.
//     Add current cell’s value to the best result.
// Final result
//     If no valid path exists, return -1.
//     Otherwise, return the maximum score.

// 🕛 Complexity
// Time complexity: O(m * n * k)
// Space complexity: O(m * n * k)

class Solution {
public:
    int m , n;
    int solve(vector<vector<int>>& grid , int k , int i , int j , int cst , vector<vector<vector<int>>>& memo) {
        if (i >= m || j >= n) return INT_MIN;

        int newCst = cst + (grid[i][j] > 0);
        if (newCst > k) {
            return INT_MIN;
        }

        if (i == m - 1 && j == n - 1) {
            return grid[i][j];
        }

        if (memo[i][j][cst] != -1) {
            return memo[i][j][cst];
        }

        int down = solve(grid , k , i + 1 , j , newCst , memo);
        int right = solve(grid , k , i , j + 1 , newCst , memo);

        int best = max(right , down);

        if (best == INT_MIN) {
            return memo[i][j][cst] = INT_MIN;
        }

        return memo[i][j][cst] = grid[i][j] + best;
    } 

    int maxPathScore(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<vector<int>>> memo(m + 1 , vector<vector<int>>(n + 1 , vector<int>(k + 1 , -1)));

        int maxScore = solve(grid , k , 0 , 0 , 0 , memo);

        return maxScore == INT_MIN ? -1 : maxScore;
    }
};