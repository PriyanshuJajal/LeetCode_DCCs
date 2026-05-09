// LEETCODE 1914. Cyclically Rotating a Grid

// You are given an m x n integer matrix grid​​​, where m and n are both even integers, and an integer k.

// The matrix is composed of several layers, which is shown in the below image, where each color is its own layer:



// A cyclic rotation of the matrix is done by cyclically rotating each layer in the matrix. To cyclically rotate a layer once, each element in the layer will take the place of the adjacent element in the counter-clockwise direction. An example rotation is shown below:


// Return the matrix after applying k cyclic rotations to it.

 

// Example 1:


// Input: grid = [[40,10],[30,20]], k = 1
// Output: [[10,20],[40,30]]
// Explanation: The figures above represent the grid at every state.
// Example 2:


// Input: grid = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]], k = 2
// Output: [[3,4,8,12],[2,11,10,16],[1,7,6,15],[5,9,13,14]]
// Explanation: The figures above represent the grid at every state.
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 2 <= m, n <= 50
// Both m and n are even integers.
// 1 <= grid[i][j] <= 5000
// 1 <= k <= 109


// 🚀 Approach
// Compute the number of layers: layers = min(m , n) / 2.
// For each layer:
//     Extract elements in order (top row, right column, bottom row, left column).
//     Store them in a vector vals.
//     Perform cyclic rotation by k % vals.size().
//     Write rotated values back into the grid in the same traversal order.
// Return the modified grid.

// 🕛 Complexity
// Time complexity: O(m * n)
// Space complexity: O(m + n)



class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int layers = min(m , n) / 2;

        for (int l = 0; l < layers; l++) {
            vector<int> vals;

            int top = l;
            int left = l;
            int bottom = m - l - 1;
            int right = n - l - 1;

            // Top Row
            for (int j = left; j <= right; j++) {
                vals.push_back(grid[top][j]);
            }

            // Right Column
            for (int i = top + 1; i <= bottom - 1; i++) {
                vals.push_back(grid[i][right]);
            }

            // Bottom Row
            for (int j = right; j >= left; j--) {
                vals.push_back(grid[bottom][j]);
            }

            // Left Column
            for (int i = bottom - 1; i >= top + 1; i--) {
                vals.push_back(grid[i][left]);
            }

            int sz = vals.size();
            int st = k % sz;
            int idx = st;

            // Top Row
            for (int j = left; j <= right; j++) {
                grid[top][j] = vals[idx];
                idx++;

                if (idx == sz) idx = 0;
            }

            // Right Column
            for (int i = top + 1; i <= bottom - 1; i++) {
                grid[i][right] = vals[idx];
                idx++;

                if (idx == sz) idx = 0;
            }

            // Bottom Row
            for (int j = right; j >= left; j--) {
                grid[bottom][j] = vals[idx];
                idx++;

                if (idx == sz) idx = 0;
            }

            // Left Column
            for (int i = bottom - 1; i >= top + 1; i--) {
                grid[i][left] = vals[idx];
                idx++;

                if (idx == sz) idx = 0;
            }
        }
        return grid;
    }
};