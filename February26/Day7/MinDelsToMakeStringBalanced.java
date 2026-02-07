// LEETCODE 1653. Minimum Deletions to Make String Balanced

// You are given a string s consisting only of characters 'a' and 'b'​​​​.

// You can delete any number of characters in s to make s balanced. s is balanced if there is no pair of indices (i,j) such that i < j and s[i] = 'b' and s[j]= 'a'.

// Return the minimum number of deletions needed to make s balanced.

 

// Example 1:

// Input: s = "aababbab"
// Output: 2
// Explanation: You can either:
// Delete the characters at 0-indexed positions 2 and 6 ("aababbab" -> "aaabbb"), or
// Delete the characters at 0-indexed positions 3 and 6 ("aababbab" -> "aabbbb").
// Example 2:

// Input: s = "bbaaaaabb"
// Output: 2
// Explanation: The only solution is to delete the first two characters.
 

// Constraints:

// 1 <= s.length <= 105
// s[i] is 'a' or 'b'​​.


// 🚀 Approach
// Traverse the string from left to right.
// Maintain:
//     bCnt: the number of b characters seen so far.
//     minDels: the minimum deletions required up to the current position.
// For each character:
//     If it’s b, increment bCnt.
//     If it’s a, we have two options:
//         Delete this a → cost = minDels + 1.
//         Delete one of the previous b characters → cost = bCnt.
//         Take the minimum of these two.
// At the end, minDels gives the minimum deletions required.

// 🕛 Complexity
// Time complexity: O(n)
// Space complexity: O(1)









class Solution {
    public int minimumDeletions(String s) {
        int n = s.length();
        int minDels = 0;
        int bCnt = 0;

        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == 'b') bCnt++
            else minDels = Math.min(minDels + 1 , bCnt);
        }
        return minDels;
    }
}