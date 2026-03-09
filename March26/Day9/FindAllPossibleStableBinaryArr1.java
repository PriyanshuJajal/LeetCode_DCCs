// LEETCODE 3129. Find All Possible Stable Binary Arrays I
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

// The two possible stable binary arrays are [1,0] and [0,1], as both arrays have a single 0 and a single 1, and no subarray has a length greater than 2.

// Example 2:

// Input: zero = 1, one = 2, limit = 1

// Output: 1

// Explanation:

// The only possible stable binary array is [1,0,1].

// Note that the binary arrays [1,1,0] and [0,1,1] have subarrays of length 2 with identical elements, hence, they are not stable.

// Example 3:

// Input: zero = 3, one = 3, limit = 2

// Output: 14

// Explanation:

// All the possible stable binary arrays are [0,0,1,0,1,1], [0,0,1,1,0,1], [0,1,0,0,1,1], [0,1,0,1,0,1], [0,1,0,1,1,0], [0,1,1,0,0,1], [0,1,1,0,1,0], [1,0,0,1,0,1], [1,0,0,1,1,0], [1,0,1,0,0,1], [1,0,1,0,1,0], [1,0,1,1,0,0], [1,1,0,0,1,0], and [1,1,0,1,0,0].

 

// Constraints:

// 1 <= zero, one, limit <= 200



// 🚀 Approach
// DP State Definition
//     Let t[left1s][left0s][last] represent the number of stable arrays that can be formed using left1s ones and left0s zeros, where last indicates the type of element placed last (0 for zero, 1 for one).
// Initialization
//     t[0][0][0] = 1 and t[0][0][1] = 1 because an empty array is trivially stable.
// Transition
//     If the last element is 1, we can add a block of zeros of length l (where 1 ≤ l ≤ min(left0s, limit)), and transition to t[left1s][left0s - l][0].
//     If the last element is 0, we can add a block of ones of length l (where 1 ≤ l ≤ min(left1s, limit)), and transition to t[left1s - l][left0s][1].
// The result is the sum of arrays starting with 0 and arrays starting with 1: (stWith1 + stWith0) % MOD.

// 🕛 Complexity
// Time complexity: O(one * zero * limit)
// Space complexity: O(one * zero)









import java.util.*;

class Solution {
    final int MOD = 1000000007;
    int[][][] t = new int[201][201][2];

    public int numberOfStableArrays(int zero, int one, int limit) {
        for (int i = 0; i <= one; i++) {
            for (int j = 0; j <= zero; j++) {
                Arrays.fill(t[i][j], 0);
            }
        }

        t[0][0][0] = 1;
        t[0][0][1] = 1;

        for (int left1s = 0; left1s <= one; left1s++) {
            for (int left0s = 0; left0s <= zero; left0s++) {
                if (left1s == 0 && left0s == 0) continue;

                int stableArr = 0;
                // If last placed was 0, now place block of 1s
                for (int l = 1; l <= Math.min(left0s, limit); l++) {
                    stableArr = (stableArr + t[left1s][left0s - l][0]) % MOD;
                }
                t[left1s][left0s][1] = stableArr;

                stableArr = 0;
                // If last placed was 1, now place block of 0s
                for (int l = 1; l <= Math.min(left1s, limit); l++) {
                    stableArr = (stableArr + t[left1s - l][left0s][1]) % MOD;
                }
                t[left1s][left0s][0] = stableArr;
            }
        }

        int stWith1 = t[one][zero][0]; 
        int stWith0 = t[one][zero][1]; 

        return (stWith1 + stWith0) % MOD;
    }
}