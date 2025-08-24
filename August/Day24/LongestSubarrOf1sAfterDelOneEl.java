// LEETCODE 1493. Longest Subarray of 1's After Deleting One Element

// Given a binary array nums, you should delete one element from it.

// Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.

 
// Example 1:

// Input: nums = [1,1,0,1]
// Output: 3
// Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.
// Example 2:

// Input: nums = [0,1,1,1,0,1,1,0,1]
// Output: 5
// Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].
// Example 3:

// Input: nums = [1,1,1]
// Output: 2
// Explanation: You must delete one element.
 

// Constraints:

// 1 <= nums.length <= 105
// nums[i] is either 0 or 1.


// 🚀 Approach
// Use a sliding window with two pointers i and j. Track the index of the last seen 0 using last0Idx.
//     If we encounter a 0, we shift the start of the window i to last0Idx + 1 and update last0Idx to the current index.
//     At each step, calculate the window size j - i and update the result res.
// This ensures the window always contains at most one zero, effectively simulating the deletion of one element.



class Solution {
    public int longestSubarray(int[] nums) {
        int i = 0 , j = 0;
        int last0Idx = -1 , res = 0;

        while(j < nums.length) {
            if (nums[j] == 0) {
                i = last0Idx + 1;
                last0Idx = j;
            }
            res = Math.max(res , j - i);
            j++;
        }
        return res;
    }
}