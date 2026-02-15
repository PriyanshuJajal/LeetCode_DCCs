// LEETCODE 67. Add Binary

// Given two binary strings a and b, return their sum as a binary string.

 

// Example 1:

// Input: a = "11", b = "1"
// Output: "100"
// Example 2:

// Input: a = "1010", b = "1011"
// Output: "10101"
 

// Constraints:

// 1 <= a.length, b.length <= 104
// a and b consist only of '0' or '1' characters.
// Each string does not contain leading zeros except for the zero itself.



// 🚀 Approach
// Initialize two pointers m and n at the end of strings a and b.
// Use a carry variable to track overflow during addition.
// Loop while either pointer is valid:
//     Add the current bits (if available) plus the carry.
//     Compute the result bit (sum % 2) and append it to the result string.
//     Update the carry (sum / 2).
// After the loop, if carry is still 1, append it.
// Reverse the result string since we built it from least significant to most significant bit.

// 🕛 Complexity
// Time complexity: O(max(m , n))
// Space complexity: O(max(m , n))









class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.length() - 1;
        int n = b.length() - 1;
        string res = "";

        int sum = 0;
        int carry = 0;

        while(m >= 0 || n >= 0) {
            sum = carry;
            if (m >= 0) {
                sum += a[m] - '0';
                m--;
            }
            
            if (n >= 0) {
                sum += b[n] - '0';
                n--;
            }

            res.push_back((sum & 1) ? '1' : '0');
            carry = (sum > 1) ? 1 : 0;
        }
        if (carry) res.push_back('1');
        reverse(begin(res) , end(res));

        return res;
    }
};