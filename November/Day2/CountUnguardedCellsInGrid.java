// You are given two integers m and n representing a 0-indexed m x n grid. You are also given two 2D integer arrays guards and walls where guards[i] = [rowi, coli] and walls[j] = [rowj, colj] represent the positions of the ith guard and jth wall respectively.

// A guard can see every cell in the four cardinal directions (north, east, south, or west) starting from their position unless obstructed by a wall or another guard. A cell is guarded if there is at least one guard that can see it.

// Return the number of unoccupied cells that are not guarded.

 

// Example 1:


// Input: m = 4, n = 6, guards = [[0,0],[1,1],[2,3]], walls = [[0,1],[2,2],[1,4]]
// Output: 7
// Explanation: The guarded and unguarded cells are shown in red and green respectively in the above diagram.
// There are a total of 7 unguarded cells, so we return 7.
// Example 2:


// Input: m = 3, n = 3, guards = [[1,1]], walls = [[0,1],[1,0],[2,1],[1,2]]
// Output: 4
// Explanation: The unguarded cells are shown in green in the above diagram.
// There are a total of 4 unguarded cells, so we return 4.
 

// Constraints:

// 1 <= m, n <= 105
// 2 <= m * n <= 105
// 1 <= guards.length, walls.length <= 5 * 104
// 2 <= guards.length + walls.length <= m * n
// guards[i].length == walls[j].length == 2
// 0 <= rowi, rowj < m
// 0 <= coli, colj < n
// All the positions in guards and walls are unique.





// 🚀 Approach
// Initialize a grid of size m × n with all cells set to 0.
// I have marked guards with value 7 and walls with value 4 (you can mark anything you like).
// For each guard, simulate visibility in all four directions:
//     Stop marking if a wall (4) or another guard (7) is encountered.
//     Mark visible cells as 1.
// Count cells that remain 0 — these are unguarded and not blocked.


// 🕛 Complexity
// Time complexity: O(G * (m + n) + m * n)

// Marking guards & walls -> O(G + W)
// For each guard, scan in 4 directions.
// So, worst case -> O(m + n)
// So, total here -> O(G * (m + n))
// Final Count of Unguarded Cells -> O(m * n)

// Space complexity: O(m * n)









class Solution {
    public void markCellsAlongGuard(int row , int col , int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;

        for (int i = row - 1; i >= 0; i--) {
            if (grid[i][col] == 4 || grid[i][col] == 7) break;

            grid[i][col] = 1;
        }

        for (int i = row + 1; i < m; i++) {
            if (grid[i][col] == 4 || grid[i][col] == 7) break;

            grid[i][col] = 1;
        }

        for (int j = col - 1; j >= 0; j--) {
            if (grid[row][j] == 4 || grid[row][j] == 7) break;

            grid[row][j] = 1;
        }

        for (int j = col + 1; j < n; j++) {
            if (grid[row][j] == 4 || grid[row][j] == 7) break;

            grid[row][j] = 1;
        }
    }

    public int countUnguarded(int m, int n, int[][] guards, int[][] walls) {
        int[][] grid = new int[m][n];

        for (int[] vec : guards) {
            int i = vec[0];
            int j = vec[1];
            grid[i][j] = 7;
        }

        for (int[] vec : walls) {
            int i = vec[0];
            int j = vec[1];
            grid[i][j] = 4;
        }

        for (int[] guard : guards) {
            int i =guard[0];
            int j = guard[1];

            markCellsAlongGuard(i , j , grid);
        }

        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) cnt++;
            }
        }
        return cnt;
    }
}