// LEETOCDE 3546. Equal Sum Grid Partition I

// You are given an m x n matrix grid of positive integers. Your task is to determine if it is possible to make either one horizontal or one vertical cut on the grid such that:

// Each of the two resulting sections formed by the cut is non-empty.
// The sum of the elements in both sections is equal.
// Return true if such a partition exists; otherwise return false.

 

// Example 1:

// Input: grid = [[1,4],[2,3]]

// Output: true

// Explanation:



// A horizontal cut between row 0 and row 1 results in two non-empty sections, each with a sum of 5. Thus, the answer is true.

// Example 2:

// Input: grid = [[1,3],[2,4]]

// Output: false

// Explanation:

// No horizontal or vertical cut results in two non-empty sections with equal sums. Thus, the answer is false.

 

// Constraints:

// 1 <= m == grid.length <= 105
// 1 <= n == grid[i].length <= 105
// 2 <= m * n <= 105
// 1 <= grid[i][j] <= 105



// 🚀 Approach
// Calculate total sum of all elements in the grid.
// If the total sum is odd, return false.
// Compute cumulative sums row by row (excluding the last row).
//     If at any point the cumulative sum equals half of the total, return true.
// Compute cumulative sums column by column (excluding the last column).
//     If at any point the cumulative sum equals half of the total, return true.
// If neither condition is satisfied, return false.

// 🕛 Complexity
// Time complexity: O(m * n)
// Space complexity: O(1)









class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        long long total = 0;
        for (auto& row : grid) {
            for (int val : row) total += val;
        }        

        if (total & 1) return false;
        long long target = total / 2;

        long long rSum = 0;
        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n; j++) {
                rSum += grid[i][j];
            }
            if (rSum == target) return true;
        }

        long long cSum = 0;
        for (int j = 0; j < n - 1; j++) {
            for (int i = 0; i < m; i++) {
                cSum += grid[i][j];
            }
            if (cSum == target) return true;
        }
        return false;
    }
};