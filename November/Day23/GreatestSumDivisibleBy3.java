// LEETCODE 1262. Greatest Sum Divisible by Three

// Given an integer array nums, return the maximum possible sum of elements of the array such that it is divisible by three.

 

// Example 1:

// Input: nums = [3,6,5,1,8]
// Output: 18
// Explanation: Pick numbers 3, 6, 1 and 8 their sum is 18 (maximum sum divisible by 3).
// Example 2:

// Input: nums = [4]
// Output: 0
// Explanation: Since 4 is not divisible by 3, do not pick any number.
// Example 3:

// Input: nums = [1,2,3,4,4]
// Output: 12
// Explanation: Pick numbers 1, 3, 4 and 4 their sum is 12 (maximum sum divisible by 3).
 

// Constraints:

// 1 <= nums.length <= 4 * 104
// 1 <= nums[i] <= 104



// 🚀 Approach
// Compute the total sum of the array.
// 2, Track the two smallest numbers with remainder 1 (r1Min1 , r1Min2) and remainder 2 (r2Min1 , r2Min2).
//     This is necessary because sometimes we must remove two numbers of the same remainder class.
// If sum % 3 == 0, return the sum.
// If sum % 3 == 1, compute the minimum removal between r1Min1 & r2Min1 + r2Min2.
// If sum % 3 == 2, compute the minimum removal between r2Min1 & r1Min1 + r1Min2.
// Subtract the chosen removal from the sum and return the result.
// If no valid removal exists, return 0.

// 🕛 Complexity
// Time complexity: O(n)
// Space complexity: O(1)











class Solution {
    public int maxSumDivThree(int[] nums) {
        long sum = 0;
        final int INF = (int)1e9;
        int r1Min1 = INF , r1Min2 = INF;
        int r2Min1 = INF , r2Min2 = INF;

        for (int num : nums) {
            sum += num;
            int r = num % 3;

            if (r == 1) {
                if (num < r1Min1) {
                    r1Min2 = r1Min1;
                    r1Min1 = num;
                }
                else if (num < r1Min2) r1Min2 = num;
                
            }
            else if (r == 2) {
                if (num < r2Min1) {
                    r2Min2 = r2Min1;
                    r2Min1 = num;
                }
                else if (num < r2Min2) r2Min2 = num;
            }
        }

        int rem = (int)(sum % 3);
        if (rem == 0) return (int)sum;

        long remove = (long)1e18;
        if (rem == 1) {
            if (r1Min1 != INF) remove = Math.min(remove , (long)r1Min1);
            if (r2Min2 != INF) remove = Math.min(remove , (long)r2Min1 + r2Min2);
        }
        else { 
            if (r2Min1 != INF) remove = Math.min(remove , (long)r2Min1);
            if (r1Min2 != INF) remove = Math.min(remove , (long)r1Min1 + r1Min2);
        }

        if (remove >= 1e18) return 0;
        return (int)(sum - remove);
    }
}
