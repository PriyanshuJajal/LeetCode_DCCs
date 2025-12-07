// LEETCODE 1523. Count Odd Numbers in an Interval Range

// Given two non-negative integers low and high. Return the count of odd numbers between low and high (inclusive).

 

// Example 1:

// Input: low = 3, high = 7
// Output: 3
// Explanation: The odd numbers between 3 and 7 are [3,5,7].
// Example 2:

// Input: low = 8, high = 10
// Output: 1
// Explanation: The odd numbers between 8 and 10 are [9].
 

// Constraints:

// 0 <= low <= high <= 10^9



// 🚀 Approach
// Check if low is odd:
//     If low is odd, then the range [low, high] contains one extra odd number compared to the case when low is even.
//     This is because the sequence starts with an odd number.

// Formula:
//     If low is odd → (high - low + 2) / 2
//     If low is even → (high - low + 1) / 2

// This works because dividing the length of the range by 2 gives the number of odd numbers, and we adjust by +1 when the range starts with an odd.

// 🕛 Complexity
// Time complexity: O(1)
// Space complexity: O(1)














class Solution {
    public int countOdds(int low, int high) {
        if ((low & 1) == 1) return (high - low + 2) / 2;
        return (high - low + 1) / 2;
    }
}