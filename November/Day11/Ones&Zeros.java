// LEETCODE 474. Ones and Zeroes

// You are given an array of binary strings strs and two integers m and n.

// Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.

// A set x is a subset of a set y if all elements of x are also elements of y.

 

// Example 1:

// Input: strs = ["10","0001","111001","1","0"], m = 5, n = 3
// Output: 4
// Explanation: The largest subset with at most 5 0's and 3 1's is {"10", "0001", "1", "0"}, so the answer is 4.
// Other valid but smaller subsets include {"0001", "1"} and {"10", "1", "0"}.
// {"111001"} is an invalid subset because it contains 4 1's, greater than the maximum of 3.
// Example 2:

// Input: strs = ["10","0","1"], m = 1, n = 1
// Output: 2
// Explanation: The largest subset is {"0", "1"}, so the answer is 2.
 

// Constraints:

// 1 <= strs.length <= 600
// 1 <= strs[i].length <= 100
// strs[i] consists only of digits '0' and '1'.
// 1 <= m, n <= 100




// 🚀 Approach
// Use dynamic programming with a 2D dp array where dp[i][j] represents the maximum number of strings that can be formed with i zeros and j ones.
// For each string:
//     Count the number of 0s and 1s.
//     Traverse the dp array in reverse (from m to cst0, and n to cst1) to avoid overwriting states that are needed for future transitions.
//     Update dp[i][j] as the maximum of its current value and 1 + dp[i - cst0][j - cst1].
// This reverse traversal ensures that each string is only considered once, maintaining the 0/1 nature of the knapsack.


// 🕛 Complexity
// Time complexity: O(L * m * n)
// Space complexity: O(m * n)










class Solution {
    private int[] getCnts(String s) {
        int zeros = 0;
        int ones = 0;
        for (char ch : s.toCharArray()) {
            if (ch == '0') zeros++;
            else ones++;
        }
        return new int[] {zeros , ones};
    }

    public int findMaxForm(String[] strs, int m, int n) {
        int[][] dp = new int[m + 1][n + 1];

        for (String s : strs) {
            int[] cost = getCnts(s);
            int cst0 = cost[0];
            int cst1 = cost[1];

            for (int i = m; i >= cst0; i--) {
                for (int j = n; j >= cst1; j--) {
                    dp[i][j] = Math.max(dp[i][j] , 1 + dp[i - cst0][j - cst1]);
                }
            }
        }
        return dp[m][n];
    }
}
