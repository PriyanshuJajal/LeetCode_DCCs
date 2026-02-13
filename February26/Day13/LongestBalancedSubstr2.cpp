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









class Solution {
public:
    int solve(string& s , int ch1 , int ch2) {
        int n = s.length();
        int maxLen = 0;

        unordered_map<int , int> diffMap;
        int cnt1 = 0;
        int cnt2 = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] != ch1 && s[i] != ch2) {
                diffMap.clear();
                cnt1 = 0;
                cnt2 = 0;
            }

            if (s[i] == ch1) cnt1++;
            if (s[i] == ch2) cnt2++;

            if (cnt1 == cnt2) {
                maxLen = max(maxLen , cnt1 + cnt2);
            }

            int diff = cnt1 - cnt2;
            if (diffMap.count(diff)) maxLen = max(maxLen , i - diffMap[diff]);
            else diffMap[diff] = i;
        }

        return maxLen;
    }

    int longestBalanced(string s) {
        int n = s.length();
        int maxLen = 0;

        // Case 1 -> 1 char contributes to the result...
        int cnt = 1;
        for (int i = 1; i < n; i++) {
            if (s[i] == s[i - 1]) cnt++;
            else {
                maxLen = max(maxLen , cnt);
                cnt = 1;
            }
        }
        maxLen = max(maxLen , cnt);


        // Case 2 -> 2 chars contributes to the result...
        maxLen = max(maxLen , solve(s , 'a' , 'b'));
        maxLen = max(maxLen , solve(s , 'a' , 'c'));
        maxLen = max(maxLen , solve(s , 'b' , 'c'));


        // Case 3 -> all 3 chars contributes to the result...
        int cntA = 0;
        int cntB = 0;
        int cntC = 0;
        unordered_map<string , int> mp;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'a') cntA++;
            if (s[i] == 'b') cntB++;
            if (s[i] == 'c') cntC++;

            if (cntA == cntB && cntA == cntC) {
                maxLen = max(maxLen , cntA + cntB + cntC);
            }

            int diffAB = cntA - cntB;
            int diffAC = cntA - cntC;

            string key = to_string(diffAB) + "_" + to_string(diffAC);

            if (mp.count(key)) {
                maxLen = max(maxLen , i - mp[key]);
            } 
            else mp[key] = i;
        }
        return maxLen;
    }
};