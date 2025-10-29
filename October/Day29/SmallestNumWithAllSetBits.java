// LEETCODE 3370. Smallest Number With All Set Bits

// You are given a positive number n.

// Return the smallest number x greater than or equal to n, such that the binary representation of x contains only set bits

 

// Example 1:

// Input: n = 5

// Output: 7

// Explanation:

// The binary representation of 7 is "111".

// Example 2:

// Input: n = 10

// Output: 15

// Explanation:

// The binary representation of 15 is "1111".

// Example 3:

// Input: n = 3

// Output: 3

// Explanation:

// The binary representation of 3 is "11".

 

// Constraints:

// 1 <= n <= 1000
 


// 🚀 Approach
// Start with k = 1.
// In each iteration, compute x = (1 << k) - 1, which gives a number with k set bits (e.g., 111...1 in binary).
// Check if x ≥ n. If yes, return x.
// Otherwise, increment k and repeat.
// This works efficiently because x grows exponentially with k.








class Solution {
    public int smallestNumber(int n) {
        int k = 1;
        while(true) {
            int x = (1 << k) - 1;
            if (x >= n) return x;
            k++;
        }
    }
}