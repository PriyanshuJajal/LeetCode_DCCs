// LEETCODE 1861. Rotating the Box

// You are given an m x n matrix of characters boxGrid representing a side-view of a box. Each cell of the box is one of the following:

// A stone '#'
// A stationary obstacle '*'
// Empty '.'
// The box is rotated 90 degrees clockwise, causing some of the stones to fall due to gravity. Each stone falls down until it lands on an obstacle, another stone, or the bottom of the box. Gravity does not affect the obstacles' positions, and the inertia from the box's rotation does not affect the stones' horizontal positions.

// It is guaranteed that each stone in boxGrid rests on an obstacle, another stone, or the bottom of the box.

// Return an n x m matrix representing the box after the rotation described above.

 

// Example 1:



// Input: boxGrid = [["#",".","#"]]
// Output: [["."],
//          ["#"],
//          ["#"]]
// Example 2:



// Input: boxGrid = [["#",".","*","."],
//               ["#","#","*","."]]
// Output: [["#","."],
//          ["#","#"],
//          ["*","*"],
//          [".","."]]
// Example 3:



// Input: boxGrid = [["#","#","*",".","*","."],
//               ["#","#","#","*",".","."],
//               ["#","#","#",".","#","."]]
// Output: [[".","#","#"],
//          [".","#","#"],
//          ["#","#","*"],
//          ["#","*","."],
//          ["#",".","*"],
//          ["#",".","."]]
 

// Constraints:

// m == boxGrid.length
// n == boxGrid[i].length
// 1 <= m, n <= 500
// boxGrid[i][j] is either '#', '*', or '.'.


// Approach
// 1. Rotate the box (90° clockwise)
//     First transpose the grid (res[i][j] = boxGrid[j][i]).
//     Then reverse each row to complete the rotation.
// 2. Apply gravity
//     For each column, track the lowest available empty cell (lastSpaceRow).
//     Traverse from bottom to top:
//         If a stone (#) is found, move it down to lastSpaceRow.
//         If an obstacle (*) is found, reset lastSpaceRow to just above it.
//     This simulates stones falling until they hit either an obstacle or the bottom.


// Time Complexity: O(m * n)
// Space Complexity: O(m * n)


class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();

        vector<vector<char>> res(n , vector<char>(m));

        // Transpose the grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res[i][j] = boxGrid[j][i];
            }
        }

        // Reverse every row
        for (vector<char>& row : res) {
            reverse(begin(row) , end(row));
        }

        // Applying gravity
        for (int j = 0; j < m; j++) {
            int lastSpaceRow = n - 1;
            for (int i = n - 1; i >= 0; i--) {
                if (res[i][j] == '*') {
                    lastSpaceRow = i - 1;
                    continue;
                }
                
                if (res[i][j] == '#') {
                    res[i][j] = '.';

                    res[lastSpaceRow][j] = '#';
                    lastSpaceRow--;
                }
            }
        }

        return res;
    }
};