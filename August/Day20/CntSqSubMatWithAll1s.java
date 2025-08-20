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
// We use a dp matrix where dp[i][j] represents the size of the largest square ending at cell (i, j).
// Initialize the first row and column of dp based on the input matrix.
// For each cell (i, j) with value 1, compute:
//     dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])
// This ensures that only valid squares are counted.
// Finally, sum all values in dp to get the total number of square submatrices.



class Solution {
    public int countSquares(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;
        int[][] dp = new int[m][n];
        
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 1) dp[i][0] = 1;
        }
        for (int i = 0; i < n; i++) {
            if (matrix[0][i] == 1) dp[0][i] = 1;
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 1) {
                    int cnt = Math.min(
                        dp[i - 1][j],
                        Math.min(dp[i][j - 1], dp[i - 1][j - 1])
                    );
                    dp[i][j] = 1 + cnt;
                }
            }
        }
        int sum = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                sum += dp[i][j];
            }
        }
        return sum;
    }
}