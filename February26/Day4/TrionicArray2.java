// LEETCODE 3640. Trionic Array II

// You are given an integer array nums of length n.

// A trionic subarray is a contiguous subarray nums[l...r] (with 0 <= l < r < n) for which there exist indices l < p < q < r such that:

// nums[l...p] is strictly increasing,
// nums[p...q] is strictly decreasing,
// nums[q...r] is strictly increasing.
// Return the maximum sum of any trionic subarray in nums.

 

// Example 1:

// Input: nums = [0,-2,-1,-3,0,2,-1]

// Output: -4

// Explanation:

// Pick l = 1, p = 2, q = 3, r = 5:

// nums[l...p] = nums[1...2] = [-2, -1] is strictly increasing (-2 < -1).
// nums[p...q] = nums[2...3] = [-1, -3] is strictly decreasing (-1 > -3)
// nums[q...r] = nums[3...5] = [-3, 0, 2] is strictly increasing (-3 < 0 < 2).
// Sum = (-2) + (-1) + (-3) + 0 + 2 = -4.
// Example 2:

// Input: nums = [1,4,2,7]

// Output: 14

// Explanation:

// Pick l = 0, p = 1, q = 2, r = 3:

// nums[l...p] = nums[0...1] = [1, 4] is strictly increasing (1 < 4).
// nums[p...q] = nums[1...2] = [4, 2] is strictly decreasing (4 > 2).
// nums[q...r] = nums[2...3] = [2, 7] is strictly increasing (2 < 7).
// Sum = 1 + 4 + 2 + 7 = 14.
 

// Constraints:

// 4 <= n = nums.length <= 105
// -109 <= nums[i] <= 109
// It is guaranteed that at least one trionic subarray exists.


// 🚀 Approach
// Traverse the array with an outer loop starting at index i.
// First segment (increasing):
//     Move forward while the sequence is strictly increasing.
//     Mark the end of this segment as p.
//     If no valid increasing segment exists, skip.
// Second segment (decreasing):
//     Add the last two elements of the first segment to the sum.
//     Continue forward while the sequence is strictly decreasing.
//     Mark the end of this segment as q.
//     If invalid (too short, ends at the last element, or doesn’t allow transition), skip.
// Third segment (increasing again):
//     Add the first element of the third segment.
//     Traverse forward while strictly increasing, computing the maximum possible sum of a contiguous subarray.
//     Add this maximum to the result.
// Extend the first segment backwards:
//     Traverse backward from p - 2 to i, computing the maximum possible sum of a contiguous subarray.
//     Add this maximum to the result.
// Update the global maximum (triMaxSum).
// Continue scanning until the entire array is processed.

// 🕛 Complexity
// Time complexity: O(n)
// Space complexity: O(1)









import java.util.*;

class Solution {
    public long maxSumTrionic(int[] nums) {
        int n = nums.length;
        int p, q, j;
        long maxSum, sum, res;
        long triMaxSum = Long.MIN_VALUE;

        for (int i = 0; i < n; i++) {
            j = i + 1;
            res = 0;

            // First segment: strictly increasing
            while (j < n && nums[j - 1] < nums[j]) {
                j++;
            }
            p = j - 1;
            if (p == i) continue;

            // Second segment: strictly decreasing
            res += nums[p] + nums[p - 1];
            while (j < n && nums[j - 1] > nums[j]) {
                res += nums[j];
                j++;
            }

            q = j - 1;
            if (q == p || q == n - 1 || (nums[j] <= nums[q])) {
                i = q;
                continue;
            }

            // Third segment: start with first element
            res += nums[q + 1];
            maxSum = 0;
            sum = 0;

            // Extend third segment (increasing)
            for (int k = q + 2; k < n && nums[k] > nums[k - 1]; k++) {
                sum += nums[k];
                maxSum = Math.max(maxSum, sum);
            }
            res += maxSum;

            // Extend first segment (backward)
            maxSum = 0;
            sum = 0;
            for (int k = p - 2; k >= i; k--) {
                sum += nums[k];
                maxSum = Math.max(maxSum, sum);
            }
            res += maxSum;

            // Update global maximum
            triMaxSum = Math.max(triMaxSum, res);
            i = q - 1;
        }
        return triMaxSum;
    }
}