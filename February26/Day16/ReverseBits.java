// LEETCODE 190. Reverse Bits

// Reverse bits of a given 32 bits signed integer.

 

// Example 1:

// Input: n = 43261596

// Output: 964176192

// Explanation:

// Integer	Binary
// 43261596	00000010100101000001111010011100
// 964176192	00111001011110000010100101000000
// Example 2:

// Input: n = 2147483644

// Output: 1073741822

// Explanation:

// Integer	Binary
// 2147483644	01111111111111111111111111111100
// 1073741822	00111111111111111111111111111110
 

// Constraints:

// 0 <= n <= 231 - 2
// n is even.
 

// 🚀 Approach
// Initialize res = 0.
// Loop 32 times (since we’re dealing with 32‑bit integers).
// In each iteration:
//     Shift res left by 1 to make space for the next bit.
//     Extract the last bit of n using (n & 1) and add it to res.
//     Shift n right by 1 to process the next bit.
// After the loop, res contains the reversed bit sequence of n.

// 🕛 Complexity
// Time complexity: O(32) ~ O(1)
// Space complexity: O(1)









class Solution {
    public int reverseBits(int n) {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            res <<= 1;          // shift result left
            res |= (n & 1);     // add last bit of n
            n >>= 1;            // shift n right
        }
        return res;
    }
}