// LEETCODE 36. Valid Sudoku

// Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

// Each row must contain the digits 1-9 without repetition.
// Each column must contain the digits 1-9 without repetition.
// Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
// Note:

// A Sudoku board (partially filled) could be valid but is not necessarily solvable.
// Only the filled cells need to be validated according to the mentioned rules.
 

// Example 1:


// Input: board = 
// [["5","3",".",".","7",".",".",".","."]
// ,["6",".",".","1","9","5",".",".","."]
// ,[".","9","8",".",".",".",".","6","."]
// ,["8",".",".",".","6",".",".",".","3"]
// ,["4",".",".","8",".","3",".",".","1"]
// ,["7",".",".",".","2",".",".",".","6"]
// ,[".","6",".",".",".",".","2","8","."]
// ,[".",".",".","4","1","9",".",".","5"]
// ,[".",".",".",".","8",".",".","7","9"]]
// Output: true
// Example 2:

// Input: board = 
// [["8","3",".",".","7",".",".",".","."]
// ,["6",".",".","1","9","5",".",".","."]
// ,[".","9","8",".",".",".",".","6","."]
// ,["8",".",".",".","6",".",".",".","3"]
// ,["4",".",".","8",".","3",".",".","1"]
// ,["7",".",".",".","2",".",".",".","6"]
// ,[".","6",".",".",".",".","2","8","."]
// ,[".",".",".","4","1","9",".",".","5"]
// ,[".",".",".",".","8",".",".","7","9"]]
// Output: false
// Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
 

// Constraints:

// board.length == 9
// board[i].length == 9
// board[i][j] is a digit 1-9 or '.'.


// 🚀 Approach
// 1. We use three 2D boolean arrays:
//     rows[9][10] to track digits in each row
//     cols[9][10] to track digits in each column
//     boxes[9][10] to track digits in each 3 * 3 box
// 2. For each cell:
//     Skip if it's '.'(empty).
//     Convert the character digit to an integer using ch - '0'.
//     Compute the box index using (r / 3) * 3 + (c / 3).
//     If the digit has already appeared in the corresponding row, column, or box, return false.
// 3. Otherwise, mark it as seen in all three trackers.



class Solution {
    public boolean isValidSudoku(char[][] board) {
        boolean[][] rows = new boolean[9][10];
        boolean[][] cols = new boolean[9][10];
        boolean[][] boxes = new boolean[9][10];

        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                char ch = board[r][c];
                if (ch == '.') continue;
                if (Character.isDigit(ch)) {
                    int num = ch - '0';
                    if (rows[r][num]) return false;
                    if (cols[c][num]) return false;

                    int boxIdx = (r / 3) * 3 + (c / 3);
                    if (boxes[boxIdx][num]) return false;

                    rows[r][num] = true;
                    cols[c][num] = true;
                    boxes[boxIdx][num] = true;
                }
            }
        }
        return true;
    }
}