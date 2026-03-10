// LEETCODE 3130. Find All Possible Stable Binary Arrays II

// You are given 3 positive integers zero, one, and limit.

// A binary array arr is called stable if:

// The number of occurrences of 0 in arr is exactly zero.
// The number of occurrences of 1 in arr is exactly one.
// Each subarray of arr with a size greater than limit must contain both 0 and 1.
// Return the total number of stable binary arrays.

// Since the answer may be very large, return it modulo 109 + 7.

 

// Example 1:

// Input: zero = 1, one = 1, limit = 2

// Output: 2

// Explanation:

// The two possible stable binary arrays are [1,0] and [0,1].

// Example 2:

// Input: zero = 1, one = 2, limit = 1

// Output: 1

// Explanation:

// The only possible stable binary array is [1,0,1].

// Example 3:

// Input: zero = 3, one = 3, limit = 2

// Output: 14

// Explanation:

// All the possible stable binary arrays are [0,0,1,0,1,1], [0,0,1,1,0,1], [0,1,0,0,1,1], [0,1,0,1,0,1], [0,1,0,1,1,0], [0,1,1,0,0,1], [0,1,1,0,1,0], [1,0,0,1,0,1], [1,0,0,1,1,0], [1,0,1,0,0,1], [1,0,1,0,1,0], [1,0,1,1,0,0], [1,1,0,0,1,0], and [1,1,0,1,0,0].

 

// Constraints:

// 1 <= zero, one, limit <= 1000


// 🚀 Approach
// State Definition
// Use a 3D DP table t[i][j][last] where:
//     i = number of zeros used so far
//     j = number of ones used so far
//     last = 0 if the array ends with a zero, 1 if it ends with a one
// Each state stores the number of valid arrays with those counts.
// Initialization
//     Arrays consisting only of zeros up to limit are valid → t[i][0][0] = 1 for i ≤ limit.
//     Arrays consisting only of ones up to limit are valid → t[0][j][1] = 1 for j ≤ limit.
// Transition (Broken down the sequence mathematically into simple terms)
//     To place a 1 at the end:
//     t[i][j][1] = (t[i][j-1][0] + t[i][j-1][1]) % MOD
//     But if we exceed limit consecutive ones, subtract the invalid case (t[i][j][1] = (t[i][j][1] - t[i][j - 1 - limit][0] + MOD) % MOD).
//     To place a 0 at the end:
//     t[i][j][0] = (t[i-1][j][0] + t[i-1][j][1]) % MOD
//     Similarly, subtract invalid cases if consecutive zeros exceed limit (t[i][j][0] = (t[i][j][0] - t[i - 1 - limit][j][1] + MOD) % MOD).
// The final result is (t[zero][one][0] + t[zero][one][1]) % MOD.

// 🕛 Complexity
// Time complexity: O(one * zero)
// Space complexity: O(one * zero)









class Solution {
public:
    int MOD = 1e9 + 7;
    int numberOfStableArrays(int zero, int one, int limit) {
        vector<vector<vector<int>>> t(zero + 1 , vector<vector<int>>(one + 1 , vector<int>(2 , 0)));

        for (int i = 0; i <= min(zero , limit); i++) {
            t[i][0][0] = 1;
        }

        for (int j = 0; j <= min(one , limit); j++) {
            t[0][j][1] = 1;
        }

        for (int i = 0; i <= zero; i++) {
            for (int j = 0; j <= one; j++) {

                if (i == 0 || j == 0) continue;

                t[i][j][1] = (t[i][j - 1][0] + t[i][j - 1][1]) % MOD;

                if (j - 1 >= limit) {
                    t[i][j][1] = (t[i][j][1] - t[i][j - 1 - limit][0] + MOD) % MOD;
                }

                t[i][j][0] = (t[i - 1][j][0] + t[i - 1][j][1]) % MOD;

                if (i - 1 >= limit) {
                    t[i][j][0] = (t[i][j][0] - t[i - 1 - limit][j][1] + MOD) % MOD; 
                }
            }
        }

        return (t[zero][one][0] + t[zero][one][1]) % MOD;
    }
};