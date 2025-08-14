// LEETCODE 2264 -> Largest 3-Same-Digit Number in String

// You are given a string num representing a large integer. An integer is good if it meets the following conditions:

// It is a substring of num with length 3.
// It consists of only one unique digit.
// Return the maximum good integer as a string or an empty string "" if no such integer exists.

// Note:

// A substring is a contiguous sequence of characters within a string.
// There may be leading zeroes in num or a good integer.
 

// Example 1:

// Input: num = "6777133339"
// Output: "777"
// Explanation: There are two distinct good integers: "777" and "333".
// "777" is the largest, so we return "777".
// Example 2:

// Input: num = "2300019"
// Output: "000"
// Explanation: "000" is the only good integer.
// Example 3:

// Input: num = "42352338"
// Output: ""
// Explanation: No substring of length 3 consists of only one unique digit. Therefore, there are no good integers.
 

// Constraints:

// 3 <= num.length <= 1000
// num only consists of digits.

// 🚀 Approach
// Iterate through the string from index 0 to n - 3.
// For each index, check if the current character and the next two are the same.
// If they are, form the triplet and compare it with the current maximum using max().
// Return the largest triplet found.

class Solution {
public:
    string largestGoodInteger(string num) {
        string s = "" , res = "";
        for (int i = 0; i < num.size() - 2; i++) {
            int j = i + 1;
            int k = j + 1;

            if (k < num.size() && num[i] == num[j] && num[j] == num[k]) {
                s += num[i];
                s += num[j];
                s += num[k];

                res = max(res , s);
                s = "";
            }
        }  
        return res;
    }
};