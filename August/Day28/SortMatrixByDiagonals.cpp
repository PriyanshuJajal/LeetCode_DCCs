// LEETCODE 3446. Sort Matrix by Diagonals

// You are given an n x n square matrix of integers grid. Return the matrix such that:

// The diagonals in the bottom-left triangle (including the middle diagonal) are sorted in non-increasing order.
// The diagonals in the top-right triangle are sorted in non-decreasing order.
 

// Example 1:

// Input: grid = [[1,7,3],[9,8,2],[4,5,6]]

// Output: [[8,2,3],[9,6,7],[4,5,1]]

// Explanation:



// The diagonals with a black arrow (bottom-left triangle) should be sorted in non-increasing order:

// [1, 8, 6] becomes [8, 6, 1].
// [9, 5] and [4] remain unchanged.
// The diagonals with a blue arrow (top-right triangle) should be sorted in non-decreasing order:

// [7, 2] becomes [2, 7].
// [3] remains unchanged.
// Example 2:

// Input: grid = [[0,1],[1,2]]

// Output: [[2,1],[1,0]]

// Explanation:



// The diagonals with a black arrow must be non-increasing, so [0, 2] is changed to [2, 0]. The other diagonals are already in the correct order.

// Example 3:

// Input: grid = [[1]]

// Output: [[1]]

// Explanation:

// Diagonals with exactly one element are already in order, so no changes are needed.

 

// Constraints:

// grid.length == grid[i].length == n
// 1 <= n <= 10
// -105 <= grid[i][j] <= 105


// 🚀 Approach
// We use three nested loops:

// The outer loop (d) runs n times to ensure convergence, similar to bubble sort passes.
// The inner two loops iterate over all valid (i, j) pairs such that (i+1, j+1) is within bounds.
// Depending on whether the element is above or below the main diagonal, we apply the appropriate comparison and swap.
// This gradually pushes the diagonal elements into their desired order over multiple passes.




class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for (int d = 0; d < n; d++) {
            for (int i = 0; i < n - 1; i++) {
                for (int j = 0; j < n - 1; j++) {
                    if (j > i) {
                        if (grid[i][j] > grid[i + 1][j + 1]) swap(grid[i][j] , grid[i + 1][j + 1]);
                    }
                    else {
                        if (grid[i][j] < grid[i + 1][j + 1]) swap(grid[i][j] , grid[i + 1][j + 1]);
                    }
                }
            }
        }
        return grid;
    }
};