// LEETCODE 3713. Longest Balanced Substring I

// You are given a string s consisting of lowercase English letters.

// A substring of s is called balanced if all distinct characters in the substring appear the same number of times.

// Return the length of the longest balanced substring of s.

 

// Example 1:

// Input: s = "abbac"

// Output: 4

// Explanation:

// The longest balanced substring is "abba" because both distinct characters 'a' and 'b' each appear exactly 2 times.

// Example 2:

// Input: s = "zzabccy"

// Output: 4

// Explanation:

// The longest balanced substring is "zabc" because the distinct characters 'z', 'a', 'b', and 'c' each appear exactly 1 time.​​​​​​​

// Example 3:

// Input: s = "aba"

// Output: 2

// Explanation:

// ​​​​​​​One of the longest balanced substrings is "ab" because both distinct characters 'a' and 'b' each appear exactly 1 time. Another longest balanced substring is "ba".

 

// Constraints:

// 1 <= s.length <= 1000
// s consists of lowercase English letters.



// 🚀 Approach
// Brute Force Enumeration of Substrings
//     Iterate over all possible starting indices i.
//     For each i, expand the substring by moving j from i to n - 1.
//     Maintain a frequency array freq[26] to count occurrences of each character.
// Check Balance
//     After each extension, call isBalanced(freq):
//         Skip characters with frequency 0.
//         Ensure all non-zero frequencies are equal.
//     If balanced, update maxLen.
// After checking all substrings, return the maximum length found.

// 🕛 Complexity
// Time complexity: O(n²)
// Space complexity: O(1)









class Solution {

    private boolean checkBalanced(int[] freq) {
        int common = 0;

        for (int f : freq) {
            if (f == 0) continue;

            if (common == 0) {
                common = f;
            } else if (f != common) {
                return false;
            }
        }
        return true;
    }

    public int longestBalanced(String s) {
        int n = s.length();
        int maxL = 0;

        for (int i = 0; i < n; i++) {
            int[] freq = new int[26];   

            for (int j = i; j < n; j++) {
                freq[s.charAt(j) - 'a']++;

                if (checkBalanced(freq)) {
                    maxL = Math.max(maxL, j - i + 1);
                }
            }
        }

        return maxL;
    }
}