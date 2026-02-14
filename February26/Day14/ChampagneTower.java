// LEETCODE 799. Champagne Tower

// We stack glasses in a pyramid, where the first row has 1 glass, the second row has 2 glasses, and so on until the 100th row.  Each glass holds one cup of champagne.

// Then, some champagne is poured into the first glass at the top.  When the topmost glass is full, any excess liquid poured will fall equally to the glass immediately to the left and right of it.  When those glasses become full, any excess champagne will fall equally to the left and right of those glasses, and so on.  (A glass at the bottom row has its excess champagne fall on the floor.)

// For example, after one cup of champagne is poured, the top most glass is full.  After two cups of champagne are poured, the two glasses on the second row are half full.  After three cups of champagne are poured, those two cups become full - there are 3 full glasses total now.  After four cups of champagne are poured, the third row has the middle glass half full, and the two outside glasses are a quarter full, as pictured below.



// Now after pouring some non-negative integer cups of champagne, return how full the jth glass in the ith row is (both i and j are 0-indexed.)

 

// Example 1:

// Input: poured = 1, query_row = 1, query_glass = 1
// Output: 0.00000
// Explanation: We poured 1 cup of champange to the top glass of the tower (which is indexed as (0, 0)). There will be no excess liquid so all the glasses under the top glass will remain empty.
// Example 2:

// Input: poured = 2, query_row = 1, query_glass = 1
// Output: 0.50000
// Explanation: We poured 2 cups of champange to the top glass of the tower (which is indexed as (0, 0)). There is one cup of excess liquid. The glass indexed as (1, 0) and the glass indexed as (1, 1) will share the excess liquid equally, and each will get half cup of champange.
// Example 3:

// Input: poured = 100000009, query_row = 33, query_glass = 17
// Output: 1.00000
 

// Constraints:

// 0 <= poured <= 109
// 0 <= query_glass <= query_row < 100



// 🚀 Approach
// Use recursion with memoization to compute the amount in each glass (i, j):
//     Base case: At (0,0) (the top glass), the amount is simply poured.
//     Recursive case: A glass receives overflow from its two parents:
//         Left parent (i - 1 , j - 1)
//         Right parent (i - 1 , j)
//     Overflow is (amount - 1) / 2.0 if the parent has more than 1. Otherwise, no overflow.
// Clamp negative overflow to 0.0 to avoid propagating invalid values.
// Store results in memo[i][j] to avoid recomputation.
// Finally, return min(1.0 , solve(poured , query_row , query_glass)) since a glass cannot hold more than 1.


// 🕛 Complexity
// Time complexity: O(query_row²)
// Space complexity: O(query_row²)









class Solution {
    double[][] memo = new double[101][101];

    double solve(int poured, int i, int j) {
        if (i < 0 || j < 0 || i < j) return 0.0;
        if (i == 0 && j == 0) return poured;
        if (memo[i][j] != -1) return memo[i][j];

        double leftUp = (solve(poured, i - 1, j - 1) - 1) / 2.0;
        double rightUp = (solve(poured, i - 1, j) - 1) / 2.0;

        if (leftUp < 0) leftUp = 0.0;
        if (rightUp < 0) rightUp = 0.0;

        return memo[i][j] = leftUp + rightUp;
    }

    public double champagneTower(int poured, int query_row, int query_glass) {
        for (int i = 0; i < 101; i++) {
            for (int j = 0; j < 101; j++) {
                memo[i][j] = -1;
            }
        }

        return Math.min(1.0, solve(poured, query_row, query_glass));
    }
}