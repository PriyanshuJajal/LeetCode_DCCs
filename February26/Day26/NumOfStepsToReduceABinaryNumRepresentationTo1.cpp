// LEETCODE 1404. Number of Steps to Reduce a Number in Binary Representation to One

// Given the binary representation of an integer as a string s, return the number of steps to reduce it to 1 under the following rules:

// If the current number is even, you have to divide it by 2.

// If the current number is odd, you have to add 1 to it.

// It is guaranteed that you can always reach one for all test cases.

 

// Example 1:

// Input: s = "1101"
// Output: 6
// Explanation: "1101" corressponds to number 13 in their decimal representation.
// Step 1) 13 is odd, add 1 and obtain 14. 
// Step 2) 14 is even, divide by 2 and obtain 7.
// Step 3) 7 is odd, add 1 and obtain 8.
// Step 4) 8 is even, divide by 2 and obtain 4.  
// Step 5) 4 is even, divide by 2 and obtain 2. 
// Step 6) 2 is even, divide by 2 and obtain 1.  
// Example 2:

// Input: s = "10"
// Output: 1
// Explanation: "10" corresponds to number 2 in their decimal representation.
// Step 1) 2 is even, divide by 2 and obtain 1.  
// Example 3:

// Input: s = "1"
// Output: 0
 

// Constraints:

// 1 <= s.length <= 500
// s consists of characters '0' or '1'
// s[0] == '1'



// Approach
// Start from the least significant bit (rightmost).
// Maintain a carry that represents whether we’ve added 1 in previous steps.
// For each bit (except the most significant one):
//     If (bit + carry) is odd → we need two operations: add 1 (which sets carry = 1) and then divide by 2.
//     If (bit + carry) is even → we only need one operation (divide by 2).
// At the end, add the final carry to the operation count.
// Return the total number of operations.

// Complexity
// Time complexity: O(n)
// Space complexity: O(1)









class Solution {
public:
    int numSteps(string s) {
        int n = s.length();
        int ops = 0;
        int carry = 0;

        for (int i = n - 1; i >= 1; i--) {
            if (((s[i] - '0') + carry) & 1) {
                ops += 2;
                carry = 1;
            }
            else ops++;
        }
        return ops + carry;
    }
};