// LEETCODE 3783. Mirror Distance of an Integer

// You are given an integer n.

// Define its mirror distance as: abs(n - reverse(n))​​​​​​​ where reverse(n) is the integer formed by reversing the digits of n.

// Return an integer denoting the mirror distance of n​​​​​​​.

// abs(x) denotes the absolute value of x.

 

// Example 1:

// Input: n = 25

// Output: 27

// Explanation:

// reverse(25) = 52.
// Thus, the answer is abs(25 - 52) = 27.
// Example 2:

// Input: n = 10

// Output: 9

// Explanation:

// reverse(10) = 01 which is 1.
// Thus, the answer is abs(10 - 1) = 9.
// Example 3:

// Input: n = 7

// Output: 0

// Explanation:

// reverse(7) = 7.
// Thus, the answer is abs(7 - 7) = 0.
 

// Constraints:

// 1 <= n <= 109


// 🚀 Approach
// Convert the integer n into a string.
// Reverse the string to get the mirrored representation.
// Convert the reversed string back into an integer.
// Compute the absolute difference between the original number and its mirrored version.
// Return this difference.

// 🕛 Complexity
// Time complexity: O(d) , d = number of digits in n
// Space complexity: O(d)

class Solution {
public:
    int mirrorDistance(int n) {
        string s = to_string(n);
        reverse(begin(s) , end(s));

        return abs(n - stoi(s));
    }
};