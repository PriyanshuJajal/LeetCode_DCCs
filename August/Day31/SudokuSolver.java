// LEETCODE 37. Sudoku Solver

// Write a program to solve a Sudoku puzzle by filling the empty cells.

// A sudoku solution must satisfy all of the following rules:

// Each of the digits 1-9 must occur exactly once in each row.
// Each of the digits 1-9 must occur exactly once in each column.
// Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
// The '.' character indicates empty cells.


// Example 1:


// Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
// Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
// Explanation: The input board is shown above and the only valid solution is shown below:


 

// Constraints:

// board.length == 9
// board[i].length == 9
// board[i][j] is a digit or '.'.
// It is guaranteed that the input board has only one solution.


// 🚀 Approach
// Recursive Backtracking:
//     Traverse the board cell by cell.
//     When an empty cell '.' is found, try placing digits '1' to '9'.
//     For each digit, check if it's safe to place using the isSafe function.
//     If safe, place the digit and recursively attempt to solve the rest of the board.
//     If the recursive call fails, backtrack by resetting the cell to '.'.
// Safety Check (isSafe):
//     Ensure the digit doesn't already exist in the current row, column, or 3 * 3 subgrid.  
// Termination:
//     If all cells are filled without conflict, the board is solved.



class Solution {
    public void solveSudoku(char[][] board) {
        sudokuSolver(board);
    }

    public boolean sudokuSolver(char[][] board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.') {
                    for (char num = '1'; num <= '9'; num++) {
                        if (isSafe(board , row , col , num)) {
                            board[row][col] = num;

                            if (sudokuSolver(board)) return true;

                            board[row][col] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    public boolean isSafe(char[][] board , int row , int col , int num) {
        for (int c = 0; c < 9; c++) {
            if (board[row][c] == num) return false;
        }
        for (int r = 0; r < 9; r++) {
            if (board[r][col] == num) return false;
        } 

        int boxRow = (row / 3) * 3 , boxCol = (col / 3) * 3;

        for (int r = 0; r < 3; r++) {
            for (int c = 0; c < 3; c++) {
                if (board[boxRow + r][boxCol + c] == num) return false;
            } 
        }
        return true;
    } 
}