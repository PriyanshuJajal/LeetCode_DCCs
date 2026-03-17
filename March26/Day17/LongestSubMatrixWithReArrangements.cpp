// LEETCODE 1727. Largest Submatrix With Rearrangements

// You are given a binary matrix matrix of size m x n, and you are allowed to rearrange the columns of the matrix in any order.

// Return the area of the largest submatrix within matrix where every element of the submatrix is 1 after reordering the columns optimally.

 

// Example 1:


// Input: matrix = [[0,0,1],[1,1,1],[1,0,1]]
// Output: 4
// Explanation: You can rearrange the columns as shown above.
// The largest submatrix of 1s, in bold, has an area of 4.
// Example 2:


// Input: matrix = [[1,0,1,0,1]]
// Output: 3
// Explanation: You can rearrange the columns as shown above.
// The largest submatrix of 1s, in bold, has an area of 3.
// Example 3:

// Input: matrix = [[1,1,0],[1,0,1]]
// Output: 2
// Explanation: Notice that you must rearrange entire columns, and there is no way to make a submatrix of 1s larger than an area of 2.
 

// Constraints:

// m == matrix.length
// n == matrix[i].length
// 1 <= m * n <= 105
// matrix[i][j] is either 0 or 1.


// Time Complexity: O(m * n)
// Space Complexity: O(n)











class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int maxArea = 0;

        vector<pair<int , int>> prevHts;
        for (int r = 0; r < m; r++) {
            vector<pair<int , int>> currHts;
            vector<bool> vis(n , false);

            for (auto [ht , col] : prevHts) {
                if (matrix[r][col] == 1) {
                    currHts.push_back({ht + 1 , col});
                    vis[col] = true;
                }
            }

            for (int c = 0; c < n; c++) {
                if (vis[c] == false && matrix[r][c] == 1) {
                    currHts.push_back({1 , c});
                }
            }

            for (int i = 0; i < currHts.size(); i++) {
                int h = currHts[i].first;
                int b = i + 1;

                maxArea = max(maxArea , h * b);
            }

            prevHts = currHts;
        }

        return maxArea;
    }
};