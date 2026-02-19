// LEETCODE 696. Count Binary Substrings

// Given a binary string s, return the number of non-empty substrings that have the same number of 0's and 1's, and all the 0's and all the 1's in these substrings are grouped consecutively.

// Substrings that occur multiple times are counted the number of times they occur.

 

// Example 1:

// Input: s = "00110011"
// Output: 6
// Explanation: There are 6 substrings that have equal number of consecutive 1's and 0's: "0011", "01", "1100", "10", "0011", and "01".
// Notice that some of these substrings repeat and are counted the number of times they occur.
// Also, "00110011" is not a valid substring because all the 0's (and 1's) are not grouped together.
// Example 2:

// Input: s = "10101"
// Output: 4
// Explanation: There are 4 substrings: "10", "01", "10", "01" that have equal number of consecutive 1's and 0's.
 

// Constraints:

// 1 <= s.length <= 105
// s[i] is either '0' or '1'.


// 🚀 Approach
// Traverse the string while grouping consecutive identical characters.
// Keep track of:
//     currCnt: length of the current run.
//     prevCnt: length of the previous run.
// When the character changes:
//     Add min(prevCnt , currCnt) to the totalCnt (because that many substrings can be formed between the two runs).
//     Update prevCnt to currCnt and reset currCnt to 1.
// After the loop ends, add min(prevCnt, currCnt) one last time to account for the final pair.
// Return the totalCnt.

// 🕛 Complexity
// Time complexity: O(n)
// Space complexity: O(1)









class Solution {
    public int countBinarySubstrings(String s) {
        int totalCnt = 0;
        int prevCnt = 0;
        int currCnt = 1;

        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) == s.charAt(i - 1)) {
                currCnt++;
            } else {
                totalCnt += Math.min(prevCnt, currCnt);
                prevCnt = currCnt;
                currCnt = 1;
            }
        }
        return totalCnt + Math.min(prevCnt, currCnt);
    }
}