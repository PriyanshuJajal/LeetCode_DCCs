// LEETCODE 1411. Number of Ways to Paint N × 3 Grid

// You have a grid of size n x 3 and you want to paint each cell of the grid with exactly one of the three colors: Red, Yellow, or Green while making sure that no two adjacent cells have the same color (i.e., no two cells that share vertical or horizontal sides have the same color).

// Given n the number of rows of the grid, return the number of ways you can paint this grid. As the answer may grow large, the answer must be computed modulo 109 + 7.

 

// Example 1:


// Input: n = 1
// Output: 12
// Explanation: There are 12 possible way to paint the grid as shown.
// Example 2:

// Input: n = 5000
// Output: 30228214
 

// Constraints:

// n == grid.length
// 1 <= n <= 5000



// 🚀 Approach
// We use dynamic programming with two states:
//     p1: number of ways to paint up to row i where the last row is of Type 1 (two colors).
//     p2: number of ways to paint up to row i where the last row is of Type 2 (three colors).
// When adding a new row:
//     If the previous row was Type 1:
//         Next row can be Type 1 in 3 ways.
//         Next row can be Type 2 in 2 ways.
//     If the previous row was Type 2:
//         Next row can be Type 1 in 2 ways.
//         Next row can be Type 2 in 2 ways.
// So recurrence relation:
//     Type 1: 3 * p1 + 2 * p2
//     Type 2: 2 * p1 + 2 * p2
// In this way, we calculate the result by iterating from 2 to n & calculating through above recurrence relation to get the answer.

// 🕛 Complexity
// Time complexity: O(n)
// Space complexity: O(1)









class Solution {
public:
    int numOfWays(int n) {
        const int MOD = 1e9 + 7;
        long p1 = 6 , p2 = 6;

        for (int i = 2; i <= n; i++) {
            long long newP1 = (3 * p1 + 2 * p2) % MOD;
            long long newP2 = (2 * p1 + 2 * p2) % MOD;

            p1 = newP1;
            p2 = newP2;
        }
        return (int)((p1 + p2) % MOD);
    }
};