// LEETCODE 342. Power of Four

// Given an integer n, return true if it is a power of four. Otherwise, return false.

// An integer n is a power of four, if there exists an integer x such that n == 4x.

 

// Example 1:

// Input: n = 16
// Output: true
// Example 2:

// Input: n = 5
// Output: false
// Example 3:

// Input: n = 1
// Output: true
 

// Constraints:

// -231 <= n <= 231 - 1

// 🚀 Approach
// We use two bitwise checks:
// Power of Two Check:
// (n & (n - 1)) == 0 ensures only one bit is set.
// Position Check:
// 0x55555555 is a hexadecimal mask with bits set at all even positions (for 32-bit integers).
// (n & 0x55555555) != 0 confirms that the single set bit is in a position valid for powers of four.
// Together, these ensure n is a power of four.


class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n <= 0) return false;
        if ((n & (n - 1)) != 0) return false;

        return (n & 0x55555555) != 0;
    }
};