// LEETCODE 3195. Find the Minimum Area to Cover All Ones I

// You are given a 2D binary array grid. Find a rectangle with horizontal and vertical sides with the smallest area, such that all the 1's in grid lie inside this rectangle.

// Return the minimum possible area of the rectangle.


// Example 1:

// Input: grid = [[0,1,0],[1,0,1]]

// Output: 6

// Explanation:



// The smallest rectangle has a height of 2 and a width of 3, so it has an area of 2 * 3 = 6.

// Example 2:

// Input: grid = [[1,0],[0,0]]

// Output: 1

// Explanation:



// The smallest rectangle has both height and width 1, so its area is 1 * 1 = 1.


// Constraints:

// 1 <= grid.length, grid[i].length <= 1000
// grid[i][j] is either 0 or 1.
// The input is generated such that there is at least one 1 in grid.


// 🚀 Approach
// Traverse the entire grid.
// For every cell with value 1, update:
// row1: minimum row index
// row2: maximum row index
// col1: minimum column index
// col2: maximum column index
// After traversal, the rectangle spans from (row1, col1) to (row2, col2).
// Compute area using:
// Area = (row2 - row1 + 1) * (col2 - col1 + 1)


class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int col1 = INT_MAX , col2 = INT_MIN , row1 = INT_MAX , row2 = INT_MIN;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    row1 = min(row1 , i);
                    row2 = max(row2 , i);
                    col1 = min(col1 , j);
                    col2 = max(col2 , j);
                }
            }
        }
        return (row2 - row1 + 1) * (col2 - col1 + 1); 
    }
};