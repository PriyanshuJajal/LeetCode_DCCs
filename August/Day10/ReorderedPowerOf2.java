// LEETCODE 869...

// You are given an integer n. We reorder the digits in any order (including the original order) such that the leading digit is not zero.

// Return true if and only if we can do this so that the resulting number is a power of two.

 

// Example 1:

// Input: n = 1
// Output: true
// Example 2:

// Input: n = 10
// Output: false
 

// Constraints:

// 1 <= n <= 109

// 🚀 Approach
// Digit Encoding:
// The getDigits(int num) method encodes the digit frequency of a number using powers of 10. For example, if a digit d appears once, it adds 10^d to the result. Multiple occurrences of the same digit will sum multiple powers of 10, creating a unique fingerprint.
// Power of 2 Check:
// Iterate through all powers of 2 from 2^0 to 2^{30} (since 2^{30} = 1073741824 is the largest power of 2 within 10 digits). For each, compute its digit encoding and compare it to the target.
// Match:
// If any power of 2 has the same digit encoding as n, return true.

class Solution {
    public long getDigits(int num) {
        long res = 0;
        while(num > 0) {
            res += Math.pow(10 , num % 10);
            num = num / 10;
        }
        return res;
    }

    public boolean reorderedPowerOf2(int n) {
        long target = getDigits(n);
        for (int i = 0; i < 31; i++) {
            if (getDigits(1 << i) == target) return true;
        }
        return false;
    }
}