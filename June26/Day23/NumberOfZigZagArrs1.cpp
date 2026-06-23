// LEETCODE 3699. Number of ZigZag Arrays I

// You are given three integers n, l, and r.

// A ZigZag array of length n is defined as follows:

// Each element lies in the range [l, r].
// No two adjacent elements are equal.
// No three consecutive elements form a strictly increasing or strictly decreasing sequence.
// Return the total number of valid ZigZag arrays.

// Since the answer may be large, return it modulo 109 + 7.

// A sequence is said to be strictly increasing if each element is strictly greater than its previous one (if exists).

// A sequence is said to be strictly decreasing if each element is strictly smaller than its previous one (if exists).

 

// Example 1:

// Input: n = 3, l = 4, r = 5

// Output: 2

// Explanation:

// There are only 2 valid ZigZag arrays of length n = 3 using values in the range [4, 5]:

// [4, 5, 4]
// [5, 4, 5]​​​​​​​
// Example 2:

// Input: n = 3, l = 1, r = 3

// Output: 10

// Explanation:

// There are 10 valid ZigZag arrays of length n = 3 using values in the range [1, 3]:

// [1, 2, 1], [1, 3, 1], [1, 3, 2]
// [2, 1, 2], [2, 1, 3], [2, 3, 1], [2, 3, 2]
// [3, 1, 2], [3, 1, 3], [3, 2, 3]
// All arrays meet the ZigZag conditions.

 

// Constraints:

// 3 <= n <= 2000
// 1 <= l < r <= 2000


// Time complexity: O(n * (r - l))
// Space complexity: O(r - l)



class Solution {
public:
    int MOD = 1e9 + 7;
    int zigZagArrays(int n, int l, int r) {
        r -= l;
        vector<int> dp(r + 1 , 1);

        for (int i = 1; i < n; i++) {
            int pref = 0;
            int pref2;

            if (i & 1) {
                for (int j = 0; j <= r; j++) {
                    pref2 = pref + dp[j];
                    dp[j] = pref;
                    pref = pref2 % MOD;
                }
            }
            else {
                for (int j = r; j >= 0; j--) {
                    pref2 = pref + dp[j];
                    dp[j] = pref;
                    pref = pref2 % MOD;
                }
            }
        }

        int validArrs = 0;
        for (int val : dp) {
            validArrs = (validArrs + val) % MOD;
        }
        
        return validArrs * 2 % MOD;
    }
};