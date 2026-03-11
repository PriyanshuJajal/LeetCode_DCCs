// LEETCODE 1009. Complement of Base 10 Integer

// The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.

// For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.
// Given an integer n, return its complement.

 

// Example 1:

// Input: n = 5
// Output: 2
// Explanation: 5 is "101" in binary, with complement "010" in binary, which is 2 in base-10.
// Example 2:

// Input: n = 7
// Output: 0
// Explanation: 7 is "111" in binary, with complement "000" in binary, which is 0 in base-10.
// Example 3:

// Input: n = 10
// Output: 5
// Explanation: 10 is "1010" in binary, with complement "0101" in binary, which is 5 in base-10.
 

// Constraints:

// 0 <= n < 109
 

// 🚀 Approach
// Edge case: If n == 0, its complement is 1.
// Use bit_width((unsigned)n) (from C++20) to find the number of bits required to represent n.
//     Example: n = 10 → binary 1010 → bit width = 4.
// Build a mask of all 1’s with that length: (1 << bits) - 1.
//     For bits = 4, mask = 1111 (decimal 15).
// XOR the mask with n: mask ^ n.
//     This flips all significant bits of n.

// 🕛 Complexity
// Time complexity: O(1)
// Space complexity: O(1)









class Solution {
    public int bitwiseComplement(int n) {
        if (n == 0) return 1;
        
        // Find the number of bits needed to represent n
        int bits = Integer.SIZE - Integer.numberOfLeadingZeros(n);
        
        // Create mask with all 1s of that length
        int mask = (1 << bits) - 1;
        
        // XOR to flip the bits
        return mask ^ n;
    }
}