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
public:
    bool isBalanced(vector<int>& freq) {
        int commonFreq = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) continue;

            if (commonFreq == 0) commonFreq = freq[i];
            else if (freq[i] != commonFreq) return false;
        }
        return true;
    }

    int longestBalanced(string s) {
        int n = s.size();
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            vector<int> freq(26 , 0);
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++;

                if (isBalanced(freq)) maxLen = max(maxLen , j - i + 1);
            }
        }
        return maxLen;
    }
};