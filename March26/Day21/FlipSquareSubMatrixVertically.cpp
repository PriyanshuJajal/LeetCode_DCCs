// LEETCODE 3643. Flip Square Submatrix Vertically

// You are given an m x n integer matrix grid, and three integers x, y, and k.

// The integers x and y represent the row and column indices of the top-left corner of a square submatrix and the integer k represents the size (side length) of the square submatrix.

// Your task is to flip the submatrix by reversing the order of its rows vertically.

// Return the updated matrix.

 

// Example 1:


// Input: grid = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]], x = 1, y = 0, k = 3

// Output: [[1,2,3,4],[13,14,15,8],[9,10,11,12],[5,6,7,16]]

// Explanation:

// The diagram above shows the grid before and after the transformation.

// Example 2:

// ​​​​​​​
// Input: grid = [[3,4,2,3],[2,3,4,2]], x = 0, y = 2, k = 2

// Output: [[3,4,4,2],[2,3,2,3]]

// Explanation:

// The diagram above shows the grid before and after the transformation.

 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 50
// 1 <= grid[i][j] <= 100
// 0 <= x < m
// 0 <= y < n
// 1 <= k <= min(m - x, n - y)


// 🚀 Approach
// Start with two pointers:
//     i at the top row of the submatrix (x)
//     i1 at the bottom row of the submatrix (x + k - 1)
// While i < i1, swap the rows element by element:
//     Iterate over each column index j from y to y + k - 1.
//     Swap grid[i][j] with grid[i1][j].
// Move i downward and i1 upward until they meet.
// Return the modified grid.

// 🕛 Complexity
// Time complexity: O(k²)
// Space complexity: O(1)









class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        for (int i = x , i1 = x + k - 1; i < i1; i++ , i1--) {
            for (int j = y; j < y + k; j++) {
                swap(grid[i][j] , grid[i1][j]);
            }
        }
        return grid;
    }
};