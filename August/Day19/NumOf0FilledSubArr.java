// LEETCODE 2348. Number of Zero-Filled Subarrays

// Given an integer array nums, return the number of subarrays filled with 0.

// A subarray is a contiguous non-empty sequence of elements within an array.


// Example 1:

// Input: nums = [1,3,0,0,2,0,0,4]
// Output: 6
// Explanation: 
// There are 4 occurrences of [0] as a subarray.
// There are 2 occurrences of [0,0] as a subarray.
// There is no occurrence of a subarray with a size more than 2 filled with 0. Therefore, we return 6.
// Example 2:

// Input: nums = [0,0,0,2,0,0]
// Output: 9
// Explanation:
// There are 5 occurrences of [0] as a subarray.
// There are 3 occurrences of [0,0] as a subarray.
// There is 1 occurrence of [0,0,0] as a subarray.
// There is no occurrence of a subarray with a size more than 3 filled with 0. Therefore, we return 9.
// Example 3:

// Input: nums = [2,10,2019]
// Output: 0
// Explanation: There is no subarray filled with 0. Therefore, we return 0.
 

// Constraints:

// 1 <= nums.length <= 105
// -109 <= nums[i] <= 109


// 🚀 Approach
// Initialize two variables:
//     len to track the current length of consecutive zeros.
//     res to accumulate the total number of zero-filled subarrays
// Traverse the array:
//     If the current element is 0, increment len and add it to res.
//     If it's non-zero, reset len to 0.
// Return res as the final count.
// This works because for every zero at position i, it contributes to len subarrays ending at i, which includes all subarrays formed by the previous zeros plus the new one.


class Solution {
    public long zeroFilledSubarray(int[] nums) {
        long res = 0 , len = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 0) {
                len++;
                res += len;
            }
            else len = 0;
        }
        return res;
    }
}