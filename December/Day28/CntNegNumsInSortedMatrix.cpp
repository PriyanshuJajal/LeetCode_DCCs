// LEETCODE 1351. Count Negative Numbers in a Sorted Matrix

// Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.

 

// Example 1:

// Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
// Output: 8
// Explanation: There are 8 negatives number in the matrix.
// Example 2:

// Input: grid = [[3,2],[1,0]]
// Output: 0
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 100
// -100 <= grid[i][j] <= 100
 

// Follow up: Could you find an O(n + m) solution?



// 🚀 Approach
// Start from the bottom-left corner of the matrix (i = m - 1, j = 0).
// If the current element grid[i][j] is negative, then all elements to the right in that row (n - j elements) are also negative.
//     Add that count to the answer.
//     Move one row up (i--) because we’ve already counted all negatives in this row.
//     If the current element is non-negative, move one column to the right (j++) to check smaller values.
// Continue until we either move past the top row (i < 0) or past the last column (j >= n).

// 🕛 Complexity
// Time complexity: O(m + n)
// Space complexity: O(1)









class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int i = m - 1 , j = 0;
        int cnt = 0;

        while(i >= 0 && j < n) {
            if (grid[i][j] < 0) {
                cnt += n - j;
                i--;
            }
            else j++;
        }

        return cnt;
    }
};