// LEETCODE 1415. The k-th Lexicographical String of All Happy Strings of Length n

// A happy string is a string that:

// consists only of letters of the set ['a', 'b', 'c'].
// s[i] != s[i + 1] for all values of i from 1 to s.length - 1 (string is 1-indexed).
// For example, strings "abc", "ac", "b" and "abcbabcbcb" are all happy strings and strings "aa", "baa" and "ababbc" are not happy strings.

// Given two integers n and k, consider a list of all happy strings of length n sorted in lexicographical order.

// Return the kth string of this list or return an empty string if there are less than k happy strings of length n.

 

// Example 1:

// Input: n = 1, k = 3
// Output: "c"
// Explanation: The list ["a", "b", "c"] contains all happy strings of length 1. The third string is "c".
// Example 2:

// Input: n = 1, k = 4
// Output: ""
// Explanation: There are only 3 happy strings of length 1.
// Example 3:

// Input: n = 3, k = 9
// Output: "cab"
// Explanation: There are 12 different happy string of length 3 ["aba", "abc", "aca", "acb", "bab", "bac", "bca", "bcb", "cab", "cac", "cba", "cbc"]. You will find the 9th string = "cab"
 

// Constraints:

// 1 <= n <= 10
// 1 <= k <= 100


// 🚀 Approach
// Recursive DFS (Backtracking):
//     Start with an empty string happy.
//     At each step, try adding 'a', 'b', or 'c'.
//     Skip adding the same character as the last one (to maintain the "happy" property).
//     Continue until the string length reaches n.
// Counting:
//     Maintain a counter cnt to track how many happy strings have been generated so far.
//     When cnt == k, store the current string as the answer (res).
// Lexicographical Order:
//     Since we iterate characters in order 'a' → 'b' → 'c', the recursion naturally generates strings in lexicographical order.
    
// 🕛 Complexity
// Time complexity: O(n * 2ⁿ)
// Space complexity: O(n)









class Solution {
    public void solve(int n, StringBuilder curr, int[] count, int k, String[] result) {
        if (curr.length() == n) {
            count[0]++;
            if (count[0] == k) {
                result[0] = curr.toString(); 
            }
            return;
        }
        
        for (char ch = 'a'; ch <= 'c'; ch++) {
            if (curr.length() > 0 && curr.charAt(curr.length() - 1) == ch) continue; 

            // Do
            curr.append(ch);

            // Explore
            solve(n, curr, count, k, result);

            if (!result[0].isEmpty()) return;

            // Undo
            curr.deleteCharAt(curr.length() - 1);
        }
    }

    public String getHappyString(int n, int k) {
        StringBuilder curr = new StringBuilder();
        String[] result = {""}; 
        int[] count = {0}; 
        
        solve(n, curr, count, k, result);

        return result[0];
    }
}