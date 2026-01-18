// LEETCODE 1895. Largest Magic Square

// A k x k magic square is a k x k grid filled with integers such that every row sum, every column sum, and both diagonal sums are all equal. The integers in the magic square do not have to be distinct. Every 1 x 1 grid is trivially a magic square.

// Given an m x n integer grid, return the size (i.e., the side length k) of the largest magic square that can be found within this grid.

 

// Example 1:


// Input: grid = [[7,1,4,5,6],[2,5,1,6,4],[1,5,4,3,2],[1,2,7,3,4]]
// Output: 3
// Explanation: The largest magic square has a size of 3.
// Every row sum, column sum, and diagonal sum of this magic square is equal to 12.
// - Row sums: 5+1+6 = 5+4+3 = 2+7+3 = 12
// - Column sums: 5+5+2 = 1+4+7 = 6+3+3 = 12
// - Diagonal sums: 5+4+3 = 6+4+2 = 12
// Example 2:


// Input: grid = [[5,1,3,1],[9,3,3,1],[1,3,3,8]]
// Output: 2
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 50
// 1 <= grid[i][j] <= 106


// 🚀 Approach
// Precompute prefix sums:
//     rowPrefSum[i][j]: sum of elements in row i from column 0 to j.
//     colPrefSum[i][j]: sum of elements in column j from row 0 to i.
// Iterate over possible square sizes:
//     Start from the largest possible side length (min(m , n)) down to 2.
//     For each top-left corner (i, j) of a candidate square:
//         Compute the sum of the first row in the square (targetSum).
//         Check all other rows using rowPrefSum.
//         Check all columns using colPrefSum.
//         Compute both diagonals directly.
//     If all sums match targetSum, return the side length immediately (largest found).
// If no larger square is found, return 1 (a single cell is trivially a magic square).

// 🕛 Complexity
// Time complexity: O(m * n * min(m , n))
// Space complexity: O(m * n)









class Solution {
    public int largestMagicSquare(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;

        int[][] rowPrefSum = new int[m][n];
        for (int i = 0; i < m; i++) {
            rowPrefSum[i][0] = grid[i][0];
            for (int j = 1; j < n; j++) {
                rowPrefSum[i][j] = rowPrefSum[i][j - 1] + grid[i][j];
            }
        }

        int[][] colPrefSum = new int[m][n];
        for (int j = 0; j < n; j++) {
            colPrefSum[0][j] = grid[0][j];
            for (int i = 1; i < m; i++) {
                colPrefSum[i][j] = colPrefSum[i - 1][j] + grid[i][j];
            }
        }

        for (int side = Math.min(m, n); side >= 2; side--) {
            for (int i = 0; i + side - 1 < m; i++) {
                for (int j = 0; j + side - 1 < n; j++) {

                    int targetSum = rowPrefSum[i][j + side - 1] - (j > 0 ? rowPrefSum[i][j - 1] : 0);
                    boolean allSumSame = true;

                    for (int r = i + 1; r < i + side; r++) {
                        int rowSum = rowPrefSum[r][j + side - 1] - (j > 0 ? rowPrefSum[r][j - 1] : 0);
                        if (rowSum != targetSum) {
                            allSumSame = false;
                            break;
                        }
                    }
                    if (!allSumSame) continue;

                    for (int c = j; c < j + side; c++) {
                        int colSum = colPrefSum[i + side - 1][c] - (i > 0 ? colPrefSum[i - 1][c] : 0);
                        if (colSum != targetSum) {
                            allSumSame = false;
                            break;
                        }
                    }
                    if (!allSumSame) continue;

                    int diagSum = 0, antiDiagSum = 0;
                    for (int k = 0; k < side; k++) {
                        diagSum += grid[i + k][j + k];
                        antiDiagSum += grid[i + k][j + side - 1 - k];
                    }

                    if (diagSum == targetSum && antiDiagSum == targetSum) {
                        return side;
                    }
                }
            }
        }

        return 1; 
    }
}