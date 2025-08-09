// LEETCODE 231...

// Given an integer n, return true if it is a power of two. Otherwise, return false.

// An integer n is a power of two, if there exists an integer x such that n == 2^x.


// Example 1:

// Input: n = 1
// Output: true
// Explanation: 20 = 1
// Example 2:

// Input: n = 16
// Output: true
// Explanation: 24 = 16
// Example 3:

// Input: n = 3
// Output: false
 

// Constraints:

// -231 <= n <= 231 - 1
 

// 🚀 Approach
// We use a one-liner condition:

// return n > 0 && (n & (n - 1)) == 0;
// n > 0: Ensures we only consider positive integers.
// (n & (n - 1)) == 0: Checks if n has only one bit set, i.e., it's a power of two.
// This is a classic bit manipulation trick that is both elegant and efficient.


class Solution {
    public boolean isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
}