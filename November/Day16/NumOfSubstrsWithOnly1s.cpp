// LEETCODE 1513. Number of Substrings With Only 1s

// Given a binary string s, return the number of substrings with all characters 1's. Since the answer may be too large, return it modulo 109 + 7.

 

// Example 1:

// Input: s = "0110111"
// Output: 9
// Explanation: There are 9 substring in total with only 1's characters.
// "1" -> 5 times.
// "11" -> 3 times.
// "111" -> 1 time.
// Example 2:

// Input: s = "101"
// Output: 2
// Explanation: Substring "1" is shown 2 times in s.
// Example 3:

// Input: s = "111111"
// Output: 21
// Explanation: Each substring contains only 1's characters.
 

// Constraints:

// 1 <= s.length <= 105
// s[i] is either '0' or '1'.




// 🚀 Approach
// Traverse the string character by character.
// Maintain a counter cnt1 for the current streak of consecutive '1's.
// For each '1', increment cnt1 and add it to the total subStrs.
// Reset cnt1 to 0 when a '0' is encountered.
// Use modulo 1e9 + 7 to avoid overflow.


// 🕛 Complexity
// Time complexity: O(n)
// Space complexity: O(1)











class Solution {
public:
    int mod = 1e9 + 7;
    int numSub(string s) {
        int cnt1 = 0;
        int subStrs = 0;

        for (char ch : s) {
            if (ch == '1') {
                cnt1++;
                subStrs = (subStrs + cnt1) % mod;
            }
            else cnt1 = 0;
        }
        return subStrs;
    }
};
