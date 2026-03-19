// LEETCODE 3212. Count Submatrices With Equal Frequency of X and Y

// Given a 2D character matrix grid, where grid[i][j] is either 'X', 'Y', or '.', return the number of submatrices that contain:

// grid[0][0]
// an equal frequency of 'X' and 'Y'.
// at least one 'X'.
 

// Example 1:

// Input: grid = [["X","Y","."],["Y",".","."]]

// Output: 3

// Explanation:



// Example 2:

// Input: grid = [["X","X"],["X","Y"]]

// Output: 0

// Explanation:

// No submatrix has an equal frequency of 'X' and 'Y'.

// Example 3:

// Input: grid = [[".","."],[".","."]]

// Output: 0

// Explanation:

// No submatrix has at least one 'X'.

 

// Constraints:

// 1 <= grid.length, grid[i].length <= 1000
// grid[i][j] is either 'X', 'Y', or '.'.



// 🚀 Approach
// Prefix Sum Construction
//     Build two 2D cumulative count arrays:
//         CntX[i][j]: number of Xs in the submatrix (0,0) → (i,j)
//         cumCntY[i][j]: number of Ys in the submatrix (0,0) → (i,j)
//     This is done using inclusion-exclusion:
//         Add counts from top and left.
//         Subtract overlap from top-left.
// Condition Check
//     At each cell (i,j), the prefix sums represent the count of X and Y in the submatrix from (0,0) to (i,j).
//     If cumCntX[i][j] == cumCntY[i][j] and greater than zero, increment the result counter.
// The final count is the number of valid submatrices satisfying the condition.

// 🕛 Complexity
// Time complexity: O(m * n)
// Space complexity: O(m * n)









class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> cumCntX(m , vector<int>(n , 0));
        vector<vector<int>> cumCntY(m , vector<int>(n , 0));

        int cnt = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cumCntX[i][j] = (grid[i][j] == 'X');
                cumCntY[i][j] = (grid[i][j] == 'Y');

                if (i - 1 >= 0){
                    cumCntX[i][j] += cumCntX[i - 1][j];
                    cumCntY[i][j] += cumCntY[i - 1][j];
                }

                if (j - 1 >= 0) {
                    cumCntX[i][j] += cumCntX[i][j - 1];
                    cumCntY[i][j] += cumCntY[i][j - 1];
                }

                if (i - 1 >= 0 && j - 1 >= 0) {
                    cumCntX[i][j] -= cumCntX[i - 1][j - 1];
                    cumCntY[i][j] -= cumCntY[i - 1][j - 1];
                }

                if (cumCntX[i][j] == cumCntY[i][j] && cumCntX[i][j] > 0) cnt++;
            }
        }
        return cnt;
    }
};