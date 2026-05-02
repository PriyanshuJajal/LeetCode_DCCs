// LEETCODE 788. Rotated Digits

// An integer x is a good if after rotating each digit individually by 180 degrees, we get a valid number that is different from x. Each digit must be rotated - we cannot choose to leave it alone.

// A number is valid if each digit remains a digit after rotation. For example:

// 0, 1, and 8 rotate to themselves,
// 2 and 5 rotate to each other (in this case they are rotated in a different direction, in other words, 2 or 5 gets mirrored),
// 6 and 9 rotate to each other, and
// the rest of the numbers do not rotate to any other number and become invalid.
// Given an integer n, return the number of good integers in the range [1, n].

 

// Example 1:

// Input: n = 10
// Output: 4
// Explanation: There are four good numbers in the range [1, 10] : 2, 5, 6, 9.
// Note that 1 and 10 are not good numbers, since they remain unchanged after rotating.
// Example 2:

// Input: n = 1
// Output: 0
// Example 3:

// Input: n = 2
// Output: 1
 

// Constraints:

// 1 <= n <= 104


// 🚀 Approach
// Iterate through all numbers from 1 to n.
// For each number, check digit by digit:
//     If any digit is invalid (3 , 4 , 7), mark the number invalid.
//     If at least one digit is in {2 , 5 , 6 , 9}, mark it as different.
// After checking all digits, if the number is valid and different, increment the count.
// Return the final count.

// 🕛 Complexity
// Time complexity: O(nlogn), each number has atmost log₁₀(n) digits
// Space complexity: O(1)



class Solution {
public:
    int rotatedDigits(int n) {
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            int x = i;
            bool isValid = true;
            bool isDiff = false;

            while(x > 0) {
                int d = x % 10;
                if (d == 3 || d == 4 || d == 7) {
                    isValid = false;
                    break;
                }
                if (d == 2 || d == 5 || d == 6 || d == 9) {
                    isDiff = true;
                }
                x /= 10;
            }
            if (isValid && isDiff) cnt++;
        }
        return cnt;
    }
};