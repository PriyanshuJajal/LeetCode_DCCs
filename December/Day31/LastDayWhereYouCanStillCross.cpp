// LEETCODE 1970. Last Day Where You Can Still Cross

// There is a 1-based binary matrix where 0 represents land and 1 represents water. You are given integers row and col representing the number of rows and columns in the matrix, respectively.

// Initially on day 0, the entire matrix is land. However, each day a new cell becomes flooded with water. You are given a 1-based 2D array cells, where cells[i] = [ri, ci] represents that on the ith day, the cell on the rith row and cith column (1-based coordinates) will be covered with water (i.e., changed to 1).

// You want to find the last day that it is possible to walk from the top to the bottom by only walking on land cells. You can start from any cell in the top row and end at any cell in the bottom row. You can only travel in the four cardinal directions (left, right, up, and down).

// Return the last day where it is possible to walk from the top to the bottom by only walking on land cells.

 

// Example 1:


// Input: row = 2, col = 2, cells = [[1,1],[2,1],[1,2],[2,2]]
// Output: 2
// Explanation: The above image depicts how the matrix changes each day starting from day 0.
// The last day where it is possible to cross from top to bottom is on day 2.
// Example 2:


// Input: row = 2, col = 2, cells = [[1,1],[1,2],[2,1],[2,2]]
// Output: 1
// Explanation: The above image depicts how the matrix changes each day starting from day 0.
// The last day where it is possible to cross from top to bottom is on day 1.
// Example 3:


// Input: row = 3, col = 3, cells = [[1,2],[2,1],[3,3],[2,2],[1,1],[1,3],[2,3],[3,2],[3,1]]
// Output: 3
// Explanation: The above image depicts how the matrix changes each day starting from day 0.
// The last day where it is possible to cross from top to bottom is on day 3.
 

// Constraints:

// 2 <= row, col <= 2 * 104
// 4 <= row * col <= 2 * 104
// cells.length == row * col
// 1 <= ri <= row
// 1 <= ci <= col
// All the values of cells are unique.




// 🚀 Approach
// Binary Search on Days
//     Use binary search over the range of days [0 … n - 1] where n = cells.size().
//     For each mid-day, simulate flooding up to that day and check if crossing is possible.
// Grid Construction
//     For a given day mid, mark all cells flooded up to that day.
//     Represent flooded cells as 1 and unflooded as 0.
// DFS Traversal
//     Start DFS from every unflooded cell in the top row.
//     Try to reach the bottom row by moving in four directions (up, down, left, right).
//     If any path reaches the bottom, crossing is possible.
// If crossing is possible at mid, move search to the right (l = mid + 1) and update lastDay.
// Otherwise, move search to the left (h = mid - 1).
// The answer is the latest day (lastDay) when crossing is possible.

// 🕛 Complexity
// Time complexity: O((row * col) * logn)
// n = cells.size()
// Space complexity: O(row * col)










class Solution {
public:
    int ROW , COL;
    vector<vector<int>> dirs{{1 , 0} , {-1 , 0} , {0 , 1} , {0 , -1}};
    
    bool DFS(vector<vector<int>>& grid , int i , int j) {
        if (i < 0 || i >= ROW || j < 0 || j >= COL || grid[i][j] == 1) return false;

        if (i == ROW - 1) return true;
        grid[i][j] = 1;

        for (auto& dir : dirs) {
            int ni = i + dir[0];
            int nj = j + dir[1];

            if (DFS(grid , ni , nj)) return true;
        }
        return false;
    }

    bool canCross(vector<vector<int>>& cells , int mid) {
        vector<vector<int>> grid(ROW , vector<int>(COL , 0));

        for (int i = 0; i <= mid; i++) {
            int x = cells[i][0] - 1;
            int y = cells[i][1] - 1;

            grid[x][y] = 1;
        }

        for (int j = 0; j < COL; j++) {
            if (grid[0][j] == 0 && DFS(grid , 0 , j)) return true;
        }
        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        ROW = row;
        COL = col;

        int l = 0;
        int h = cells.size() - 1;
        int lastDay = 0;

        while(l <= h) {
            int mid = l + (h - l) / 2;
            if (canCross(cells , mid)) {
                lastDay = mid + 1;
                l = mid + 1;
            }
            else h = mid - 1;
        }
        return lastDay;
    }
};