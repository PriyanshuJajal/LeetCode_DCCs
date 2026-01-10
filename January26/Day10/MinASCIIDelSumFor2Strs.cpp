// LEETCODE 712. Minimum ASCII Delete Sum for Two Strings

// Given two strings s1 and s2, return the lowest ASCII sum of deleted characters to make two strings equal.

 

// Example 1:

// Input: s1 = "sea", s2 = "eat"
// Output: 231
// Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
// Deleting "t" from "eat" adds 116 to the sum.
// At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.
// Example 2:

// Input: s1 = "delete", s2 = "leet"
// Output: 403
// Explanation: Deleting "dee" from "delete" to turn the string into "let",
// adds 100[d] + 101[e] + 101[e] to the sum.
// Deleting "e" from "leet" adds 101[e] to the sum.
// At the end, both strings are equal to "let", and the answer is 100+101+101+101 = 403.
// If instead we turned both strings into "lee" or "eet", we would get answers of 433 or 417, which are higher.
 

// Constraints:

// 1 <= s1.length, s2.length <= 1000
// s1 and s2 consist of lowercase English letters.


// 🚀 Approach
// Dynamic Programming Setup
//     Define a 2D DP table dp[n + 1][m + 1] where dp[i][j] represents the maximum ASCII sum of the common subsequence between the first i characters of s1 and the first j characters of s2.
// Transition:
//     If characters match (s1[i - 1] == s2[j - 1]), we add their ASCII value to the result of the subproblem:
//     dp[i][j] = s1[i - 1] + dp[i - 1][j - 1]
//     Otherwise, we take the maximum of skipping one character from either string:
//     dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1])
// Final Calculation
//     Compute the total ASCII sum of both strings (sum1 + sum2).
//     Subtract twice the maximum common subsequence ASCII sum (2 * dp[n][m]).
//     This gives the minimum delete sum required.

// 🕛 Complexity
// Time complexity: O(n * m)
// Space complexity: O(n * m)









class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n + 1 , vector<int>(m + 1));

        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < m + 1; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = s1[i - 1] + dp[i - 1][j - 1];
                }
                else dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);
            }
        }

        int lcs = dp[n][m];
        int sum1 = 0;
        int sum2 = 0;

        for (int i = 0; i < n; i++) {
            sum1 += s1[i];
        }
        for (int j = 0; j < m; j++) {
            sum2 += s2[j];
        }

        return sum1 + sum2 - 2 * lcs;
    }
};