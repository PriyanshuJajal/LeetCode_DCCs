// LEETCODE 1545. Find Kth Bit in Nth Binary String

// Given two positive integers n and k, the binary string Sn is formed as follows:

// S1 = "0"
// Si = Si - 1 + "1" + reverse(invert(Si - 1)) for i > 1
// Where + denotes the concatenation operation, reverse(x) returns the reversed string x, and invert(x) inverts all the bits in x (0 changes to 1 and 1 changes to 0).

// For example, the first four strings in the above sequence are:

// S1 = "0"
// S2 = "011"
// S3 = "0111001"
// S4 = "011100110110001"
// Return the kth bit in Sn. It is guaranteed that k is valid for the given n.

 

// Example 1:

// Input: n = 3, k = 1
// Output: "0"
// Explanation: S3 is "0111001".
// The 1st bit is "0".
// Example 2:

// Input: n = 4, k = 11
// Output: "1"
// Explanation: S4 is "011100110110001".
// The 11th bit is "1".
 

// Constraints:

// 1 <= n <= 20
// 1 <= k <= 2n - 1
 

// 🚀 Approach
// Base case:
//     If n = 1, the string is "0", so return '0'.
// Length calculation:
//     The length of Sn is 2^n - 1.
//     The middle index is ceil(len / 2).
// Recursive logic:
//     If k is before the middle, the k-th bit is the same as in S(n - 1).
//     If k is exactly the middle, return '1'.
//     If k is after the middle, it corresponds to the mirrored inverted bit from S(n - 1). So we recursively find the bit at the mirrored position and invert it.

// 🕛 Complexity
// Time complexity: O(n)
// Space complexity: O(n)









class Solution {
    public char findKthBit(int n, int k) {
        if (n == 1) {
            return '0';
        }

        // Length of the sequence at level n: 2^n - 1
        int len = (1 << n) - 1;

        // If k is in the first half, recurse on the first half
        if (k < Math.ceil(len / 2.0)) {
            return findKthBit(n - 1, k);
        } 
        // If k is the middle bit, return '1'
        else if (k == Math.ceil(len / 2.0)) {
            return '1';
        } 
        // Otherwise, recurse on the mirrored second half
        else {
            char ch = findKthBit(n - 1, len - (k - 1)); // handle reversed
            return (ch == '0') ? '1' : '0'; // handle flipped bit
        }
    }
}