// LEETCODE 1504. Count Submatrices With All Ones

// Given an m x n binary matrix mat, return the number of submatrices that have all ones.

// Example 1:


// Input: mat = [[1,0,1],[1,1,0],[1,1,0]]
// Output: 13
// Explanation: 
// There are 6 rectangles of side 1x1.
// There are 2 rectangles of side 1x2.
// There are 3 rectangles of side 2x1.
// There is 1 rectangle of side 2x2. 
// There is 1 rectangle of side 3x1.
// Total number of rectangles = 6 + 2 + 3 + 1 + 1 = 13.
// Example 2:


// Input: mat = [[0,1,1,0],[0,1,1,1],[1,1,1,0]]
// Output: 24
// Explanation: 
// There are 8 rectangles of side 1x1.
// There are 5 rectangles of side 1x2.
// There are 2 rectangles of side 1x3. 
// There are 4 rectangles of side 2x1.
// There are 2 rectangles of side 2x2. 
// There are 2 rectangles of side 3x1. 
// There is 1 rectangle of side 3x2. 
// Total number of rectangles = 8 + 5 + 2 + 4 + 2 + 2 + 1 = 24.
 

// Constraints:

// 1 <= m, n <= 150
// mat[i][j] is either 0 or 1.


// 🚀 Approach
// Build Histogram Heights:
    // For each row, maintain a height[] array where height[j] represents the number of consecutive ones ending at column j up to the current row. If** mat[i][j] == 0**, reset height[j] to 0.
// Count Submatrices Ending at Each Column:
    // For each column j in the current row:
        // Initialize minHt = height[j].
        // Move leftward from j to 0, updating minHt = min(minHt, height[k]).
        // Add minHt to the result res for each step. This counts all submatrices ending at (i, j) with width (j - k + 1) and height minHt.
// Accumulate Results:
    // Repeat the above for every row and accumulate the total count of valid submatrices.



class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size() , n = mat[0].size();
        int res = 0;
        vector<int> height(n , 0);
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) height[j] = 0;
                else height[j] += 1;
            }

            for (int j = 0; j < n; j++) {
                int minHt = height[j];
                for (int k = j; k >= 0 && minHt > 0; k--) {
                    minHt = min(minHt , height[k]);
                    res += minHt;
                }
            }
        }
        return res;
    }
};