// LEETCODE 3003. Maximize the Number of Partitions After Operations

// You are given a string s and an integer k.

// First, you are allowed to change at most one index in s to another lowercase English letter.

// After that, do the following partitioning operation until s is empty:

// Choose the longest prefix of s containing at most k distinct characters.
// Delete the prefix from s and increase the number of partitions by one. The remaining characters (if any) in s maintain their initial order.
// Return an integer denoting the maximum number of resulting partitions after the operations by optimally choosing at most one index to change.

 

// Example 1:

// Input: s = "accca", k = 2

// Output: 3

// Explanation:

// The optimal way is to change s[2] to something other than a and c, for example, b. then it becomes "acbca".

// Then we perform the operations:

// The longest prefix containing at most 2 distinct characters is "ac", we remove it and s becomes "bca".
// Now The longest prefix containing at most 2 distinct characters is "bc", so we remove it and s becomes "a".
// Finally, we remove "a" and s becomes empty, so the procedure ends.
// Doing the operations, the string is divided into 3 partitions, so the answer is 3.

// Example 2:

// Input: s = "aabaab", k = 3

// Output: 1

// Explanation:

// Initially s contains 2 distinct characters, so whichever character we change, it will contain at most 3 distinct characters, so the longest prefix with at most 3 distinct characters would always be all of it, therefore the answer is 1.

// Example 3:

// Input: s = "xxyz", k = 1

// Output: 4

// Explanation:

// The optimal way is to change s[0] or s[1] to something other than characters in s, for example, to change s[0] to w.

// Then s becomes "wxyz", which consists of 4 distinct characters, so as k is 1, it will divide into 4 partitions.

 

// Constraints:

// 1 <= s.length <= 104
// s consists only of lowercase English letters.
// 1 <= k <= 26



// 🚀 Approach
// Use a recursive function solve(i, uniqueChars, canChange):
//     i: current index in the string.
//     uniqueChars: bitmask representing the set of unique characters in the current partition.
// canChange: boolean flag indicating whether the one allowed change is still available.
// At each step:
//     Add the current character to the bitmask.
//     If the number of unique characters exceeds K, start a new partition.
//     If canChange is true, try replacing the current character with all 26 possibilities and choose the best outcome.
// Use a compressed key combining i, uniqueChars, and canChange for memoization.
// Return 1 + solve(0, 0, true) to count the first partition.







class Solution {
public:
    unordered_map<long long , int> mp;
    string S;
    int K;

    int solve(long long i , long long uniqueChars , bool canChange) {
        long long key = ((i << 27)  | (uniqueChars << 1) | canChange);

        if (mp.find(key) != mp.end()) return mp[key];

        if (i >= S.length()) return 0;

        int charIdx = S[i] - 'a';
        int newUniqChars = uniqueChars | (1 << charIdx);
        int uniqCharCnt = __builtin_popcount(newUniqChars);

        int res;
        if (uniqCharCnt > K) res = 1 + solve(i + 1 , (1 << charIdx) , canChange);
        else res = solve(i + 1 , newUniqChars , canChange);

        if (canChange == true) {
            for (int newCharIdx = 0; newCharIdx < 26; newCharIdx++) {
                int newCharSet = uniqueChars | (1 << newCharIdx);
                int newUniqCharCnt = __builtin_popcount(newCharSet);

                if (newUniqCharCnt > K) res = max(res , 1 + solve(i + 1 , (1 << newCharIdx) , false));
                else res = max(res , solve(i + 1 , newCharSet , false));
            }
        }
        return mp[key] = res;
    }

    int maxPartitionsAfterOperations(string s, int k) {
        S = s;
        K = k;

        return 1 + solve(0 , 0 , true);
    }
};