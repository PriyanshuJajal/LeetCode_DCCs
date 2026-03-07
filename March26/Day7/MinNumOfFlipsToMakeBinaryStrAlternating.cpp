// LEETCODE 1888. Minimum Number of Flips to Make the Binary String Alternating

// You are given a binary string s. You are allowed to perform two types of operations on the string in any sequence:

// Type-1: Remove the character at the start of the string s and append it to the end of the string.
// Type-2: Pick any character in s and flip its value, i.e., if its value is '0' it becomes '1' and vice-versa.
// Return the minimum number of type-2 operations you need to perform such that s becomes alternating.

// The string is called alternating if no two adjacent characters are equal.

// For example, the strings "010" and "1010" are alternating, while the string "0100" is not.
 

// Example 1:

// Input: s = "111000"
// Output: 2
// Explanation: Use the first operation two times to make s = "100011".
// Then, use the second operation on the third and sixth elements to make s = "101010".
// Example 2:

// Input: s = "010"
// Output: 0
// Explanation: The string is already alternating.
// Example 3:

// Input: s = "1110"
// Output: 1
// Explanation: Use the second operation on the second element to make s = "1010".
 

// Constraints:

// 1 <= s.length <= 105
// s[i] is either '0' or '1'.


// 🚀 Approach
// Two alternating patterns:
//     Pattern 1: 010101...
//     Pattern 2: 101010...
// For each window of length n, we count mismatches with both patterns.
// Sliding window over 2n characters:
//     Expand the window by moving j.
//     Compare s[j % n] with expected characters of both patterns.
//     Maintain mismatch counts f1 and f2.
// Shrink window when size > n:
//     Remove contribution of s[i % n] from mismatch counts.
//     Move i forward.
// Update minimum flips:   
//     When window size == n, record min({flips , f1 , f2}).
// Return the minimum flips across all rotations.

// 🕛 Complexity
// Time complexity: O(2n) ~ O(n)
// Space complexity: O(1)









class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        int flips = INT_MAX;
        int f1 = 0;
        int f2 = 0;

        int i = 0 , j = 0;
        while(j < 2 * n) {
            char expChar1 = (j & 1) ? '1' : '0';
            char expChar2 = (j & 1) ? '0' : '1';

            if (s[j % n] != expChar1) f1++;
            if (s[j % n] != expChar2) f2++;

            if (j - i + 1 > n) {
                expChar1 = (i & 1) ? '1' : '0';
                expChar2 = (i & 1) ? '0' : '1';

                if (s[i % n] != expChar1) f1--;
                if (s[i % n] != expChar2) f2--;

                i++;
            }

            if (j - i + 1 == n) flips = min({flips , f1 , f2});

            j++;
        }
        return flips;
    }
};