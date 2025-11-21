// LEETCODE 1930. Unique Length-3 Palindromic Subsequences

// Given a string s, return the number of unique palindromes of length three that are a subsequence of s.

// Note that even if there are multiple ways to obtain the same subsequence, it is still only counted once.

// A palindrome is a string that reads the same forwards and backwards.

// A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

// For example, "ace" is a subsequence of "abcde".
 

// Example 1:

// Input: s = "aabca"
// Output: 3
// Explanation: The 3 palindromic subsequences of length 3 are:
// - "aba" (subsequence of "aabca")
// - "aaa" (subsequence of "aabca")
// - "aca" (subsequence of "aabca")
// Example 2:

// Input: s = "adc"
// Output: 0
// Explanation: There are no palindromic subsequences of length 3 in "adc".
// Example 3:

// Input: s = "bbcbaba"
// Output: 4
// Explanation: The 4 palindromic subsequences of length 3 are:
// - "bbb" (subsequence of "bbcbaba")
// - "bcb" (subsequence of "bbcbaba")
// - "bab" (subsequence of "bbcbaba")
// - "aba" (subsequence of "bbcbaba")
 

// Constraints:

// 3 <= s.length <= 105
// s consists of only lowercase English letters.





// 🚀 Approach
// Traverse the string once to record the first and last occurrence of each character (a–z).
// For each character:
//     If it appears at least twice, consider the substring between its first and last occurrence.
//     Collect all distinct characters in that range (using a set).
//     The size of the set equals the number of unique palindromes formed with that character as the outer pair.
// Sum these counts across all characters to get the final result.

// 🕛 Complexity
// Time complexity: O(n)
// Space complexity: O(26)












class Solution {
    public int countPalindromicSubsequence(String s) {
        int n = s.length();

        int[][] indices = new int[26][2];
        for (int i = 0; i < 26; i++) {
            indices[i][0] = -1; 
            indices[i][1] = -1; 
        }
        
        for (int i = 0; i < n; i++) {
            int idx = s.charAt(i) - 'a';
            if (indices[idx][0] == -1) {
                indices[idx][0] = i;
            }
            indices[idx][1] = i;
        }

        int res = 0;
        for (int i = 0; i < 26; i++) {
            int leftIdx = indices[i][0];
            int rightIdx = indices[i][1];
            
            if (leftIdx == -1) continue; 
            
            HashSet<Character> set = new HashSet<>();
            for (int mid = leftIdx + 1; mid <= rightIdx - 1; mid++) {
                set.add(s.charAt(mid));
            }
            res += set.size();
        }
        return res;
    }
}
