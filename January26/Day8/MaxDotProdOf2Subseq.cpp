// LEETCODE 1458. Max Dot Product of Two Subsequences

// Given two arrays nums1 and nums2.

// Return the maximum dot product between non-empty subsequences of nums1 and nums2 with the same length.

// A subsequence of a array is a new array which is formed from the original array by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, [2,3,5] is a subsequence of [1,2,3,4,5] while [1,5,3] is not).

 

// Example 1:

// Input: nums1 = [2,1,-2,5], nums2 = [3,0,-6]
// Output: 18
// Explanation: Take subsequence [2,-2] from nums1 and subsequence [3,-6] from nums2.
// Their dot product is (2*3 + (-2)*(-6)) = 18.
// Example 2:

// Input: nums1 = [3,-2], nums2 = [2,-6,7]
// Output: 21
// Explanation: Take subsequence [3] from nums1 and subsequence [7] from nums2.
// Their dot product is (3*7) = 21.
// Example 3:

// Input: nums1 = [-1,-1], nums2 = [1,1]
// Output: -1
// Explanation: Take subsequence [-1] from nums1 and subsequence [1] from nums2.
// Their dot product is -1.
 

// Constraints:

// 1 <= nums1.length, nums2.length <= 500
// -1000 <= nums1[i], nums2[i] <= 1000




// 🚀 Approach
// DP Table Setup:
//     Define dp[i][j] as the maximum dot product achievable using subsequences from nums1[0..i] and nums2[0..j].
// Transition:
// For each pair (i, j):
//     Compute the product: prod = nums1[i] * nums2[j].
//     Possible choices:
//         Take only this pair: prod.
//         Extend a previous subsequence by pairing (i, j): prod + dp[i - 1][j - 1].
//         Skip nums1[i]: dp[i - 1][j].
//         Skip nums2[j]: dp[i][j - 1].
//         Take the maximum of these options.
// Initialization:
//     Start filling the DP table from (0,0) upwards.
//     Each cell ensures at least one product is considered, avoiding empty subsequences.
// The result is stored in dp[n - 1][m - 1].

// 🕛 Complexity
// Time complexity: O(n * m)
// Space complexity: O(n * m)









class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> dp(n , vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int prod = nums1[i] * nums2[j];
                int maxProd = prod;

                if (i > 0 && j > 0) {
                    maxProd = max(maxProd , maxProd + dp[i - 1][j - 1]);
                }
                if (i > 0) maxProd = max(maxProd , dp[i - 1][j]);
                if (j > 0) maxProd = max(maxProd , dp[i][j - 1]);

                dp[i][j] = maxProd;
            }
        }
        return dp[n - 1][m - 1];
    }
};
