// LEETCODE 1358. Number of Substrings Containing All Three Characters

// Given a string s consisting only of characters a, b and c.

// Return the number of substrings containing at least one occurrence of all these characters a, b and c.

// Example 1:

// Input: s = "abcabc"
// Output: 10
// Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 
// Example 2:

// Input: s = "aaacb"
// Output: 3
// Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 
// Example 3:

// Input: s = "abc"
// Output: 1
 

// Constraints:

// 3 <= s.length <= 5 x 10^4
// s only consists of a, b or c characters.

// Time complexity: O(n)
// Space complexity: O(1)




class Solution {
public:
    bool hasABC(vector<int>& freq) {
        return freq[0] > 0 && freq[1] > 0 && freq[2] > 0;
    } 

    int numberOfSubstrings(string s) {
        int n = s.length();
        int l = 0 , r = 0;
        vector<int> freq(3 , 0);
        int cnt = 0;

        while(r < n) {
            char ch = s[r];
            freq[ch - 'a']++;

            while(hasABC(freq)) {
                cnt += n - r;

                char leftCh = s[l];
                freq[leftCh - 'a']--;
                l++;
            }
            r++;
        }
        return cnt;
    }
};