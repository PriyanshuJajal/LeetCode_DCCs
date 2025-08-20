// LEETCODE 1277. Count Square Submatrices with All Ones

// Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

// Example 1:

// Input: matrix =
// [
//   [0,1,1,1],
//   [1,1,1,1],
//   [0,1,1,1]
// ]
// Output: 15
// Explanation: 
// There are 10 squares of side 1.
// There are 4 squares of side 2.
// There is  1 square of side 3.
// Total number of squares = 10 + 4 + 1 = 15.
// Example 2:

// Input: matrix = 
// [
//   [1,0,1],
//   [1,1,0],
//   [1,1,0]
// ]
// Output: 7
// Explanation: 
// There are 6 squares of side 1.  
// There is 1 square of side 2. 
// Total number of squares = 6 + 1 = 7.
 

// Constraints:

// 1 <= arr.length <= 300
// 1 <= arr[0].length <= 300
// 0 <= arr[i][j] <= 1


// 🚀 Approach
// We iterate through each cell in the matrix. If the cell contains 1, and it's not on the first row or column, we update it to be:
//     1 + min(top, left, top-left)
// This represents the largest square that can end at that cell. We accumulate the value of each cell into a counter, since each cell contributes that many squares (e.g., a cell with value 3 contributes squares of size 1x1, 2x2, and 3x3).

// 🔧 In-place Optimization
// We reuse the input matrix to store DP values, saving space.

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size() , n = matrix[0].size();
        int cnt = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1 && i > 0 && j > 0) 
                    matrix[i][j] = 1 + min({matrix[i - 1][j] , matrix[i][j - 1] , matrix[i - 1][j - 1]});
                cnt += matrix[i][j];
            }
        }
        return cnt;
    }
};