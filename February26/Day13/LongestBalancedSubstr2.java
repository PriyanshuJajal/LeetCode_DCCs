// LEETCODE 3714. Longest Balanced Substring II

// You are given a string s consisting only of the characters 'a', 'b', and 'c'.

// A substring of s is called balanced if all distinct characters in the substring appear the same number of times.

// Return the length of the longest balanced substring of s.

 

// Example 1:

// Input: s = "abbac"

// Output: 4

// Explanation:

// The longest balanced substring is "abba" because both distinct characters 'a' and 'b' each appear exactly 2 times.

// Example 2:

// Input: s = "aabcc"

// Output: 3

// Explanation:

// The longest balanced substring is "abc" because all distinct characters 'a', 'b' and 'c' each appear exactly 1 time.

// Example 3:

// Input: s = "aba"

// Output: 2

// Explanation:

// One of the longest balanced substrings is "ab" because both distinct characters 'a' and 'b' each appear exactly 1 time. Another longest balanced substring is "ba".

 

// Constraints:

// 1 <= s.length <= 105
// s contains only the characters 'a', 'b', and 'c'.



// 🚀 Approach
// Case 1: Single character substrings
//     Traverse the string and count consecutive identical characters.
//     Update maxLen with the longest streak.
// Case 2: Two-character substrings
//     Use a helper function solve(s , ch1 , ch2):
//         Maintain counts of ch1 and ch2.
//         Use a hashmap to store the first index where a given difference (cnt1 - cnt2) occurred.
//         If the difference repeats, the substring between those indices is balanced.
//         Update maxLen accordingly.
// Case 3: Three-character substrings
//     Maintain counts of a, b, and c.
//     Use a hashmap keyed by (cntA - cntB , cntA - cntC) to track differences.
//     If the same key reappears, the substring between those indices is balanced.
//     Update maxLen.
//     Return the maximum length found across all cases.

// 🕛 Complexity
// Time complexity: O(nlogn)
// Space complexity: O(n)









import java.util.*;

class Solution {
    private int solve(String s, char ch1, char ch2) {
        int n = s.length();
        int maxLen = 0;

        Map<Integer, Integer> diffMap = new HashMap<>();
        int cnt1 = 0, cnt2 = 0;

        for (int i = 0; i < n; i++) {
            char c = s.charAt(i);

            if (c != ch1 && c != ch2) {
                diffMap.clear();
                cnt1 = 0;
                cnt2 = 0;
            }

            if (c == ch1) cnt1++;
            if (c == ch2) cnt2++;

            if (cnt1 == cnt2) {
                maxLen = Math.max(maxLen, cnt1 + cnt2);
            }

            int diff = cnt1 - cnt2;
            if (diffMap.containsKey(diff)) {
                maxLen = Math.max(maxLen, i - diffMap.get(diff));
            } else {
                diffMap.put(diff, i);
            }
        }

        return maxLen;
    }

    public int longestBalanced(String s) {
        int n = s.length();
        int maxLen = 0;

        // Case 1 -> single character streaks
        int cnt = 1;
        for (int i = 1; i < n; i++) {
            if (s.charAt(i) == s.charAt(i - 1)) {
                cnt++;
            } else {
                maxLen = Math.max(maxLen, cnt);
                cnt = 1;
            }
        }
        maxLen = Math.max(maxLen, cnt);


        // Case 2 -> two characters balanced
        maxLen = Math.max(maxLen, solve(s, 'a', 'b'));
        maxLen = Math.max(maxLen, solve(s, 'a', 'c'));
        maxLen = Math.max(maxLen, solve(s, 'b', 'c'));


        // Case 3 -> all three characters balanced
        int cntA = 0, cntB = 0, cntC = 0;
        Map<String, Integer> mp = new HashMap<>();

        for (int i = 0; i < n; i++) {
            char c = s.charAt(i);
            if (c == 'a') cntA++;
            if (c == 'b') cntB++;
            if (c == 'c') cntC++;

            if (cntA == cntB && cntA == cntC) {
                maxLen = Math.max(maxLen, cntA + cntB + cntC);
            }

            int diffAB = cntA - cntB;
            int diffAC = cntA - cntC;

            String key = diffAB + "_" + diffAC;

            if (mp.containsKey(key)) {
                maxLen = Math.max(maxLen, i - mp.get(key));
            } else {
                mp.put(key, i);
            }
        }

        return maxLen;
    }
}