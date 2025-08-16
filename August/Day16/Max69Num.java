// LEETCODE 1323. Maximum 69 Number

// You are given a positive integer num consisting only of digits 6 and 9.

// Return the maximum number you can get by changing at most one digit (6 becomes 9, and 9 becomes 6).
 

// Example 1:

// Input: num = 9669
// Output: 9969
// Explanation: 
// Changing the first digit results in 6669.
// Changing the second digit results in 9969.
// Changing the third digit results in 9699.
// Changing the fourth digit results in 9666.
// The maximum number is 9969.
// Example 2:

// Input: num = 9996
// Output: 9999
// Explanation: Changing the last digit 6 to 9 results in the maximum number.
// Example 3:

// Input: num = 9999
// Output: 9999
// Explanation: It is better not to apply any change.
 

// Constraints:

// 1 <= num <= 104
// num consists of only 6 and 9 digits.

// 🚀 Approach
// Extract digits from the number starting from the least significant digit and store them in a list or vector.
// Traverse the digit list in reverse (from most significant to least significant).
// Find the first '6' and change it to '9'. Break the loop to ensure only one change.
// Reconstruct the number by multiplying each digit with its corresponding place value and summing them up.
// This approach ensures that only one digit is changed and the result is maximized.

class Solution {
    public int maximum69Number (int num) {
        List<Integer> digit = new ArrayList<>();
        int n = num;
        int dec = 1;

        while(n != 0) {
            digit.add(n % 10);
            n /= 10;
        }
        for (int i = digit.size() - 1; i >= 0; i--) {
            if (digit.get(i) == 6) {
                digit.set(i , 9);
                break;
            }
        }
        num = 0;
        for (int i = 0; i < digit.size(); i++) {
            num += dec * digit.get(i);
            dec *= 10;
        }
        return num;
    }
}