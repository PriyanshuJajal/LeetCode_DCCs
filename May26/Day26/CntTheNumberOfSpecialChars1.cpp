// LEETCODE 3120. Count the Number of Special Characters I

// You are given a string word. A letter is called special if it appears both in lowercase and uppercase in word.

// Return the number of special letters in word.

// Example 1:

// Input: word = "aaAbcBC"

// Output: 3

// Explanation:

// The special characters in word are 'a', 'b', and 'c'.

// Example 2:

// Input: word = "abc"

// Output: 0

// Explanation:

// No character in word appears in uppercase.

// Example 3:

// Input: word = "abBCab"

// Output: 1

// Explanation:

// The only special character in word is 'b'.

 

// Constraints:

// 1 <= word.length <= 50
// word consists of only lowercase and uppercase English letters.


// 🚀 Approach
// Create two boolean arrays of size 26:
//     lower[i] → true if lowercase 'a' + i exists.
//     upper[i] → true if uppercase 'A' + i exists.
// Traverse the string:
//     If the character is lowercase, mark lower[ch - 'a'] = true.
//     If uppercase, mark upper[ch - 'A'] = true.
// After processing, loop through all 26 letters:
//     If both lower[i] and upper[i] are true, increment the count.
// Return the count.

// 🕛 Complexity
// Time complexity: O(n)
// Space complexity: O(1)


class Solution {
public:
    int numberOfSpecialChars(string word) {
        bool lower[26] = {false};
        bool upper[26] = {false};

        for (char ch : word) {
            if (islower(ch)) {
                lower[ch - 'a'] = true;
            }
            else {
                upper[ch - 'A'] = true;
            }
        }

        int cnt = 0;
        for (int i = 0; i < 26; i++) {
            if (lower[i] && upper[i]) cnt++;
        }

        return cnt;
    }
};