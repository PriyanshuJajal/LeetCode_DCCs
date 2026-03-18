// LEETCODE 3070. Count Submatrices with Top-Left Element and Sum Less Than k

// You are given a 0-indexed integer matrix grid and an integer k.

// Return the number of submatrices that contain the top-left element of the grid, and have a sum less than or equal to k.

 

// Example 1:


// Input: grid = [[7,6,3],[6,6,1]], k = 18
// Output: 4
// Explanation: There are only 4 submatrices, shown in the image above, that contain the top-left element of grid, and have a sum less than or equal to 18.
// Example 2:


// Input: grid = [[7,2,9],[1,5,0],[2,6,6]], k = 20
// Output: 6
// Explanation: There are only 6 submatrices, shown in the image above, that contain the top-left element of grid, and have a sum less than or equal to 20.
 

// Constraints:

// m == grid.length 
// n == grid[i].length
// 1 <= n, m <= 1000 
// 0 <= grid[i][j] <= 1000
// 1 <= k <= 109



// 🚀 Approach
// Prefix Sum Matrix Construction
//     For each cell (i, j), compute the sum of the submatrix from (0,0) to (i,j) using inclusion-exclusion:
//     grid[i][j] += (grid[i - 1][j] + grid[i][j - 1] - grid[i - 1][j - 1])
//     This allows constant-time retrieval of any submatrix sum later.
// Counting Submatrices
//     As you build the prefix sum matrix, check if the sum of the submatrix (0,0) to (i,j) is less than or equal to k.
//     If yes, increment the counter.
//     If not, break early since extending the submatrix further will only increase the sum.
// The counter cnt holds the number of valid submatrices.

// 🕛 Complexity
// Time complexity: O(m * n)
// Space complexity: O(1)









class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i - 1 >= 0 ) grid[i][j] += grid[i - 1][j];

                if (j - 1 >= 0) grid[i][j] += grid[i][j - 1];

                if (i - 1 >= 0 && j - 1 >= 0) grid[i][j] -= grid[i - 1][j - 1];

                if (grid[i][j] <= k) cnt++;
                else break;
            }
        }
        return cnt;
    }
};