// LEETCODE 3548. Equal Sum Grid Partition II

// You are given an m x n matrix grid of positive integers. Your task is to determine if it is possible to make either one horizontal or one vertical cut on the grid such that:

// Each of the two resulting sections formed by the cut is non-empty.
// The sum of elements in both sections is equal, or can be made equal by discounting at most one single cell in total (from either section).
// If a cell is discounted, the rest of the section must remain connected.
// Return true if such a partition exists; otherwise, return false.

// Note: A section is connected if every cell in it can be reached from any other cell by moving up, down, left, or right through other cells in the section.

 

// Example 1:

// Input: grid = [[1,4],[2,3]]

// Output: true

// Explanation:



// A horizontal cut after the first row gives sums 1 + 4 = 5 and 2 + 3 = 5, which are equal. Thus, the answer is true.
// Example 2:

// Input: grid = [[1,2],[3,4]]

// Output: true

// Explanation:



// A vertical cut after the first column gives sums 1 + 3 = 4 and 2 + 4 = 6.
// By discounting 2 from the right section (6 - 2 = 4), both sections have equal sums and remain connected. Thus, the answer is true.
// Example 3:

// Input: grid = [[1,2,4],[2,3,5]]

// Output: false

// Explanation:



// A horizontal cut after the first row gives 1 + 2 + 4 = 7 and 2 + 3 + 5 = 10.
// By discounting 3 from the bottom section (10 - 3 = 7), both sections have equal sums, but they do not remain connected as it splits the bottom section into two parts ([2] and [5]). Thus, the answer is false.
// Example 4:

// Input: grid = [[4,1,8],[3,2,6]]

// Output: false

// Explanation:

// No valid cut exists, so the answer is false.

 

// Constraints:

// 1 <= m == grid.length <= 105
// 1 <= n == grid[i].length <= 105
// 2 <= m * n <= 105
// 1 <= grid[i][j] <= 105


// 🚀 Approach
// Compute total sum of all elements in the grid.
// Horizontal cuts:
//     Iterate row by row, maintaining the cumulative sum (top).
//     Compute bottom = total - top.
//     If top == bottom, return true.
//     Additionally, check if the difference matches boundary elements or any previously seen element (stored in a set).
// Reverse the grid and repeat the horizontal check (to cover cuts from the other side).
// Vertical cuts:
//     Transpose the grid (swap rows and columns).
//     Apply the same horizontal cut logic on the transposed grid.
//     Reverse and check again.
// If none of the checks succeed, return false.

// 🕛 Complexity
// Time complexity: O(m * n)
// Space complexity: O(m * n)









class Solution {
public:
    typedef long long ll;
    ll total = 0;

    bool checkHorzCuts(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        unordered_set<ll> st;
        ll top = 0;
        
        for (int i = 0; i <= m - 2; i++) {
            for (int j = 0; j < n; j++) {
                st.insert(grid[i][j]);
                top += grid[i][j];
            }

            ll bottom = total - top;
            ll diff = top - bottom;

            if (diff == 0) return true;

            if (diff == (ll)grid[0][0]) return true;
            if (diff == (ll)grid[0][n - 1]) return true;
            if (diff == (ll)grid[i][0]) return true;

            if (i > 0 && n > 1 && st.count(diff)) return true;
        }
        return false;
    }

    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                total += grid[i][j];
            }
        }

        if (checkHorzCuts(grid)) return true;

        reverse(begin(grid) , end(grid));

        if (checkHorzCuts(grid)) return true;

        // For Vertical Cuts (Transpose & check same as above)
        reverse(begin(grid) , end(grid));

        vector<vector<int>> transpose(n , vector<int>(m));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                transpose[j][i] = grid[i][j];
            }
        }

        if (checkHorzCuts(transpose)) return true;

        reverse(begin(transpose) , end(transpose));

        if (checkHorzCuts(transpose)) return true;

        return false;
    }
};