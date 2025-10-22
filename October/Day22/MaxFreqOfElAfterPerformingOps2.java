// LEETCODE 3347. Maximum Frequency of an Element After Performing Operations II

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

// Adding 0 to nums[1], after which nums becomes [1, 4, 5].
// Adding -1 to nums[2], after which nums becomes [1, 4, 4].
// Example 2:

// Input: nums = [5,11,20,20], k = 5, numOperations = 1

// Output: 2

// Explanation:

// We can achieve a maximum frequency of two by:

// Adding 0 to nums[1].
 

// Constraints:

// 1 <= nums.length <= 105
// 1 <= nums[i] <= 109
// 0 <= k <= 109
// 0 <= numOperations <= nums.length




// 🚀 Approach
// Frequency Mapping:
// Count the frequency of each number in nums using a hash map freq.
// Range Contribution via Difference Array:
// For each number x, it can contribute to any target in the range [x - k, x + k].
// We use a difference array technique (diff map) to mark the start and end of this contribution range efficiently.
// Prefix Sum Sweep:
// Iterate through the sorted keys of diff to compute the cumulative sum of contributions at each point.
// For each target value:
//     Let cumuSum be the total number of elements that can be converted to this target.
//     Subtract the number of elements already equal to the target (freq[target]) to get how many need to be changed.
//     Use at most numOperations of those changes to boost the frequency of the target.
// Track Maximum Frequency:
// For each target, compute the possible frequency and update the result.









class Solution {
    public int maxFrequency(int[] nums, int k, int numOperations) {
        int maxVal = Arrays.stream(nums).max().getAsInt() + k;
        TreeMap<Integer, Integer> diff = new TreeMap<>();
        Map<Integer, Integer> freq = new HashMap<>();

        for (int num : nums) {
            freq.put(num , freq.getOrDefault(num , 0) + 1);

            int l = Math.max(num - k , 0);
            int r = Math.min(num + k , maxVal);

            diff.put(l , diff.getOrDefault(l , 0) + 1);
            diff.put(r + 1 , diff.getOrDefault(r + 1 , 0) - 1);

            diff.putIfAbsent(num , diff.getOrDefault(num , 0));
        }

        int res = 1;
        int cumuSum = 0;

        for (Map.Entry<Integer, Integer> entry : diff.entrySet()) {
            int target = entry.getKey();
            int delta = entry.getValue();
            cumuSum += delta;

            int targetFreq = freq.getOrDefault(target , 0);
            int toConvert = cumuSum - targetFreq;
            int maxPossFreq = Math.min(toConvert , numOperations);
            res = Math.max(res , targetFreq + maxPossFreq);
        }
        return res;
    }
}
