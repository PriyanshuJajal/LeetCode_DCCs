// LEETCODE 3381. Maximum Subarray Sum With Length Divisible by K

// You are given an array of integers nums and an integer k.

// Return the maximum sum of a subarray of nums, such that the size of the subarray is divisible by k.

 

// Example 1:

// Input: nums = [1,2], k = 1

// Output: 3

// Explanation:

// The subarray [1, 2] with sum 3 has length equal to 2 which is divisible by 1.

// Example 2:

// Input: nums = [-1,-2,-3,-4,-5], k = 4

// Output: -10

// Explanation:

// The maximum sum subarray is [-1, -2, -3, -4] which has length equal to 4 which is divisible by 4.

// Example 3:

// Input: nums = [-5,1,2,-3,4], k = 2

// Output: 4

// Explanation:

// The maximum sum subarray is [1, 2, -3, 4] which has length equal to 4 which is divisible by 2.

 

// Constraints:

// 1 <= k <= nums.length <= 2 * 105
// -109 <= nums[i] <= 109




// 🚀 Approach
// Compute prefix sums incrementally while iterating through the array.
// For each index i, calculate pref = P[i + 1] and its modulo class mod = (i + 1) % k.
// To maximize the subarray sum ending at i, we need the smallest prefix sum among all earlier indices l with l % k == mod. This ensures the subarray length is divisible by k.
// Maintain an array minPref of size k where minPref[mod] stores the minimum prefix sum seen so far for that modulo class.
// Initialize minPref[0] = 0 to allow subarrays starting at index 0.
// At each step:
//     Compute candidate sum as pref - minPref[mod].
//     Update maxSum if this candidate is larger.
//     Update minPref[mod] with the current prefix sum if it is smaller.
// Return the maximum sum found.


// 🕛 Complexity
// Time complexity: O(n)
// Space complexity: O(k)













class Solution {
    public long maxSubarraySum(int[] nums, int k) {
        int n = nums.length;
        long maxSum = Long.MIN_VALUE;
        long pref = 0;
        long[] minPref = new long[k];

        for (int i = 0; i < k; i++) {
            minPref[i] = Long.MAX_VALUE;
        }

        minPref[0] = 0;
        for (int i = 0; i < n; i++) {
            pref += nums[i];
            int mod = (i + 1) % k;

            if (minPref[mod] != Long.MAX_VALUE) {
                maxSum = Math.max(maxSum , pref - minPref[mod]);
            }
            minPref[mod] = Math.min(minPref[mod] , pref);
        }
        return maxSum;
    }
}
