// LEETCODE 1189. Maximum Number of Balloons

// Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.

// You can use each character in text at most once. Return the maximum number of instances that can be formed.


// Example 1:

// Input: text = "nlaebolko"
// Output: 1
// Example 2:



// Input: text = "loonbalxballpoon"
// Output: 2
// Example 3:

// Input: text = "leetcode"
// Output: 0
 

// Constraints:

// 1 <= text.length <= 104
// text consists of lower case English letters only.
 

// 🚀 Approach
// Use a fixed-size array f[26] to count the frequency of each lowercase letter in the input string.
// Check if the minimum required characters ('b', 'a', 'l', 'o', 'n') exist in sufficient quantity.
// For 'l' and 'o', divide their counts by 2 since they appear twice in "balloon".
// Return the minimum of:
//     minFreqOfLO / 2 → how many times we can satisfy the double-letter requirement.
//     minFreqOfBAN → how many times we can satisfy the single-letter requirement.

// 🕛 Complexity
// Time complexity: O(n)
// Space complexity: O(1)



class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int f[26] = {0};
        for (char ch : text) f[ch - 'a']++;

        if (f['l' - 'a'] <= 1 || f['o' - 'a'] <= 1) return 0;
        if (f['b' - 'a'] < 1 || f['a' - 'a'] < 1 || f['n' - 'a'] < 1) return 0;

        int minFreqOfLO = min(f['l' - 'a'] , f['o' - 'a']);
        int minFreqOfBAN = min({f['b' - 'a'] , f['a' - 'a'] , f['n' - 'a']});

        return min(minFreqOfLO / 2 , minFreqOfBAN);
    }
};