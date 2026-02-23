// LEETCODE 1461. Check If a String Contains All Binary Codes of Size K

// Given a binary string s and an integer k, return true if every binary code of length k is a substring of s. Otherwise, return false.

 

// Example 1:

// Input: s = "00110110", k = 2
// Output: true
// Explanation: The binary codes of length 2 are "00", "01", "10" and "11". They can be all found as substrings at indices 0, 1, 3 and 2 respectively.
// Example 2:

// Input: s = "0110", k = 1
// Output: true
// Explanation: The binary codes of length 1 are "0" and "1", it is clear that both exist as a substring. 
// Example 3:

// Input: s = "0110", k = 2
// Output: false
// Explanation: The binary code "00" is of length 2 and does not exist in the array.
 

// Constraints:

// 1 <= s.length <= 5 * 105
// s[i] is either '0' or '1'.
// 1 <= k <= 20



// 🚀 Approach
// Use a sliding window of size k to extract every substring of length k from s.
// Insert each substring into an unordered_set (to avoid duplicates).
// After processing the entire string:
//     If the size of the set equals 2^k, it means all possible binary codes of length k are present.
//     Otherwise, some codes are missing.

// 🕛 Complexity
// Time complexity: O(n * k)
// Space complexity: O(2^k * k)









import java.util.HashSet;

class Solution {
    public boolean hasAllCodes(String s, int k) {
        HashSet<String> set = new HashSet<>();
        
        for (int i = 0; i + k <= s.length(); i++) {
            set.add(s.substring(i, i + k));
        }
        
        return set.size() == (int) Math.pow(2, k);
    }
}