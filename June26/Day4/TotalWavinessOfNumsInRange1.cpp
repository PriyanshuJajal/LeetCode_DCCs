// LEETCODE 3751. Total Waviness of Numbers in Range I

// You are given two integers num1 and num2 representing an inclusive range [num1, num2].

// The waviness of a number is defined as the total count of its peaks and valleys:

// A digit is a peak if it is strictly greater than both of its immediate neighbors.
// A digit is a valley if it is strictly less than both of its immediate neighbors.
// The first and last digits of a number cannot be peaks or valleys.
// Any number with fewer than 3 digits has a waviness of 0.
// Return the total sum of waviness for all numbers in the range [num1, num2].
 

// Example 1:

// Input: num1 = 120, num2 = 130

// Output: 3

// Explanation:

// In the range [120, 130]:
// 120: middle digit 2 is a peak, waviness = 1.
// 121: middle digit 2 is a peak, waviness = 1.
// 130: middle digit 3 is a peak, waviness = 1.
// All other numbers in the range have a waviness of 0.
// Thus, total waviness is 1 + 1 + 1 = 3.

// Example 2:

// Input: num1 = 198, num2 = 202

// Output: 3

// Explanation:

// In the range [198, 202]:
// 198: middle digit 9 is a peak, waviness = 1.
// 201: middle digit 0 is a valley, waviness = 1.
// 202: middle digit 0 is a valley, waviness = 1.
// All other numbers in the range have a waviness of 0.
// Thus, total waviness is 1 + 1 + 1 = 3.

// Example 3:

// Input: num1 = 4848, num2 = 4848

// Output: 2

// Explanation:

// Number 4848: the second digit 8 is a peak, and the third digit 4 is a valley, giving a waviness of 2.

// Constraints:

// 1 <= num1 <= num2 <= 105



// 🚀 Approach
// Iterate through all integers from num1 to num2.
// Convert each integer into a string to easily access its digits.
// For each digit n[j] (excluding the first and last digit):
//     If n[j] > n[j - 1] && n[j] > n[j + 1], it is a peak → increment count.
//     If n[j] < n[j - 1] && n[j] < n[j + 1], it is a valley → increment count.
// Accumulate the count across all numbers in the range.
// Return the total count.

// 🕛 Complexity
// Time complexity: O(M * D)
// Range size is M = (num2 - num1 + 1)
// Max number of digits is D (D <= log10(num2))

// Space complexity: O(D)


class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int cnt = 0;
        for (int i = num1; i <= num2; i++) {
            string n = to_string(i);
            for (int j = 1; j < n.size() - 1; j++) {
                if (n[j] > n[j - 1] && n[j] > n[j + 1] ||
                   n[j] < n[j - 1] && n[j] < n[j + 1]) cnt++;
            }
        }
        return cnt;
    }
};