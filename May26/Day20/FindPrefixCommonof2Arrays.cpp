// LEETCODE 2657. Find the Prefix Common Array of Two Arrays

// You are given two 0-indexed integer permutations A and B of length n.

// A prefix common array of A and B is an array C such that C[i] is equal to the count of numbers that are present at or before the index i in both A and B.

// Return the prefix common array of A and B.

// A sequence of n integers is called a permutation if it contains all integers from 1 to n exactly once.

 

// Example 1:

// Input: A = [1,3,2,4], B = [3,1,2,4]
// Output: [0,2,3,4]
// Explanation: At i = 0: no number is common, so C[0] = 0.
// At i = 1: 1 and 3 are common in A and B, so C[1] = 2.
// At i = 2: 1, 2, and 3 are common in A and B, so C[2] = 3.
// At i = 3: 1, 2, 3, and 4 are common in A and B, so C[3] = 4.
// Example 2:

// Input: A = [2,3,1], B = [3,1,2]
// Output: [0,1,3]
// Explanation: At i = 0: no number is common, so C[0] = 0.
// At i = 1: only 3 is common in A and B, so C[1] = 1.
// At i = 2: 1, 2, and 3 are common in A and B, so C[2] = 3.
 

// Constraints:

// 1 <= A.length == B.length == n <= 50
// 1 <= A[i], B[i] <= n
// It is guaranteed that A and B are both a permutation of n integers.


// 🚀 Approach
// Initialize a hash map (unordered_map) to store frequencies of elements seen so far.
// Maintain a counter cnt to track how many elements are common up to the current prefix.
// Iterate through the arrays simultaneously:
//     Add A[i] to the map. If its frequency becomes 2, increment cnt.
//     Add B[i] to the map. If its frequency becomes 2, increment cnt.
// Store the current cnt in the result array at index i.
// Continue until the end of the arrays.

// 🕛 Complexity
// Time complexity: O(n)
// Space complexity: O(n)



class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> res(n , 0);
        unordered_map<int , int> mp;
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            mp[A[i]]++;
            if (mp[A[i]] == 2) cnt++;

            mp[B[i]]++;
            if (mp[B[i]] == 2) cnt++;

            res[i] = cnt;
        }
        return res;
    }
};