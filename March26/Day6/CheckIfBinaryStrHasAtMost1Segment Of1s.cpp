// LEETCODE 1784. Check if Binary String Has at Most One Segment of Ones

// Given a binary string s ​​​​​without leading zeros, return true​​​ if s contains at most one contiguous segment of ones. Otherwise, return false.

 

// Example 1:

// Input: s = "1001"
// Output: false
// Explanation: The ones do not form a contiguous segment.
// Example 2:

// Input: s = "110"
// Output: true
 

// Constraints:

// 1 <= s.length <= 100
// s[i]​​​​ is either '0' or '1'.
// s[0] is '1'.


// 🚀 Approach
// Instead of manually counting segments, we can simply check if "01" appears in the string.
//     - If "01" is found, it means there is a break between ones and zeros,
//         so there must be more than one segment of ones.
//     - If "01" is not found, then all ones are grouped together (or there are none at all).
// Thus, the solution reduces to a single string search.


// 🕛 Complexity
// - Time complexity: O(n).
// - Space complexity: O(1).
 








class Solution {
public:
    bool checkOnesSegment(string s) {
        return s.find("01") == string::npos;
    }
};