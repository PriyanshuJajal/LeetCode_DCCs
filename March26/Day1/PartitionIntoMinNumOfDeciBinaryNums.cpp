// LEETCODE 1689. Partitioning Into Minimum Number Of Deci-Binary Numbers

// A decimal number is called deci-binary if each of its digits is either 0 or 1 without any leading zeros. For example, 101 and 1100 are deci-binary, while 112 and 3001 are not.

// Given a string n that represents a positive decimal integer, return the minimum number of positive deci-binary numbers needed so that they sum up to n.

 

// Example 1:

// Input: n = "32"
// Output: 3
// Explanation: 10 + 11 + 11 = 32
// Example 2:

// Input: n = "82734"
// Output: 8
// Example 3:

// Input: n = "27346209830709182346"
// Output: 9
 

// Constraints:

// 1 <= n.length <= 105
// n consists of only digits.
// n does not contain any leading zeros and represents a positive integer.



// 🚀 Approach
// Iterate through each character in the string n.
// Convert the character to its integer value (ch - '0').
// Track the maximum digit encountered.
// Return this maximum digit as the result.

// 🕛 Complexity
// Time complexity: O(length of n)
// Space complexity: O(1)









class Solution {
public:
    int minPartitions(string n) {
        int minNums = 0;
        for (char ch : n) {
            if ((ch - '0') > minNums) minNums = (ch - '0');
        }
        return minNums;
    }
};