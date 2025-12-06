// LEETCODE 3578. Count Partitions With Max-Min Difference at Most K

// You are given an integer array nums and an integer k. Your task is to partition nums into one or more non-empty contiguous segments such that in each segment, the difference between its maximum and minimum elements is at most k.

// Return the total number of ways to partition nums under this condition.

// Since the answer may be too large, return it modulo 109 + 7.

 

// Example 1:

// Input: nums = [9,4,1,3,7], k = 4

// Output: 6

// Explanation:

// There are 6 valid partitions where the difference between the maximum and minimum elements in each segment is at most k = 4:

// [[9], [4], [1], [3], [7]]
// [[9], [4], [1], [3, 7]]
// [[9], [4], [1, 3], [7]]
// [[9], [4, 1], [3], [7]]
// [[9], [4, 1], [3, 7]]
// [[9], [4, 1, 3], [7]]
// Example 2:

// Input: nums = [3,3,4], k = 0

// Output: 2

// Explanation:

// There are 2 valid partitions that satisfy the given conditions:

// [[3], [3], [4]]
// [[3, 3], [4]]
 

// Constraints:

// 2 <= nums.length <= 5 * 104
// 1 <= nums[i] <= 109
// 0 <= k <= 109



// 🚀 Approach
// Dynamic Programming Setup:
//     dp[i] = number of ways to partition the first i elements.
//     prefix[i] = cumulative sum of dp[0..i - 1] for fast range queries.

// Sliding Window with Deques:
//     Use two deques (minQ , maxQ) to maintain the minimum and maximum in the current window efficiently.
//     Adjust the left boundary l whenever the difference max - min > k.
// Transition:
//     For each index i, the valid partitions end at i but must start at some l ≤ start ≤ i.
//     Thus, dp[i + 1] = prefix[i + 1] - prefix[l].
//     Update prefix: prefix[i + 2] = prefix[i + 1] + dp[i + 1].
//     Return dp[n], the number of ways to partition the entire array.


// 🕛 Complexity
// Time complexity: O(n)
// Space complexity: O(n)











class Solution {
    public int countPartitions(int[] nums, int k) {
        final int MOD = 1_000_000_007;
        int n = nums.length;

        long[] dp = new long[n + 1];
        long[] prefix = new long[n + 2];
        dp[0] = 1;
        prefix[1] = 1;

        Deque<Integer> minQ = new ArrayDeque<>();
        Deque<Integer> maxQ = new ArrayDeque<>();
        int l = 0;

        for (int i = 0; i < n; i++) {
            while (!maxQ.isEmpty() && nums[maxQ.peekLast()] <= nums[i]) {
                maxQ.pollLast();
            }
            while (!minQ.isEmpty() && nums[minQ.peekLast()] >= nums[i]) {
                minQ.pollLast();
            }

            maxQ.addLast(i);
            minQ.addLast(i);

            while (nums[maxQ.peekFirst()] - nums[minQ.peekFirst()] > k) {
                if (maxQ.peekFirst() == l) {
                    maxQ.pollFirst();
                }
                if (minQ.peekFirst() == l) {
                    minQ.pollFirst();
                }
                l++;
            }

            dp[i + 1] = (prefix[i + 1] - prefix[l] + MOD) % MOD;
            prefix[i + 2] = (prefix[i + 1] + dp[i + 1]) % MOD;
        }
        return (int) dp[n];
    }
}