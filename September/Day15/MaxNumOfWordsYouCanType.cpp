// LEETCODE 1935. Maximum Number of Words You Can Type

// There is a malfunctioning keyboard where some letter keys do not work. All other keys on the keyboard work properly.

// Given a string text of words separated by a single space (no leading or trailing spaces) and a string brokenLetters of all distinct letter keys that are broken, return the number of words in text you can fully type using this keyboard.

 

// Example 1:

// Input: text = "hello world", brokenLetters = "ad"
// Output: 1
// Explanation: We cannot type "world" because the 'd' key is broken.
// Example 2:

// Input: text = "leet code", brokenLetters = "lt"
// Output: 1
// Explanation: We cannot type "leet" because the 'l' and 't' keys are broken.
// Example 3:

// Input: text = "leet code", brokenLetters = "e"
// Output: 0
// Explanation: We cannot type either word because the 'e' key is broken.
 

// Constraints:

// 1 <= text.length <= 104
// 0 <= brokenLetters.length <= 26
// text consists of words separated by a single space without any leading or trailing spaces.
// Each word only consists of lowercase English letters.
// brokenLetters consists of distinct lowercase English letters.


// 🚀 Approach
// Mark broken letters using a boolean array for constant-time lookup.
// Split the input text into words.
// For each word, check if it contains any broken letter.
// If not, increment the cnt.




class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        bool isBroken[26] = {false};
        for (char ch : brokenLetters) isBroken[ch - 'a'] = true;

        stringstream ss(text);
        string word;
        int cnt = 0;

        while(ss >> word) {
            bool canType = true;
            for (char ch : word) {
                if (isBroken[ch - 'a']) {
                    canType = false;
                    break;
                }
            }
            if (canType) cnt++;
        }
        return cnt;
    }
};
