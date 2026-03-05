// LEETCODE 1758. Minimum Changes To Make Alternating Binary String

// You are given a string s consisting only of the characters '0' and '1'. In one operation, you can change any '0' to '1' or vice versa.

// The string is called alternating if no two adjacent characters are equal. For example, the string "010" is alternating, while the string "0100" is not.

// Return the minimum number of operations needed to make s alternating.

 

// Example 1:

// Input: s = "0100"
// Output: 1
// Explanation: If you change the last character to '1', s will be "0101", which is alternating.
// Example 2:

// Input: s = "10"
// Output: 0
// Explanation: s is already alternating.
// Example 3:

// Input: s = "1111"
// Output: 2
// Explanation: You need two operations to reach "0101" or "1010".
 

// Constraints:

// 1 <= s.length <= 104
// s[i] is either '0' or '1'.


// 🚀 Approach
// Let n be the length of the string.
// Consider two possible alternating strings:
//     Starting with '0': 010101...
//     Starting with '1': 101010...
// Traverse the string:
//     If the index is even, the expected character for the start with 0 pattern is 0.
//     If it doesn’t match, increment stWith0.
//     If the index is odd, the expected character for the start with 0 pattern is 1.
//     If it doesn’t match, increment stWith0.
// The number of changes required for the start with 1 pattern is simply n - stWith0 (since every mismatch for one pattern is a match for the other).
// Return the minimum of stWith0 and stWith1.

// 🕛 Complexity
// Time complexity: O(n)
// Space complexity: O(1)









class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        int stWith0 = 0;

        for (int i = 0; i < n; i++) {
            if (i & 1) {
                if (s[i] == '1') stWith0++;
            }
            else {
                if (s[i] == '0') stWith0++;
            }
        }

        int stWith1 = n - stWith0;
        return min(stWith0 , stWith1);
    }
};