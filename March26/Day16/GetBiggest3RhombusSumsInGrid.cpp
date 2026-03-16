// LEETCODE 1878. Get Biggest Three Rhombus Sums in a Grid

// You are given an m x n integer matrix grid​​​.

// A rhombus sum is the sum of the elements that form the border of a regular rhombus shape in grid​​​. The rhombus must have the shape of a square rotated 45 degrees with each of the corners centered in a grid cell. Below is an image of four valid rhombus shapes with the corresponding colored cells that should be included in each rhombus sum:


// Note that the rhombus can have an area of 0, which is depicted by the purple rhombus in the bottom right corner.

// Return the biggest three distinct rhombus sums in the grid in descending order. If there are less than three distinct values, return all of them.

 

// Example 1:


// Input: grid = [[3,4,5,1,3],[3,3,4,2,3],[20,30,200,40,10],[1,5,5,4,1],[4,3,2,2,5]]
// Output: [228,216,211]
// Explanation: The rhombus shapes for the three biggest distinct rhombus sums are depicted above.
// - Blue: 20 + 3 + 200 + 5 = 228
// - Red: 200 + 2 + 10 + 4 = 216
// - Green: 5 + 200 + 4 + 2 = 211
// Example 2:


// Input: grid = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [20,9,8]
// Explanation: The rhombus shapes for the three biggest distinct rhombus sums are depicted above.
// - Blue: 4 + 2 + 6 + 8 = 20
// - Red: 9 (area 0 rhombus in the bottom right corner)
// - Green: 8 (area 0 rhombus in the bottom middle)
// Example 3:

// Input: grid = [[7,7,7]]
// Output: [7]
// Explanation: All three possible rhombus sums are the same, so return [7].
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 50
// 1 <= grid[i][j] <= 105



// Time Complexity: O(m * n * min(m * n))
// Space Complexity: O(m * n)


class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        set<int> st;

        // Right diagonal...
        vector<vector<int>> d1(m , vector<int>(n , 0));

        // Left diagonal...
        vector<vector<int>> d2(m , vector<int>(n , 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                d1[i][j] = grid[i][j];
                if (i - 1 >= 0 && j - 1 >= 0) {
                    d1[i][j] += d1[i - 1][j - 1];
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                d2[i][j] = grid[i][j];
                if (i - 1 >= 0 && j + 1 < n) {
                    d2[i][j] += d2[i - 1][j + 1];
                }
            }
        }

        auto addSet = [&](int sum) {
            st.insert(sum);
            if (st.size() > 3) st.erase(begin(st));
        };

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                addSet(grid[r][c]); 

                for (int s = 1; r - s >= 0 && r + s < m && c - s >= 0 && c + s < n; s++) {
                    int sum = 0;

                    int topR = r - s;
                    int topC = c;

                    int rightR = r;
                    int rightC = c + s;

                    int bottomR = r + s;
                    int bottomC = c;

                    int leftR = r;
                    int leftC = c - s;

                    // Top To Right...
                    sum += d1[rightR][rightC];
                    if (topR - 1 >= 0 && topC - 1 >= 0) {
                        sum -= d1[topR - 1][topC - 1];
                    }

                    // Right To Bottom...
                    sum += d2[bottomR][bottomC];
                    if (rightR - 1 >= 0 && rightC + 1 < n) {
                        sum -= d2[rightR - 1][rightC + 1];
                    }

                    // Bottom To Left...
                    sum += d1[bottomR][bottomC];
                    if (leftR - 1 >= 0 && leftC - 1 >= 0) {
                        sum -= d1[leftR - 1][leftC - 1];
                    }

                    // Left To Top...
                    sum += d2[leftR][leftC];
                    if (topR - 1 >= 0 && topC + 1 < n) {
                        sum -= d2[topR - 1][topC + 1];
                    }

                    sum -= grid[topR][topC];
                    sum -= grid[rightR][rightC];
                    sum -= grid[bottomR][bottomC];
                    sum -= grid[leftR][leftC];

                    addSet(sum);
                }
            }
        }

        return vector<int>(rbegin(st) , rend(st));
    }
};