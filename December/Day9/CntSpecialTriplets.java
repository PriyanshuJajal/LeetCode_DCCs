// LEETCODE 3583. Count Special Triplets

// You are given an integer array nums.

// A special triplet is defined as a triplet of indices (i, j, k) such that:

// 0 <= i < j < k < n, where n = nums.length
// nums[i] == nums[j] * 2
// nums[k] == nums[j] * 2
// Return the total number of special triplets in the array.

// Since the answer may be large, return it modulo 109 + 7.

 

// Example 1:

// Input: nums = [6,3,6]

// Output: 1

// Explanation:

// The only special triplet is (i, j, k) = (0, 1, 2), where:

// nums[0] = 6, nums[1] = 3, nums[2] = 6
// nums[0] = nums[1] * 2 = 3 * 2 = 6
// nums[2] = nums[1] * 2 = 3 * 2 = 6
// Example 2:

// Input: nums = [0,1,0,0]

// Output: 1

// Explanation:

// The only special triplet is (i, j, k) = (0, 2, 3), where:

// nums[0] = 0, nums[2] = 0, nums[3] = 0
// nums[0] = nums[2] * 2 = 0 * 2 = 0
// nums[3] = nums[2] * 2 = 0 * 2 = 0
// Example 3:

// Input: nums = [8,4,2,8,4]

// Output: 2

// Explanation:

// There are exactly two special triplets:

// (i, j, k) = (0, 1, 3)
// nums[0] = 8, nums[1] = 4, nums[3] = 8
// nums[0] = nums[1] * 2 = 4 * 2 = 8
// nums[3] = nums[1] * 2 = 4 * 2 = 8
// (i, j, k) = (1, 2, 4)
// nums[1] = 4, nums[2] = 2, nums[4] = 4
// nums[1] = nums[2] * 2 = 2 * 2 = 4
// nums[4] = nums[2] * 2 = 2 * 2 = 4
 

// Constraints:

// 3 <= n == nums.length <= 105
// 0 <= nums[i] <= 105


// 🚀 Approach
// Precompute frequencies:
//     Use a map total to store the frequency of each number in the entire array.
//     This helps us quickly know how many candidates remain on the right side of j.
// Iterate through the array:
//     For each element num (considered as the middle element j), decrement its count in total since we are processing it.
//     Compute target = 2 * num.
//     The number of valid triplets with this j is:
//     leftCnt[target] * total[target]
//     where leftCnt[target] counts how many valid i exist before j, and total[target] counts how many valid k exist after j.
// Increment leftCnt[num] to include the current element for future iterations.
// Since the count can be large, return the result modulo 10^9+7.


// 🕛 Complexity
// Time complexity: O(n)
// Space complexity: O(n) (in worst case)













class Solution {
    public int specialTriplets(int[] nums) {
        final int mod = 1_000_000_007;
        long cnt = 0;

        Map<Integer , Integer> total = new HashMap<>();
        for (int num : nums) {
            total.put(num , total.getOrDefault(num , 0) + 1);
        }

        Map<Integer , Integer> leftCnt = new HashMap<>();
        for (int num : nums) {
            total.put(num , total.get(num) - 1);

            int left = leftCnt.getOrDefault(2 * num , 0);
            int right = total.getOrDefault(2 * num , 0);

            cnt += (long) left * right;

            leftCnt.put(num , leftCnt.getOrDefault(num , 0) + 1);
        }
        return (int) (cnt % mod);
    }
}
