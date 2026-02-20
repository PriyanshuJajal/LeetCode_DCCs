// LEETCODE 761. Special Binary String

// Special binary strings are binary strings with the following two properties:

// The number of 0's is equal to the number of 1's.
// Every prefix of the binary string has at least as many 1's as 0's.
// You are given a special binary string s.

// A move consists of choosing two consecutive, non-empty, special substrings of s, and swapping them. Two strings are consecutive if the last character of the first string is exactly one index before the first character of the second string.

// Return the lexicographically largest resulting string possible after applying the mentioned operations on the string.

 

// Example 1:

// Input: s = "11011000"
// Output: "11100100"
// Explanation: The strings "10" [occuring at s[1]] and "1100" [at s[3]] are swapped.
// This is the lexicographically largest string possible after some number of swaps.
// Example 2:

// Input: s = "10"
// Output: "10"
 

// Constraints:

// 1 <= s.length <= 50
// s[i] is either '0' or '1'.
// s is a special binary string.


//  Approach
// Use a counter sum to track balance between 1s and 0s.
// Each time sum becomes 0, we found a valid special substring.
// Recursively process the substring inside (excluding the outer 1 and 0).
// Wrap it back with "1" + inner + "0".
// Collect all substrings, sort them in descending lexicographical order, and concatenate.

// 🕛 Complexity
// Time complexity: O(n²)
// Space complexity: O(n)









class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string> sp;
        int st = 0;
        int sum = 0;
        
        for (int i = 0; i < s.length(); i++) {
            sum += s[i] == '1' ? 1 : -1;
            if (sum == 0) {
                string inner = s.substr(st + 1 , i - st - 1);
                sp.push_back("1" + makeLargestSpecial(inner) + "0");
                st = i + 1;
            }
        }

        sort(begin(sp) , end(sp) , greater<string>());
        string res = "";
        for (string& str : sp) {
            res += str;
        }
        return res;
    }
};