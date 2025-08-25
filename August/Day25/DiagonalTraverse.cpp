// LEETCODE 498. Diagonal Traverse

// Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.
 

// Example 1:


// Input: mat = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,4,7,5,3,6,8,9]
// Example 2:

// Input: mat = [[1,2],[3,4]]
// Output: [1,2,3,4]
 

// Constraints:

// m == mat.length
// n == mat[i].length
// 1 <= m, n <= 104
// 1 <= m * n <= 104
// -105 <= mat[i][j] <= 105


// 🚀 Approach
// Start from the top-left corner (0, 0).
// Use a boolean flag upSide to track direction:
//     If true, move up-right: i--, j++.
//     If false, move down-left: i++, j--.
// Handle boundary conditions:
//     If moving up and hit the top row, move right.
//     If moving up and hit the last column, move down.
//     If moving down and hit the bottom row, move right.
//     If moving down and hit the first column, move down.
// Continue until all m * n elements are added to the result.



class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> res;
        int i = 0 , j = 0;
        bool upSide = true;

        while(res.size() < m * n) {
            res.push_back(mat[i][j]);
            if (upSide) {
                if (j == n - 1) {
                    i++;
                    upSide = false;
                }
                else if (i == 0) {
                    j++;
                    upSide = false;
                }
                else {
                    i--;
                    j++;
                }
            }
            else {
                if (i == m - 1) {
                    j++;
                    upSide = true;
                }
                else if (j == 0) {
                    i++;
                    upSide = true;
                }
                else {
                    i++;
                    j--;
                }
            }
        }
        return res;
    }
};