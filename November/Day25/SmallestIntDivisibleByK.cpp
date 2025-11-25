// LEETCODE 1015. Smallest Integer Divisible by K

// Given a positive integer k, you need to find the length of the smallest positive integer n such that n is divisible by k, and n only contains the digit 1.

// Return the length of n. If there is no such n, return -1.

// Note: n may not fit in a 64-bit signed integer.

 

// Example 1:

// Input: k = 1
// Output: 1
// Explanation: The smallest answer is n = 1, which has length 1.
// Example 2:

// Input: k = 2
// Output: -1
// Explanation: There is no such positive integer n divisible by 2.
// Example 3:

// Input: k = 3
// Output: 3
// Explanation: The smallest answer is n = 111, which has length 3.
 

// Constraints:

// 1 <= k <= 105



// 🚀 Approach
// Check divisibility blockers:
//     If k is divisible by 2 or 5, no repunit can be divisible by k, because repunits always end with digit 1. In this case, return -1.

// Iterative remainder update:
//     Start with remainder r = 0.
//     For each length i=1 to k:
//         Update remainder: r = (r * 10 + 1) % k
//         If r = 0, return i.

// Termination guarantee:
//     By the pigeonhole principle, if a solution exists, it must appear within k steps, because there are only k possible remainders.
//     If no remainder becomes 0 within k steps, return -1.

// 🕛 Complexity
// Time complexity: O(k)
// Space complexity: O(1)










class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (k % 2 == 0 || k % 5 == 0) return -1;
        
        int r = 0;
        for (int i = 1; i <= k; i++) {
            r = (r * 10 + 1) % k;
            if (r == 0) return i;
        }
        return -1;
    }
};