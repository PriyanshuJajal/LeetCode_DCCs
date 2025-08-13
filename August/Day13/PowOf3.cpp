// LEETCODE 326...


// Given an integer n, return true if it is a power of three. Otherwise, return false.

// An integer n is a power of three, if there exists an integer x such that n == 3x.

 
// Example 1:

// Input: n = 27
// Output: true
// Explanation: 27 = 33
// Example 2:

// Input: n = 0
// Output: false
// Explanation: There is no x where 3x = 0.
// Example 3:

// Input: n = -1
// Output: false
// Explanation: There is no x where 3x = (-1).
 

// Constraints:

// -231 <= n <= 231 - 1


// Approach...
// Check for non-positive values: If n <= 0, return false immediately.
// Use modulus: Return true if 1162261467 % n == 0, meaning n is a divisor of 3^{19}.
// This works because all powers of 3 up to 3^{19} are divisors of 3^{19}, and no non-power-of-3 integers will divide it evenly.

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        return 1162261467 % n == 0;
    }
};