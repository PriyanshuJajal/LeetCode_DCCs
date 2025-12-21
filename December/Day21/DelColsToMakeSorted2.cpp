// LEETCODE 955. Delete Columns to Make Sorted II

// You are given an array of n strings strs, all of the same length.

// We may choose any deletion indices, and we delete all the characters in those indices for each string.

// For example, if we have strs = ["abcdef","uvwxyz"] and deletion indices {0, 2, 3}, then the final array after deletions is ["bef", "vyz"].

// Suppose we chose a set of deletion indices answer such that after deletions, the final array has its elements in lexicographic order (i.e., strs[0] <= strs[1] <= strs[2] <= ... <= strs[n - 1]). Return the minimum possible value of answer.length.

 

// Example 1:

// Input: strs = ["ca","bb","ac"]
// Output: 1
// Explanation: 
// After deleting the first column, strs = ["a", "b", "c"].
// Now strs is in lexicographic order (ie. strs[0] <= strs[1] <= strs[2]).
// We require at least 1 deletion since initially strs was not in lexicographic order, so the answer is 1.
// Example 2:

// Input: strs = ["xc","yb","za"]
// Output: 0
// Explanation: 
// strs is already in lexicographic order, so we do not need to delete anything.
// Note that the rows of strs are not necessarily in lexicographic order:
// i.e., it is NOT necessarily true that (strs[0][0] <= strs[0][1] <= ...)
// Example 3:

// Input: strs = ["zyx","wvu","tsr"]
// Output: 3
// Explanation: We have to delete every column.
 

// Constraints:

// n == strs.length
// 1 <= n <= 100
// 1 <= strs[i].length <= 100
// strs[i] consists of lowercase English letters.







// 🚀 Approach
// Let n be the number of strings and m their length.
// Maintain an array sorted[n - 1] where sorted[i] indicates whether the order between strs[i] and strs[i + 1] has already been confirmed.
//     Initially, all entries are 0 (not yet confirmed).
// Iterate column by column:
//     For each column, check all pairs (strs[i], strs[i + 1]) where sorted[i] == 0.
//     If any pair violates lexicographic order (strs[i][j] > strs[i + 1][j]), we must d**elete this column (cnt++) and skip updating.
//     Otherwise, update sorted[i] = 1 if strs[i][j] < strs[i + 1][j].
// Continue until all columns are processed.
// Return the total number of deletions.
// This greedy approach works because once a pair of rows is confirmed sorted, we don’t need to check them again in later columns.

// 🕛 Complexity
// Time complexity: O(n * m)
// Space complexity: O(n)













class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        int cnt = 0;
        vector<int> sorted(n - 1 , 0);

        for (int j = 0; j < m; j++) {
            bool toDel = false;
            for (int i = 0; i < n - 1; i++) {
                if (!sorted[i] && strs[i][j] > strs[i + 1][j]) {
                    toDel = true;
                    break;
                }
            }
            if (toDel) {
                cnt++;
                continue;
            }

            for (int i = 0; i < n - 1; i++) {
                if (!sorted[i] && strs[i][j] < strs[i + 1][j]) sorted[i] = 1;
            }
        }
        return cnt;
    }
};