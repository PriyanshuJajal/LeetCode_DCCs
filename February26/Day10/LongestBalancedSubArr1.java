// LEETCODE 3719. Longest Balanced Subarray I

// You are given an integer array nums.

// A subarray is called balanced if the number of distinct even numbers in the subarray is equal to the number of distinct odd numbers.

// Return the length of the longest balanced subarray.

 

// Example 1:

// Input: nums = [2,5,4,3]

// Output: 4

// Explanation:

// The longest balanced subarray is [2, 5, 4, 3].
// It has 2 distinct even numbers [2, 4] and 2 distinct odd numbers [5, 3]. Thus, the answer is 4.
// Example 2:

// Input: nums = [3,2,2,5,4]

// Output: 5

// Explanation:

// The longest balanced subarray is [3, 2, 2, 5, 4].
// It has 2 distinct even numbers [2, 4] and 2 distinct odd numbers [3, 5]. Thus, the answer is 5.
// Example 3:

// Input: nums = [1,2,3,2]

// Output: 3

// Explanation:

// The longest balanced subarray is [2, 3, 2].
// It has 1 distinct even number [2] and 1 distinct odd number [3]. Thus, the answer is 3.
 

// Constraints:

// 1 <= nums.length <= 1500
// 1 <= nums[i] <= 105
 

// 🚀 Approach
// Use two nested loops to explore all subarrays:
//     Outer loop i marks the start of the subarray.
//     Inner loop j marks the end of the subarray.
// For each subarray:
//     Use two Sets to track distinct even and odd numbers.
//     If nums[j] is even, add to even set; else add to odd set.
//     If the sizes of both sets match, update maxLen with the current subarray length.

// This brute-force approach ensures all possible subarrays are checked.

// 🕛 Complexity
// Time complexity: O(n²)
// Space complexity: O(n)






class Solution {
    public int longestBalanced(int[] nums) {
        int n = nums.length;
        Set<Integer> even = new HashSet<>();
        Set<Integer> odd = new HashSet<>();
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            even.clear();
            odd.clear();

            for (int j = i; j < n; j++) {
                if ((nums[j] & 1) == 0) even.add(nums[j]);
                else odd.add(nums[j]);

                if (even.size() == odd.size()) maxLen = Math.max(maxLen , j - i + 1);
            }
        }
        return maxLen;
    }
}


