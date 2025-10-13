// LEETCODE 2273. Find Resultant Array After Removing Anagrams

// You are given a 0-indexed string array words, where words[i] consists of lowercase English letters.

// In one operation, select any index i such that 0 < i < words.length and words[i - 1] and words[i] are anagrams, and delete words[i] from words. Keep performing this operation as long as you can select an index that satisfies the conditions.

// Return words after performing all operations. It can be shown that selecting the indices for each operation in any arbitrary order will lead to the same result.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase using all the original letters exactly once. For example, "dacb" is an anagram of "abdc".

 

// Example 1:

// Input: words = ["abba","baba","bbaa","cd","cd"]
// Output: ["abba","cd"]
// Explanation:
// One of the ways we can obtain the resultant array is by using the following operations:
// - Since words[2] = "bbaa" and words[1] = "baba" are anagrams, we choose index 2 and delete words[2].
//   Now words = ["abba","baba","cd","cd"].
// - Since words[1] = "baba" and words[0] = "abba" are anagrams, we choose index 1 and delete words[1].
//   Now words = ["abba","cd","cd"].
// - Since words[2] = "cd" and words[1] = "cd" are anagrams, we choose index 2 and delete words[2].
//   Now words = ["abba","cd"].
// We can no longer perform any operations, so ["abba","cd"] is the final answer.
// Example 2:

// Input: words = ["a","b","c","d","e"]
// Output: ["a","b","c","d","e"]
// Explanation:
// No two adjacent strings in words are anagrams of each other, so no operations are performed.
 

// Constraints:

// 1 <= words.length <= 100
// 1 <= words[i].length <= 10
// words[i] consists of lowercase English letters.



// 🚀 Approach
// Anagram Check:
//     Use a frequency array freq of size 26 (for lowercase English letters).
//     Increment counts for characters in s1, decrement for s2.
//     If all counts are zero, the words are anagrams.
// Main Logic:
//     Initialize the result res with the first word.
//     Iterate from the second word onward.
//     Compare each word with the last word in the result using checkAnagram.
//     If not an anagram, add it to the res.







class Solution {
    boolean checkAnagram(String s1 , String s2) {
        int[] freq = new int[26];
        for (char ch : s1.toCharArray()) freq[ch - 'a']++;
        for (char ch : s2.toCharArray()) freq[ch - 'a']--;

        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0) return false;
        }   
        return true;
    }

    public List<String> removeAnagrams(String[] words) {
        int n = words.length;
        List<String> res = new ArrayList<>();

        res.add(words[0]);
        for (int i = 1; i < n; i++) {
            if (!checkAnagram(words[i] , res.get(res.size() - 1))) res.add(words[i]);
        }
        return res;
    }
}