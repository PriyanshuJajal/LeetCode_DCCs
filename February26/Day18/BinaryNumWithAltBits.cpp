// 693. Binary Number with Alternating Bits


// Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.

 

// Example 1:

// Input: n = 5
// Output: true
// Explanation: The binary representation of 5 is: 101
// Example 2:

// Input: n = 7
// Output: false
// Explanation: The binary representation of 7 is: 111.
// Example 3:

// Input: n = 11
// Output: false
// Explanation: The binary representation of 11 is: 1011.
 

// Constraints:

// 1 <= n <= 231 - 1


// 🚀 Approach
// Compute res = n ^ (n >> 1).
//     If n has alternating bits, res will be a sequence of consecutive 1s.
// To check if res is all 1s, use the property:
//     A number with all 1s in binary satisfies (res & (res + 1)) == 0.
//     Example: 1111 (15) → res + 1 = 10000 → 1111 & 10000 = 0.
// Thus, the function returns true if the bits alternate, otherwise false.

// 🕛 Complexity
// Time complexity: O(1)
// Space complexity: O(1)









class Solution {
public:
    bool hasAlternatingBits(int n) {
        unsigned int res = n ^ (n >> 1);
        return (res & (res + 1)) == 0;
    }
};