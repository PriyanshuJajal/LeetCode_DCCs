// LEETCODE 2840. Check if Strings Can be Made Equal With Operations II

// You are given two strings s1 and s2, both of length n, consisting of lowercase English letters.

// You can apply the following operation on any of the two strings any number of times:

// Choose any two indices i and j such that i < j and the difference j - i is even, then swap the two characters at those indices in the string.
// Return true if you can make the strings s1 and s2 equal, and false otherwise.

 

// Example 1:

// Input: s1 = "abcdba", s2 = "cabdab"
// Output: true
// Explanation: We can apply the following operations on s1:
// - Choose the indices i = 0, j = 2. The resulting string is s1 = "cbadba".
// - Choose the indices i = 2, j = 4. The resulting string is s1 = "cbbdaa".
// - Choose the indices i = 1, j = 5. The resulting string is s1 = "cabdab" = s2.
// Example 2:

// Input: s1 = "abe", s2 = "bea"
// Output: false
// Explanation: It is not possible to make the two strings equal.
 

// Constraints:

// n == s1.length == s2.length
// 1 <= n <= 105
// s1 and s2 consist only of lowercase English letters.


// 🚀 Approach
// Traverse both strings simultaneously.
// For each index i:
//     If i is even, increment the count of s1[i] in the even array and decrement the count of s2[i].
//     If i is odd, increment the count of s1[i] in the odd array and decrement the count of s2[i].
// After processing all characters, check if all counts in both arrays are zero.
//     If yes, the strings can be made equal.
//     Otherwise, they cannot.

// 🕛 Complexity
// Time complexity: O(n)
// Space complexity: O(1)









class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.length();
        int even[26] = {0};
        int odd[26] = {0};

        for (int i = 0; i < n; i++) {
            if (i & 1) {
                odd[s1[i] - 'a']++;
                odd[s2[i] - 'a']--;
            }
            else {
                even[s1[i] - 'a']++;
                even[s2[i] - 'a']--;
            }
        }

        for (int i = 0; i < 26; i++) {
            if (even[i] != 0 || odd[i] != 0) return false;
        }
        return true;
    }
};