// LEETCODE 3541. Find Most Frequent Vowel and Consonant

// You are given a string s consisting of lowercase English letters ('a' to 'z').

// Your task is to:

// Find the vowel (one of 'a', 'e', 'i', 'o', or 'u') with the maximum frequency.
// Find the consonant (all other letters excluding vowels) with the maximum frequency.
// Return the sum of the two frequencies.

// Note: If multiple vowels or consonants have the same maximum frequency, you may choose any one of them. If there are no vowels or no consonants in the string, consider their frequency as 0.

// The frequency of a letter x is the number of times it occurs in the string.
 

// Example 1:

// Input: s = "successes"

// Output: 6

// Explanation:

// The vowels are: 'u' (frequency 1), 'e' (frequency 2). The maximum frequency is 2.
// The consonants are: 's' (frequency 4), 'c' (frequency 2). The maximum frequency is 4.
// The output is 2 + 4 = 6.
// Example 2:

// Input: s = "aeiaeia"

// Output: 3

// Explanation:

// The vowels are: 'a' (frequency 3), 'e' ( frequency 2), 'i' (frequency 2). The maximum frequency is 3.
// There are no consonants in s. Hence, maximum consonant frequency = 0.
// The output is 3 + 0 = 3.
 

// Constraints:

// 1 <= s.length <= 100
// s consists of lowercase English letters only.


// 🚀 Approach
// Use a Map to count character frequencies.
// For each character in the string:
//     Increment its count in the map.
//     If it's a vowel (a, e, i, o, u), update cntV with the max frequency seen so far.
//     Otherwise, treat it as a consonant and update cntC.
// Return the sum of cntV and cntC.




class Solution {
    public int maxFreqSum(String s) {
        int cntV = 0, cntC = 0;
        Map<Character, Integer> mp = new HashMap<>();

        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            mp.put(ch , mp.getOrDefault(ch , 0) + 1);

            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') 
                cntV = Math.max(cntV , mp.get(ch));
            else cntC = Math.max(cntC , mp.get(ch));
        }
        
        return cntV + cntC;
    }
}