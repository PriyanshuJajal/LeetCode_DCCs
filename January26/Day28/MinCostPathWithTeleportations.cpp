// LEETCODE 3651. Minimum Cost Path with Teleportations

// You are given a m x n 2D integer array grid and an integer k. You start at the top-left cell (0, 0) and your goal is to reach the bottom‐right cell (m - 1, n - 1).

// There are two types of moves available:

// Normal move: You can move right or down from your current cell (i, j), i.e. you can move to (i, j + 1) (right) or (i + 1, j) (down). The cost is the value of the destination cell.

// Teleportation: You can teleport from any cell (i, j), to any cell (x, y) such that grid[x][y] <= grid[i][j]; the cost of this move is 0. You may teleport at most k times.

// Return the minimum total cost to reach cell (m - 1, n - 1) from (0, 0).

 

// Example 1:

// Input: grid = [[1,3,3],[2,5,4],[4,3,5]], k = 2

// Output: 7

// Explanation:

// Initially we are at (0, 0) and cost is 0.

// Current Position	Move	New Position	Total Cost
// (0, 0)	Move Down	(1, 0)	0 + 2 = 2
// (1, 0)	Move Right	(1, 1)	2 + 5 = 7
// (1, 1)	Teleport to (2, 2)	(2, 2)	7 + 0 = 7
// The minimum cost to reach bottom-right cell is 7.

// Example 2:

// Input: grid = [[1,2],[2,3],[3,4]], k = 1

// Output: 9

// Explanation:

// Initially we are at (0, 0) and cost is 0.

// Current Position	Move	New Position	Total Cost
// (0, 0)	Move Down	(1, 0)	0 + 2 = 2
// (1, 0)	Move Right	(1, 1)	2 + 3 = 5
// (1, 1)	Move Down	(2, 1)	5 + 4 = 9
// The minimum cost to reach bottom-right cell is 9.


// Constraints:

// 2 <= m, n <= 80
// m == grid.length
// n == grid[i].length
// 0 <= grid[i][j] <= 104
// 0 <= k <= 10



// 🚀 Approach
// Sorting cells by value:
//     We sort all cells by their grid values. This helps us group cells with equal values and efficiently propagate teleportation costs.
// Cost matrix:
//     Maintain a costs matrix where costs[i][j] represents the minimum cost to reach the destination (m - 1 , n - 1) from cell (i ,j) under the current teleportation allowance.
// Iterative relaxation (up to k times):
//     For each teleportation allowance t from 0 to k:
//     Propagate the minimum cost among cells of equal value (this simulates teleportation).
//     Then, traverse the grid backward (from bottom‑right to top‑left) to update costs using normal moves (down and right).
//     This ensures both teleportation and normal moves are considered.
// After processing up to k teleportations, the minimum cost to reach (m - 1 ,n - 1) from (0 , 0) is stored in costs[0][0].

// 🕛 Complexity
// Time complexity: O((k + log(m * n)) * m * n)
// Space complexity: O(m * n)









class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<pair<int , int>> pts;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                pts.push_back({i , j});
            }
        }

        sort(begin(pts) , end(pts) , [&](const auto& p1 , const auto& p2) -> bool {
            return grid[p1.first][p1.second] < grid[p2.first][p2.second];
        });

        vector<vector<int>> costs(m , vector<int>(n , INT_MAX));
        for (int t = 0; t <= k; t++) {
            int minCst = INT_MAX;
            for (int i = 0 , j = 0; i < pts.size(); i++) {
                minCst = min(minCst , costs[pts[i].first][pts[i].second]);

                if (i + 1 < pts.size() && 
                    grid[pts[i].first][pts[i].second] == grid[pts[i + 1].first][pts[i + 1].second]
                ) continue;

                for (int r = j; r <= i; r++) {
                    costs[pts[r].first][pts[r].second] = minCst;
                }
                
                j = i + 1;
            }

            for (int i = m - 1; i >= 0; i--) {
                for (int j = n - 1; j >= 0; j--) {
                    if (i == m - 1 && j == n - 1) {
                        costs[i][j] = 0;
                        continue;
                    }

                    if (i != m - 1) {
                        costs[i][j] = min(costs[i][j] , costs[i + 1][j] + grid[i + 1][j]);
                    }

                    if (j != n - 1) {
                        costs[i][j] = min(costs[i][j] , costs[i][j + 1] + grid[i][j + 1]);
                    }
                }
            }
        }
        return costs[0][0];
    }
};