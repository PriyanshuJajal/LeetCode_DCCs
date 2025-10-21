// LEETCODE 3346. Maximum Frequency of an Element After Performing Operations I

// You are given an integer array nums and two integers k and numOperations.

// You must perform an operation numOperations times on nums, where in each operation you:

// Select an index i that was not selected in any previous operations.
// Add an integer in the range [-k, k] to nums[i].
// Return the maximum possible frequency of any element in nums after performing the operations.

 

// Example 1:

// Input: nums = [1,4,5], k = 1, numOperations = 2

// Output: 2

// Explanation:

// We can achieve a maximum frequency of two by:

// Adding 0 to nums[1]. nums becomes [1, 4, 5].
// Adding -1 to nums[2]. nums becomes [1, 4, 4].
// Example 2:

// Input: nums = [5,11,20,20], k = 5, numOperations = 1

// Output: 2

// Explanation:

// We can achieve a maximum frequency of two by:

// Adding 0 to nums[1].
 

// Constraints:

// 1 <= nums.length <= 105
// 1 <= nums[i] <= 105
// 0 <= k <= 105
// 0 <= numOperations <= nums.length





// 🚀 Approach
// Find bounds: Compute the minimum and maximum values in the array to define the range of interest.
// Frequency array: Build a frequency array freq where freq[i] is the count of numbers ≤ i.
// Prefix sum: Convert freq into a prefix sum array to allow fast range queries.
// Sliding window over values: For each value i in [mini, maxi]:
//     Define a range [l, r] = [i - k, i + k] clamped within [mini, maxi].
//     Compute the frequency of i itself: f = freq[i] - freq[i - 1].
//     Compute how many other numbers lie in** [l, r]** excluding i:
//     freq[r] - freq[l - 1] - f.
//     Take the minimum of that and numOperations as extraFreq.
//     Update result as res = max(res, f + extraFreq).











class Solution {
    public int maxFrequency(int[] nums, int k, int numOperations) {
        int mini = Integer.MAX_VALUE;
        int maxi = Integer.MIN_VALUE;
        int res = 0;

        for (int num : nums) {
            maxi = Math.max(maxi , num);
            mini = Math.min(mini , num);
        }

        int[] freq = new int[maxi + 1];
        for (int num : nums) freq[num]++;
        
        for (int i = 1; i <= maxi; i++) {
            freq[i] += freq[i - 1];
        }

        for (int i = mini; i <= maxi; i++) {
            int l = Math.max(mini , i - k);
            int r = Math.min(maxi , i + k);

            int f = freq[i] - freq[i - 1];
            int extraFreq = Math.min(numOperations , freq[r] - freq[l - 1] - f);
            res = Math.max(res, f + extraFreq);
        }

        return res;

    }
}
